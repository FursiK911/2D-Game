#include "GroundSpawner.h"



GroundSpawner::GroundSpawner()
{
	path = "images/Map/textures.png";
	image.loadFromFile(path);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, 32, 32));
}


GroundSpawner::~GroundSpawner()
{
}

Sprite& GroundSpawner::spawn()
{
	return sprite;
}
