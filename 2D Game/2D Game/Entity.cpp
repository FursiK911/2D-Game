#include "Entity.h"
#include "SFML\Graphics.hpp"


Entity::Entity()
{
}


Entity::~Entity()
{
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

Image& Entity::getImage()
{
	return *image;
}

Texture& Entity::getTexture()
{
	return *texture;
}

Sprite& Entity::getSprite()
{
	return *sprite;
}

void Entity::setImage(Image i)
{
	*image = i;
}

void Entity::setTexture(Texture t)
{
	*texture = t;
}

void Entity::setSprite(Sprite s)
{
	*sprite = s;
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

void Entity::checkCollisionWithMap(float Dx, float Dy, String* map)//ф ция проверки столкновений с картой
{
	for (int i = y / 32; i < (y + height) / 32; i++)//проходимся по элементам карты
		for (int j = x / 32; j < (x + weight) / 32; j++)
		{
			if (map[i][j] == '0')//если элемент наш тайлик земли? то
			{
				if (Dy > 0) { y = i * 32 - height;  dy = 0; onGround = true; }//по Y вниз=>идем в пол(стоим на месте) или падаем. В этот момент надо вытолкнуть персонажа и поставить его на землю, при этом говорим что мы на земле тем самым снова можем прыгать
				if (Dy < 0) { y = i * 32 + 32;  dy = 0; }//столкновение с верхними краями карты(может и не пригодиться)
				if (Dx > 0) { x = j * 32 - weight; }//с правым краем карты
				if (Dx < 0) { x = j * 32 + 32; }// с левым краем карты
			}
			else { onGround = false; }
		}
}