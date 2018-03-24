#include "Player.h"

Player::Player(String f, float PositionX, float PositionY, float w, float h)
{
	heroImage = new Image();
	heroTexture = new Texture();
	heroSprite = new Sprite();
	file = &f;
	x = PositionX;
	y = PositionY; 
	weight = w;
	height = h;
	currentFrame = 0;
	speed = 0.1;
	attack = false;
	heroImage->loadFromFile("images/" + *file);
	heroTexture->loadFromImage(*heroImage);
	heroSprite->setTexture(*heroTexture);
	heroSprite->setTextureRect(IntRect(0, 0, w, h)); //IntRect - приведение типов
	heroSprite->setPosition(PositionX, PositionY);
}

Player::~Player()
{
}

void Player::update(float t)
{
	if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) 
	{ 
		combo = false;
		currentFrame += 0.001*t; // скорость анимации
		if (currentFrame > 3) currentFrame -= 3;
		heroSprite->setScale(-1, 1); //отразим по горизонтали
		heroSprite->setTextureRect(IntRect(50 * int(currentFrame), 0, 50, 75));
		dx = -speed; dy = 0;
		x += dx * t;
		heroSprite->move(x, 0);
	}

	if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D))))
	{
		combo = false;
		currentFrame -= 0.001*t; 
		if (currentFrame < 0) currentFrame += 3;
		heroSprite->setScale(1, 1);
		heroSprite->setTextureRect(IntRect(50 * int(currentFrame), 0, 50, 75));
		dx = speed; dy = 0;
		x += dx * t;
		//heroSprite->move(x, 0);
		
	}

	if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) 
	{
		dx = 0; dy = -speed;
		y += dy * t;
		//heroSprite->move(0, y);
	}

	if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) 
	{
		dx = 0; dy = speed;
		y += dy * t;
		//heroSprite->move(0, y);
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
		heroSprite->setTextureRect(IntRect(60 * int(currentFrame), 80, 60, 75));
	}
	heroSprite->setPosition(x, y);
}

void Player::interactionWithMap(String* map)
{

	for (int i = y / 32; i < (y + height) / 32; i++)
		for (int j = x / 32; j<(x + weight) / 32; j++)
		{
			if (map[i][j] == '0')//если наш квадратик соответствует символу 0 (стена), то проверяем "направление скорости" персонажа:
			{
				if (dy>0)//если мы шли вниз,
				{
					y = i * 32 - height;//то стопорим координату игрек персонажа. сначала получаем координату нашего квадратика на карте(стены) и затем вычитаем из высоты спрайта персонажа.
				}
				if (dy<0)
				{
					y = i * 32 + 32;//аналогично с ходьбой вверх. dy<0, значит мы идем вверх (вспоминаем координаты паинта)
				}
				if (dx>0)
				{
					x = j * 32 - weight;//если идем вправо, то координата Х равна стена (символ 0) минус ширина персонажа
				}
				if (dx < 0)
				{
					x = j * 32 + 32;//аналогично идем влево
				}
			}
		}
}

float Player::getHeroCoordinateX()
{
	return x;
}

float Player::getHeroCoordinateY()
{
	return y;
}

Image& Player::getHeroImage()
{
	return *heroImage;
}

Texture& Player::getHeroTexture()
{
	return *heroTexture;
}

Sprite& Player::getHeroSprite()
{
	return *heroSprite;
}

void Player::setHeroImage(Image i)
{
	*heroImage = i;
}

void Player::setHeroTexture(Texture t)
{
	*heroTexture = t;
}

void Player::setHeroSprite(Sprite s)
{
	*heroSprite = s;
}
