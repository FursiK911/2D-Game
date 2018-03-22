#pragma once
#include "SFML\Graphics.hpp"
#include "ISpawner.h"
#include <vector>
using namespace sf;

class Map
{
private:
	std::vector<ISpawner*> mapSprite;
public:
	Map();
	~Map();
	void buildMap(String *map, int height, int width);
};

