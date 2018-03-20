#include "Player.h"

Player::Player(String f, float PositionX, float PositionY, float w, float h)
{
	file = f;
	x = PositionX;
	y = PositionY; 
	weight = w;
	height = h;
	currentFrame = 0;
	speed = 0.1;
	attack = false;
	heroImage.loadFromFile("images/" + file);
	heroTexture.loadFromImage(heroImage);
	heroSprite.setTexture(heroTexture);

	heroSprite.setTextureRect(IntRect(0, 0, w, h)); //IntRect - приведение типов
}

Player::~Player()
{
}

void Player::update(float t)
{
	if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) 
	{ 
		combo = false;
		currentFrame += 0.001*t;
		if (currentFrame > 3) currentFrame -= 3;
		heroSprite.setScale(-1, 1); //отразим по горизонтали
		heroSprite.setTextureRect(IntRect(50 * int(currentFrame), 0, 50, 75));
		heroSprite.move(-speed * t, 0);
	}

	if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D))))
	{
		combo = false;
		currentFrame -= 0.001*t; 
		if (currentFrame < 0) currentFrame += 3;
		heroSprite.setScale(1, 1);
		heroSprite.setTextureRect(IntRect(50 * int(currentFrame), 0, 50, 75));
		heroSprite.move(speed * t, 0);
	}

	if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
		heroSprite.move(0, -speed * t);
	}

	if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) 
	{
		heroSprite.move(0, speed * t);
	}

	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		if (!combo)
			currentFrame = 0;

		combo = true;
		if(combo)
			currentFrame += 0.001*t;

		if (currentFrame > 4)
		{
			currentFrame -= 4;
			combo = false;
		}
		heroSprite.setTextureRect(IntRect(60 * int(currentFrame), 80, 60, 75));
	}
}

Image Player::getHeroImage()
{
	return heroImage;
}

Texture Player::getHeroTexture()
{
	return heroTexture;
}

Sprite Player::getHeroSprite()
{
	return heroSprite;
}

void Player::setHeroImage(Image i)
{
	heroImage = i;
}

void Player::setHeroTexture(Texture t)
{
	heroTexture = t;
}

void Player::setHeroSprite(Sprite s)
{
	heroSprite = s;
}
