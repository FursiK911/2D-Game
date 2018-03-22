#include "GroundSpawner.h"



GroundSpawner::GroundSpawner()
{
	path = "images/texture.png";
	image.loadFromFile(path);
	texture.loadFromImage(image);
	sprite.setTextureRect(IntRect(0, 0, 32, 32));
}


GroundSpawner::~GroundSpawner()
{
}

Sprite & GroundSpawner::getSprite()
{
	return sprite;
}

void GroundSpawner::spawn()
{

}
