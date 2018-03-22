#include "Map.h"
#include"ISpawner.h"
#include"DarkGroundSpawner.h"
#include"GroundSpawner.h"



Map::Map()
{
}
Map::~Map()
{
}

void Map::buildMap(String * mapString, int heightMap, int widthMap)
{
	for (int i = 0; i < heightMap; i++)
	{
		for (int j = 0; j < widthMap; j++)
		{
			if (mapString[i][j] == ' ')
			{
				mapSprite.push_back = new DarkGroundSpawner*();
			}
			if (mapString[i][j] == '0')
			{
				mapSprite.push_back = new GroundSpawner*();
			}
		}
	}
}
