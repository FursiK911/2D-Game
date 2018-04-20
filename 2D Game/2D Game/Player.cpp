#include "Player.h"

Player::Player(String f, float PositionX, float PositionY, float w, float h)
{
	image = new Image();
	texture = new Texture();
	sprite = new Sprite();
	file = &f;
	x = PositionX;
	y = PositionY;
	dx = 0;
	dy = 0;
	state = stay;
	width = w;
	height = h;
	currentFrame = 0;
	speed = 0.1;
	life = true;
	health = 100;
	attack = false;
	onGround = false;
	directionMove = 0;
	image->loadFromFile("images/" + *file);
	texture->loadFromImage(*image);
	sprite->setTexture(*texture);
	sprite->setTextureRect(IntRect(0, 0, w, h)); //IntRect - приведение типов
	sprite->setPosition(PositionX, PositionY);
	sprite->setOrigin(w / 2, h / 2);
}

Player::~Player()
{
}

void Player::update(float t, String* map)
{
	control(t);
	switch (state)
	{
	case right:
		dx = speed;
		break;
	case left:
		dx = -speed;
		break;
	case up:
		break;
	case down:
		dx = 0;
		break;
	case jump:
		break;
	case stay:
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
	state = stay;
}

void Player::control(float& t) 
{
	state = stay;
	if (Keyboard::isKeyPressed(Keyboard::Left)) 
	{
		state = left;
		directionMove = left;
		speed = 0.1;
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
		state = right;
		directionMove = right;
		speed = 0.1;
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
		if (state == left)
		{
			sprite->setScale(-1, 1); //отразим по горизонтали
			sprite->setTextureRect(IntRect(55, 225, 55, 85));
		}
		else if (state == right)
		{
			sprite->setScale(1, 1); //отразим по горизонтали
			sprite->setTextureRect(IntRect(55, 225, 55, 85));
		}
		state = jump; 
		dy = -0.2; 
		onGround = false;
	}

	if (Keyboard::isKeyPressed(Keyboard::Down)) 
	{
		state = down;
		speed = 0.1;
	}

	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		if (!combo)
			currentFrame = 0;
		combo = true;
		if (combo)
		{
			currentFrame += 0.0015*t;
		}
		if (currentFrame > 4)
		{
			currentFrame -= 4;
		}
		sprite->setTextureRect(IntRect(60 * int(currentFrame), 80, 60, 75));
	}
}

void Player::checkCollisionWithMap(float Dx, float Dy, String* TileMap)//ф ция проверки столкновений с картой
{
	for (int i = y / 32; i < (y + height) / 32; i++)
		for (int j = x / 32; j<(x + width) / 32; j++)
		{
			if (TileMap[i][j] == '0')
			{
				if (Dy > 0)//по Y вниз=>идем в пол(стоим на месте) или падаем. В этот момент надо вытолкнуть персонажа и поставить его на землю, при этом говорим что мы на земле тем самым снова можем прыгать
				{
					y = i * 32 - height;
					dy = 0;
					onGround = true;
					if (directionMove == left && !combo)
					{
						sprite->setScale(-1, 1);
						sprite->setTextureRect(IntRect(50 * int(currentFrame), 0, 50, 75));
					}
					else if(directionMove == right && !combo)
					{
						sprite->setScale(1, 1);
						sprite->setTextureRect(IntRect(50 * int(currentFrame), 0, 50, 75));
					}
				}
				if (Dy<0) { y = i * 32 + 32;  dy = 0; }
				if (Dx>0) { x = j * 32 - width; }
				if (Dx<0) { x = j * 32 + 32; }
			}
		}
}

void Player::InteractionWithEntity(std::list<Entity*> &entities, std::list<Entity*>::iterator it)
{

	for (it = entities.begin(); it != entities.end();)
	{
		Entity *b = *it;
		if (b->getLife() == false)
		{
			it = entities.erase(it);
			delete b;
		}
		else it++;
	}

	for (it = entities.begin(); it != entities.end(); it++)
	{
		if ((*it)->getRect().intersects(getRect()))//если прямоугольник спрайта объекта пересекается с игроком
		{
			if ((combo == true && (int)currentFrame % 2 != 0))
			{
				(*it)->setCoordinateX((*it)->getCoordinateX() - 4);
				(*it)->setDY((*it)->getDY() - 0.12);
				(*it)->setHealth(0);
			}
			else
			{
				//иначе враг что-то сделал
			}
		}
	}
}

bool Player::getCombo()
{
	return combo;
}
