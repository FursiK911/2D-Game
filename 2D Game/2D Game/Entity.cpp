#include "Entity.h"

Entity::Entity()
{
}

Entity::Entity(Image & im, float X, float Y, int W, int H, String * Name)
{
	image = &im;
	texture = new Texture();
	sprite = new Sprite();
	x = X; y = Y; width = W; height = H; name = Name; moveTimer = 0;
	speed = 0; health = 100; dx = 0; dy = 0;
	life = true; onGround = false; isMove = false;
	texture->loadFromImage(*image);
	sprite->setTexture(*texture);
	sprite->setOrigin(width / 2, height / 2);
}

Entity::~Entity()
{
}


void Entity::checkCollisionWithMap(float Dx, float Dy, String* TileMap)//ф ция проверки столкновений с картой
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
				}
				if (Dy<0) { y = i * 32 + 32;  dy = 0; }
				if (Dx>0) { x = j * 32 - width; }
				if (Dx<0) { x = j * 32 + 32; }
			}
		}
}

Image Entity::getImage()
{
	return *image;
}

Texture Entity::getTexture()
{
	return *texture;
}

Sprite Entity::getSprite()
{
	return *sprite;
}

void Entity::setImage(Image& i)
{
	image = &i;
}

void Entity::setTexture(Texture& t)
{
	texture = &t;
}

void Entity::setSprite(Sprite& s)
{
	sprite = &s;
}

float Entity::getCoordinateX()
{
	return x;
}

void Entity::setCoordinateX(float px)
{
	x = px;
}

float Entity::getDX()
{
	return dx;
}

void Entity::setDX(float pdx)
{
	dx = pdx;
}

float Entity::getCoordinateY()
{
	return y;
}

void Entity::setCoordinateY(float py)
{
	y = py;
}

float Entity::getDY()
{
	return dy;
}

void Entity::setDY(float pdy)
{
	dy = pdy;
}

float Entity::getCurrentFrame()
{
	return currentFrame;
}

void Entity::setCurrentFrame(float c)
{
	currentFrame = c;
}

float Entity::getSpeed()
{
	return speed;
}

void Entity::setSpeed(float s)
{
	speed = s;
}

bool Entity::getOnGround()
{
	return onGround;
}

void Entity::setOnGround(bool onground)
{
	onGround = onground;
}