#include "GameInterface.h"



GameInterface::GameInterface()
{
	image = new Image();
	texture = new Texture();
	sprite = new Sprite();
}

GameInterface::~GameInterface()
{
	delete image, texture, sprite;
}

Sprite GameInterface::getSprite()
{
	return *sprite;
}
