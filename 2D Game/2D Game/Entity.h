#pragma once
#include "SFML\Graphics.hpp"
using namespace sf;
class Entity
{
protected:
	float dx, dy, x, y, speed, moveTimer, currentFrame;
	int width, height, health;
	bool life, isMove, onGround;
	Image* image;
	Texture* texture;
	Sprite* sprite;
	String* name;
public:
	Entity();
	Entity(Image& im, float X, float Y, int W, int H, String* Name);
	virtual ~Entity();

	virtual void update(float t, String * map) = 0;
	virtual void control(float & t) = 0;

	virtual void checkCollisionWithMap(float Dx, float Dy, String * TileMap);

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

