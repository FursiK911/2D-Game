#include "DarkGroundSpawner.h"



DarkGroundSpawner::DarkGroundSpawner()
{
	path = "images/textures.png";
	image.loadFromFile(path);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(32,0,32,32));
}


DarkGroundSpawner::~DarkGroundSpawner()
{
}

 Sprite& DarkGroundSpawner::spawn()
{
	return sprite;
}
