#pragma once
#include "SFML\Graphics.hpp"
#include "Camera.h"
using namespace sf;

class Player
{
private:
	float x, y, weight, height, dx, dy, currentFrame, speed;
	String* file;
	Image* heroImage;
	Texture* heroTexture;
	Sprite* heroSprite;
	bool attack, combo;
public:
	Player(String f, float x, float y, float w, float h);
	~Player();

	void update(float t);
	void interactionWithMap(String* map);
	float getHeroCoordinateX();
	float getHeroCoordinateY();
	Image& getHeroImage();
	Texture& getHeroTexture();
	Sprite& getHeroSprite();
	void setHeroImage(Image i);
	void setHeroTexture(Texture t);
	void setHeroSprite(Sprite s);
};

