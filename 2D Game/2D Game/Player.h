#pragma once
#include "SFML\Graphics.hpp"
using namespace sf;

class Player
{
private:
	float x, y, weight, height, dx, dy, currentFrame, speed;
	String* file;
	Image* image;
	Texture* texture;
	Sprite* sprite;
	bool attack, combo, onGround, isMove;
public:
	Player(String f, float x, float y, float w, float h);
	~Player();

	void update(float t, String * map);

	enum { left, right, up, down, jump, stay } state;//добавляем тип перечисления - состояние объекта

	void control();

	void checkCollisionWithMap(float Dx, float Dy, String * TileMap);

	Image getImage();
	Texture getTexture();
	Sprite getSprite();
	void setImage(Image& i);
	void setTexture(Texture& t);
	void setSprite(Sprite& s);

	float getCoordinateX();
	void setCoordinateX(float px);
	float getDX();
	void setDX(float pdx);

	float getCoordinateY();
	void setCoordinateY(float py);
	float getDY();
	void setDY(float pdy);

	float getCurrentFrame();
	void setCurrentFrame(float c);

	float getSpeed();
	void setSpeed(float s);

	bool getOnGround();
	void setOnGround(bool ongroud);
};

