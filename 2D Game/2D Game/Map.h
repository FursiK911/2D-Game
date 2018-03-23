#pragma once
#include "SFML\Graphics.hpp"
#include "ISpawner.h"
#include "DarkGroundSpawner.h"
#include "GroundSpawner.h"
#include <vector>
using namespace sf;

class Map
{
private:
	DarkGroundSpawner* darkGround = new DarkGroundSpawner();
	GroundSpawner* ground = new GroundSpawner();
	Sprite* tmpSprite = new Sprite();
	int heightMap, widthMap;
public:
	Map();
	~Map();
	void buildMap(RenderWindow& window, String * mapString, int h, int w);
};

