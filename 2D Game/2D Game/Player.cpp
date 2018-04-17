#include "Player.h"

Player::Player(String f, float PositionX, float PositionY, float w, float h)
{
	image = new Image();
	texture = new Texture();
	sprite = new Sprite();
	file = &f;
	x = PositionX;
	y = PositionY; 
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
}

Player::~Player()
{
}

// TODO:Переделать управление под паттерн "Команда"
void Player::ControlPlayer(float time)
{
	if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A))))
	{
		
	}

	if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D))))
	{
	}

	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		if (!combo)
			currentFrame = 0;

		combo = true;
		if (combo)
			currentFrame += 0.001*time;

		if (currentFrame > 4)
		{
			currentFrame -= 4;
			combo = false;
		}
		sprite->setTextureRect(IntRect(60 * int(currentFrame), 80, 60, 75));
	}
}

void Player::update(float t)
{
	ControlPlayer(t);
	sprite->setPosition(x, y);
}

bool Player::getCombo()
{
	return combo;
}

void Player::setCombo(bool c)
{
	combo = c;
}