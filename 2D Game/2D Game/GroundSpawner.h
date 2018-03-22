#pragma once
#include"SFML\Graphics.hpp"
#include"ISpawner.h"
using namespace sf;
class GroundSpawner : ISpawner
{
private:
	char* path;
	Image image;
	Texture texture;
	Sprite sprite;
public:
	GroundSpawner();
	~GroundSpawner();
	Sprite& getSprite();
	void spawn();
};

