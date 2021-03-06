#include "Enemy.h"



Enemy::Enemy(String f, float PositionX, float PositionY, float w, float h)
{
	image = new Image();
	texture = new Texture();
	sprite = new Sprite();
	file = &f;
	x = PositionX;
	y = PositionY;
	dx = 0.05;
	dy = 0;
	width = w;
	height = h;
	health = 100;
	life = true;
	currentFrame = 0;
	speed = 0.1;
	onGround = false;
	image->loadFromFile("images/Entities/" + *file);
	texture->loadFromImage(*image);
	sprite->setTexture(*texture);
	sprite->setTextureRect(IntRect(0, 0, w, h)); //IntRect - ���������� �����
	sprite->setPosition(PositionX, PositionY);
	sprite->setOrigin(w / 2, h / 2 + 5 );
}

Enemy::~Enemy()
{
}

void Enemy::update(float t, String * map)
{
	//moveTimer += time;if (moveTimer>3000){ dx *= -1; moveTimer = 0; }//������ ����������� �������� ������ 3 ���
		if (life == true && dx > 0)
		{
			currentFrame -= 0.001 * t; // �������� ��������
			if (currentFrame < 0) currentFrame += 6;
			sprite->setScale(1, 1); //������� �� �����������
			sprite->setTextureRect(IntRect(60 * int(currentFrame), 0, 60, 70));
		}
		else if (life == true && dx < 0)
		{
			currentFrame -= 0.001 * t; // �������� ��������
			if (currentFrame < 0) currentFrame += 6;
			sprite->setScale(-1, 1); //������� �� �����������
			sprite->setTextureRect(IntRect(60 * int(currentFrame), 0, 60, 70));
	}
	x += dx*t;
	checkCollisionWithMap(dx, 0, map);//������������ ������������ �� �
	y += dy*t;
	checkCollisionWithMap(0, dy, map);//������������ ������������ �� Y
	sprite->setPosition(x + width / 2, y + height / 2); //������ ������� ������� � ����� ��� ������
	dy = dy + 0.00015*t; //��������� ����������
	if (health <= 0) 
	{ 
		if (life == true)
			currentFrame = 3;

			life = false;
			if ((int)currentFrame > 0)
				currentFrame -= 0.001 * t; // �������� ��������
			else
				currentFrame = 0;

			if (dx > 0)
				sprite->setScale(1, 1); //������� �� �����������
			else
				sprite->setScale(-1, 1);

		sprite->setTextureRect(IntRect(60 * int(currentFrame), 80, 60, 82));
	}
}

void Enemy::checkCollisionWithMap(float Dx, float Dy, String * TileMap)
{
	for (int i = y / 32; i < (y + height) / 32; i++)
		for (int j = x / 32; j<(x + width) / 32; j++)
		{
			if (TileMap[i][j] == '0')
			{
				if (Dy>0) { y = i * 32 - height; dy = 0;}//�� Y ����=>���� � ���(����� �� �����) ��� ������. � ���� ������ ���� ���������� ��������� � ��������� ��� �� �����, ��� ���� ������� ��� �� �� ����� ��� ����� ����� ����� �������
				if (Dy<0) { y = i * 32 + 32; dy = 0;}
				if (Dx>0) { x = j * 32 - width; dx = -0.05; sprite->scale(-1, 1); }
				if (Dx<0) { x = j * 32 + 32; dx = 0.05; sprite->scale(-1, 1); }
			}
		}
}