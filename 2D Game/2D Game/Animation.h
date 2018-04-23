#pragma once
#include "SFML\Graphics.hpp"
#include "Enum.h"
using namespace sf;
class Animation
{
private:
	Sprite* sprite;
	float currentFrame, oldCurrentFrame;
public:
	Animation(Sprite* s);
	~Animation();

	void moveLeft(float t, int x, int y, int width, int height);
	void moveRight(float t, int x, int y, int width, int height);
	void jump(float t, int x, int y, int width, int height, Status& directionMove);
	bool combo(float t, int x, int y, int width, int height, Status& oldState);
	void attacked(float t, int x, int y, int width, int height);
};

