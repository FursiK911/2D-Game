#include "DarkGroundSpawner.h"



DarkGroundSpawner::DarkGroundSpawner()
{
	image = new Image();
	texture = new Texture();
	sprite = new Sprite();
	path = "images/textures.png";
	image->loadFromFile(path);
	texture->loadFromImage(*image);
	sprite->setTexture(*texture);
	sprite->setTextureRect(IntRect(32,0,32,32));
}


DarkGroundSpawner::~DarkGroundSpawner()
{
	delete image, texture, sprite;
}

 Sprite& DarkGroundSpawner::spawn()
{
	return *sprite;
}
