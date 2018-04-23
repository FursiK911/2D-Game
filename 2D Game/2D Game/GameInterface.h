#pragma once
#include "SFML\Graphics.hpp"
#include "Camera.h"
using namespace sf;
class GameInterface
{
protected:
	Image* image;
	Texture* texture;
	Sprite* sprite;
public:
	GameInterface();
	virtual ~GameInterface();
	virtual void update(int k) = 0;
	virtual void draw(RenderWindow *window,Camera* camera) = 0;

	Sprite getSprite();
};

