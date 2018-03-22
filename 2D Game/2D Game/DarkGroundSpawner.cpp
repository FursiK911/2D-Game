#include "DarkGroundSpawner.h"



DarkGroundSpawner::DarkGroundSpawner()
{
	path = "images/texture.png";
	image.loadFromFile(path);
	texture.loadFromImage(image);
	sprite.setTextureRect(IntRect(32,0,32,32));
}


DarkGroundSpawner::~DarkGroundSpawner()
{
}

Sprite& DarkGroundSpawner::getSprite()
{
	return sprite;
}

void DarkGroundSpawner::spawn()
{
}
