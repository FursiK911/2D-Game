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
	weight = w;
	height = h;
	currentFrame = 0;
	speed = 0.1;
	attack = false;
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
}

void Player::update(float t, String* map)
{
	control();//функция управления персонажем
	switch (state)//тут делаются различные действия в зависимости от состояния
	{
	case right: dx = speed; break;//состояние идти вправо
	case left: dx = -speed; break;//состояние идти влево
	case up: break;//будет состояние поднятия наверх (например по лестнице)
	case down: dx = 0; break;//будет состояние во время спуска персонажа (например по лестнице)
	case jump: break;//здесь может быть вызов анимации
	case stay: break;//и здесь тоже		
	}
	x += dx*t;
	checkCollisionWithMap(dx, 0, map);//обрабатываем столкновение по Х
	y += dy*t;
	checkCollisionWithMap(0, dy, map);//обрабатываем столкновение по Y
	sprite->setPosition(x + weight / 2, y + height / 2); //задаем позицию спрайта в место его центра
	dy = dy + 0.0015*t; //делаем притяжение к земле
	speed = 0;
}

void Player::control() {
	if (Keyboard::isKeyPressed(Keyboard::Left)) 
	{
		state = left;
		speed = 0.1;
		//currentFrame += 0.005*time;
		//if (currentFrame > 3) currentFrame -= 3;
		//p.sprite.setTextureRect(IntRect(96 * int(currentFrame), 135, 96, 54));
	}
	if (Keyboard::isKeyPressed(Keyboard::Right)) 
	{
		state = right;
		speed = 0.1;
		//	currentFrame += 0.005*time;
		//	if (currentFrame > 3) currentFrame -= 3;
		//	p.sprite.setTextureRect(IntRect(96 * int(currentFrame), 232, 96, 54));
	}

	if ((Keyboard::isKeyPressed(Keyboard::Up)) && (onGround))
	{
		state = jump; dy = -0.5; onGround = false;//то состояние равно прыжок,прыгнули и сообщили, что мы не на земле
												  //currentFrame += 0.005*time;
												  //if (currentFrame > 3) currentFrame -= 3;
												  //p.sprite.setTextureRect(IntRect(96 * int(currentFrame), 307, 96, 96));
	}

	if (Keyboard::isKeyPressed(Keyboard::Down)) 
	{
		state = down;
		speed = 0.1;

		//currentFrame += 0.005*time;
		//if (currentFrame > 3) currentFrame -= 3;
		//p.sprite.setTextureRect(IntRect(96 * int(currentFrame), 0, 96, 96));
	}
}

void Player::checkCollisionWithMap(float Dx, float Dy, String* TileMap)//ф ция проверки столкновений с картой
{
	for (int i = y / 32; i < (y + height) / 32; i++)//проходимся по элементам карты
		for (int j = x / 32; j<(x + weight) / 32; j++)
		{
			if (TileMap[i][j] == '0')//если элемент наш тайлик земли? то
			{
				if (Dy>0) { y = i * 32 - height;  dy = 0; onGround = true; }//по Y вниз=>идем в пол(стоим на месте) или падаем. В этот момент надо вытолкнуть персонажа и поставить его на землю, при этом говорим что мы на земле тем самым снова можем прыгать
				if (Dy<0) { y = i * 32 + 32;  dy = 0; }//столкновение с верхними краями карты(может и не пригодиться)
				if (Dx>0) { x = j * 32 - weight; }//с правым краем карты
				if (Dx<0) { x = j * 32 + 32; }// с левым краем карты
			}
			else { onGround = false; }
		}
}

Image Player::getImage()
{
	return *image;
}

Texture Player::getTexture()
{
	return *texture;
}

Sprite Player::getSprite()
{
	return *sprite;
}

void Player::setImage(Image& i)
{
	image = &i;
}

void Player::setTexture(Texture& t)
{
	texture = &t;
}

void Player::setSprite(Sprite& s)
{
	sprite = &s;
}

float Player::getCoordinateX()
{
	return x;
}

void Player::setCoordinateX(float px)
{
	x = px;
}

float Player::getDX()
{
	return dx;
}

void Player::setDX(float pdx)
{
	dx = pdx;
}

float Player::getCoordinateY()
{
	return y;
}

void Player::setCoordinateY(float py)
{
	y = py;
}

float Player::getDY()
{
	return dy;
}

void Player::setDY(float pdy)
{
	dy = pdy;
}

float Player::getCurrentFrame()
{
	return currentFrame;
}

void Player::setCurrentFrame(float c)
{
	currentFrame = c;
}

float Player::getSpeed()
{
	return speed;
}

void Player::setSpeed(float s)
{
	speed = s;
}

bool Player::getOnGround()
{
	return onGround;
}

void Player::setOnGround(bool onground)
{
	onGround = onground;
}