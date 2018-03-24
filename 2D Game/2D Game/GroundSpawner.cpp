#include "GroundSpawner.h"



GroundSpawner::GroundSpawner()
{
	image = new Image();
	texture = new Texture();
	sprite = new Sprite();
	path = "images/textures.png";
	image->loadFromFile(path);
	texture->loadFromImage(*image);
	sprite->setTexture(*texture);
	sprite->setTextureRect(IntRect(0, 0, 32, 32));
}


GroundSpawner::~GroundSpawner()
{
	delete image, texture, sprite;
}

Sprite& GroundSpawner::spawn()
{
	return *sprite;
}
