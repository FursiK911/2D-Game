#pragma once
#include "SFML\Graphics.hpp"
#include "ISpawner.h"
using namespace sf;
class DarkGroundSpawner : public ISpawner
{
private:
	char* path;
	Image image;
	Texture texture;
	Sprite sprite;
public:
	DarkGroundSpawner();
	~DarkGroundSpawner();
	Sprite& getSprite();
	void spawn();
};

