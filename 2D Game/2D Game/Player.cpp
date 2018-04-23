#include "Player.h"

Player::Player(String f, float PositionX, float PositionY, float w, float h)
{
	image = new Image();
	texture = new Texture();
	sprite = new Sprite();

	hitBuffer = new SoundBuffer();
	attack1Buffer = new SoundBuffer();
	attack2Buffer = new SoundBuffer();
	jumpBuffer = new SoundBuffer();
	walkBuffer = new SoundBuffer();

	hitBuffer->loadFromFile("sounds/Hit1.wav");
	attack1Buffer->loadFromFile("sounds/Attack1.wav");
	attack2Buffer->loadFromFile("sounds/Attack2.wav");
	jumpBuffer->loadFromFile("sounds/jump.wav");
	walkBuffer->loadFromFile("sounds/walk.wav");

	hit = new Sound(*hitBuffer);
	attack1 = new Sound(*attack1Buffer);
	attack2 = new Sound(*attack2Buffer);
	jump = new Sound(*jumpBuffer);
	walk = new Sound(*walkBuffer);

	hit->setVolume(10);
	attack1->setVolume(50);
	attack2->setVolume(50);
	jump->setVolume(50);
	walk->setVolume(10);

	file = &f;
	x = PositionX;
	y = PositionY;
	dx = 0;
	dy = 0;
	state = Status::stay;
	width = w;
	height = h;
	currentFrame = 0;
	speed = 0.1;
	life = true;
	health = 100;
	directionMove = Status::right;
	onGround = false;
	image->loadFromFile("images/" + *file);
	texture->loadFromImage(*image);
	sprite->setTexture(*texture);
	sprite->setTextureRect(IntRect(0, 0, w, h)); //IntRect - приведение типов
	sprite->setPosition(PositionX, PositionY);
	sprite->setOrigin(w / 2, h / 2);
}

Player::~Player()
{
	delete settings, hitBuffer, attack1Buffer, attack2Buffer, jumpBuffer, walkBuffer, hit, attack1, attack2, jump, walk;
}

void Player::update(float t, String* map)
{
	if(state != Status::attacked)
		control(t);
		switch (state)
		{
		case Status::right:
			dx = speed;
			break;
		case Status::left:
			dx = -speed;
			break;
		case Status::up:
			break;
		case Status::down:
			dx = 0;
			break;
		case Status::jump:
			jump->play();
			break;
		case Status::attacked:
			hit->play();
			attackedAnimation(t);
			break;
		case Status::stay:
			dx = 0;
			speed = 0;
			break;
	}

	x += dx*t;
	checkCollisionWithMap(dx, 0, map);//обрабатываем столкновение по Х
	y += dy*t;
	checkCollisionWithMap(0, dy, map);//обрабатываем столкновение по Y
	sprite->setPosition(x + width / 2, y + height / 2); //задаем позицию спрайта в место его центра
	dy = dy + 0.00015*t; //Добавляем гравитацию
}

void Player::control(float& t) 
{
	state = Status::stay;
	if (Keyboard::isKeyPressed(Keyboard::Left)) 
	{
		state = Status::left;
		directionMove = Status::left;
		speed = 0.1;
		dx = speed;
		combo = false;
		if (onGround)
		{
			currentFrame += 0.001 * t; // скорость анимации
			if (currentFrame > 3) currentFrame -= 3;
			sprite->setScale(-1, 1); //отразим по горизонтали
			sprite->setTextureRect(IntRect(50 * int(currentFrame), 0, 50, 75));
		}
}
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		state = Status::right;
		directionMove = Status::right;
		speed = 0.1;
		dx = -speed;
		combo = false;
		if (onGround)
		{
			currentFrame -= 0.001 * t; // скорость анимации
			if (currentFrame < 0) currentFrame += 3;
			sprite->setScale(1, 1); //отразим по горизонтали
			sprite->setTextureRect(IntRect(50 * int(currentFrame), 0, 50, 75));
		}
	}

	if ((Keyboard::isKeyPressed(Keyboard::Up)) && (onGround))
	{
		combo = false;
		if (directionMove == Status::left)
		{
			sprite->setScale(-1, 1); //отразим по горизонтали
			sprite->setTextureRect(IntRect(55, 235, 55, 85));
		}
		else if (directionMove == Status::right)
		{
			sprite->setScale(1, 1); //отразим по горизонтали
			sprite->setTextureRect(IntRect(55, 225, 55, 85));
		}
		state = Status::jump;
		dy = -0.2; 
		onGround = false;
	}

	if (Keyboard::isKeyPressed(Keyboard::Down)) 
	{
		state = Status::down;
		speed = 0.1;
	}

	if (Keyboard::isKeyPressed(Keyboard::Space) && onGround) // если клавиша зажата, то проводится комбинация
	{
		if (!combo)
		{
			currentFrame = 0;
			oldCurrentFrame = 0;
		}

		combo = true;
		if (combo)
		{
			currentFrame += 0.0015*t;
			oldCurrentFrame = currentFrame;
		}
		if (currentFrame > 4)
		{
			currentFrame -= 4;
		}
		sprite->setTextureRect(IntRect(60 * int(currentFrame), 80, 60, 75));
	}
	else if (currentFrame == oldCurrentFrame) // в ином случае комбинация прерывается
	{
		combo = false;
		if (directionMove == Status::right)
		{
			currentFrame = 2; // скорость анимации
			sprite->setScale(1, 1); //отразим по горизонтали
			sprite->setTextureRect(IntRect(50 * int(currentFrame), 0, 50, 75));
		}
		else
		{
			currentFrame = 2;
			sprite->setScale(-1, 1); //отразим по горизонтали
			sprite->setTextureRect(IntRect(50 * int(currentFrame), 0, 50, 75));
		}
	}
}

void Player::attackedAnimation(float& t)
{
	if (kickUp)
	{
		dy = -0.1; kickUp = false;
	}
	if (kickR)
	{
		dx = 0.15;
		if (currentFrame < 4)
			currentFrame += 0.001 * t; // скорость анимации
		sprite->setScale(-1, 1); //отразим по горизонтали
		sprite->setTextureRect(IntRect(80 * int(currentFrame), 160, 80, 75));
	}
	else if (kickL)
	{
		dx = -0.15;
		if (currentFrame < 4)
			currentFrame += 0.001 * t; // скорость анимации
		sprite->setScale(1, 1); //отразим по горизонтали
		sprite->setTextureRect(IntRect(80 * int(currentFrame), 160, 80, 75));
	}
	if (onGround && state == Status::attacked)
	{
		if (kickR)
		{
			currentFrame = 0;
			sprite->setScale(-1, 1); //отразим по горизонтали
			sprite->setTextureRect(IntRect(50 * int(currentFrame), 0, 50, 75));
			state = Status::left;
		}
		else if (kickL)
		{
			currentFrame = 0;
			sprite->setScale(1, 1); //отразим по горизонтали
			sprite->setTextureRect(IntRect(50 * int(currentFrame), 0, 50, 75));
			state = Status::right;
		}

		kickR = false; kickL = false;
	}
}

void Player::checkCollisionWithMap(float Dx, float Dy, String* TileMap)//ф ция проверки столкновений с картой
{
	for (int i = y / 32; i < (y + height) / 32; i++)
		for (int j = x / 32; j < (x + width) / 32; j++)
		{
			if (TileMap[i][j] == '0')
			{
				if (Dy > 0)//по Y вниз=>идем в пол(стоим на месте) или падаем. В этот момент надо вытолкнуть персонажа и поставить его на землю, при этом говорим что мы на земле тем самым снова можем прыгать
				{
					y = i * 32 - height;
					dy = 0;
					onGround = true;
					if (directionMove == Status::left && !combo)
					{
						sprite->setScale(-1, 1);
						sprite->setTextureRect(IntRect(50 * int(currentFrame), 0, 50, 75));
					}
					else if (directionMove == Status::right && !combo)
					{
						sprite->setScale(1, 1);
						sprite->setTextureRect(IntRect(50 * int(currentFrame), 0, 50, 75));
					}
				}
				if (Dy < 0)
				{
					y = i * 32 + 32;  dy = 0;
				}
				if (Dx > 0)
				{
					x = j * 32 - width;
				}
				if (Dx < 0)
				{
					x = j * 32 + 32;
				}
			}
		}
}

void Player::InteractionWithEntity(std::list<Entity*> &entities, std::list<Entity*>::iterator it)
{
	if (settings->getInstance()->getStun()) // Отрисовка поверженных врагов
	{
		for (it = entities.begin(); it != entities.end();)
		{
			Entity *b = *it;
			if (b->getLife() == false && (int)b->getCurrentFrame() == 0)
			{
				it = entities.erase(it);
				delete b;
			}
			else it++;
		}
	}

	for (it = entities.begin(); it != entities.end(); it++)//Атака игрока по врагам
	{
		if ((*it)->getRect().intersects(getRect()))//если прямоугольник спрайта объекта пересекается с игроком
		{
			if (combo == true && (int)currentFrame % 2 != 0 && (*it)->getLife())
			{
				attack1->play();
				if(directionMove == Status::left)
					(*it)->setCoordinateX((*it)->getCoordinateX() - 10);
				else
					(*it)->setCoordinateX((*it)->getCoordinateX() + 10);
				(*it)->setDX(0);
				(*it)->setHealth(0);
			}

			else if (state != Status::attacked)//Атака врагов по игроку
			{
				if ((*it)->getDX() > 0)
				{
					currentFrame = 0;
					kickR = true; kickUp = true; state = Status::attacked;
					onGround = false;
					health -= 5;
				}
				if ((*it)->getDX() < 0)
				{
					hit->play();
					currentFrame = 0;
					kickL = true; kickUp = true; state = Status::attacked;
					onGround = false;
					health -= 5;
				}
			}
		}
	}
}
