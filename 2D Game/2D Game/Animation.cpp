#include "Animation.h"

Animation::Animation(Sprite * s)
{
	sprite = s;
	currentFrame = 0;
	oldCurrentFrame = 0;
}

Animation::~Animation()
{
}

void Animation::moveLeft(float t, int x, int y, int width, int height)
{
	currentFrame += 0.001 * t; // скорость анимации
	if (currentFrame > 3) currentFrame -= 3;
	sprite->setScale(-1, 1); //отразим по горизонтали
	sprite->setTextureRect(IntRect(x * int(currentFrame), y, width, height));
}

void Animation::moveRight(float t, int x, int y, int width, int height)
{
	currentFrame -= 0.001 * t; // скорость анимации
	if (currentFrame < 0) currentFrame += 3;
	sprite->setScale(1, 1); //отразим по горизонтали
	sprite->setTextureRect(IntRect(x * int(currentFrame), y, width, height));
}

void Animation::jump(float t, int x, int y, int width, int height, Status& directionMove)
{
	if (directionMove == Status::left)
	{
		sprite->setScale(-1, 1); //отразим по горизонтали
		sprite->setTextureRect(IntRect(x, y, width, height));
	}
	else if (directionMove == Status::right)
	{
		sprite->setScale(1, 1); //отразим по горизонтали
		sprite->setTextureRect(IntRect(x, y, width, height));
	}
}

bool Animation::combo(float t, int x, int y, int width, int height, Status& oldState)
{
	if (oldState != Status::combo)
	{
		currentFrame = 0;
		oldCurrentFrame = 0;
	}

	if (oldState == Status::combo)
	{
		currentFrame += 0.0015* t;
		oldCurrentFrame = currentFrame;
	}
	if (currentFrame > 4)
	{
		currentFrame -= 4;
	}
	sprite->setTextureRect(IntRect(x * int(currentFrame), y, width, height));
	if ((int)currentFrame % 2 == 0)
		return true;
	return false;
}

void Animation::attacked(float t, int x, int y, int width, int height)
{
}
