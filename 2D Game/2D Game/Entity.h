#pragma once
#include "SFML\Graphics.hpp"
using namespace sf;
class Entity
{
protected:
	float x, y, weight, height, dx, dy, currentFrame, speed;
	String* file;
	Image* image;
	Texture* texture;
	Sprite* sprite;
	bool attack, onGround;
public:
	Entity();
	virtual ~Entity();
	virtual void update(float t) = 0;

	void checkCollisionWithMap(float Dx, float Dy, String * map);

	float getCoordinateX();
	void setCoordinateX(float px);
	float getDX();
	void setDX(float pdx);

	float getCoordinateY();
	void setCoordinateY(float py);
	float getDY();
	void setDY(float pdy);

	Image& getImage();
	Texture& getTexture();
	Sprite& getSprite();
	void setImage(Image i);
	void setTexture(Texture t);
	void setSprite(Sprite s);

	float getCurrentFrame();
	void setCurrentFrame(float c);

	float getSpeed();
	void setSpeed(float s);
};

