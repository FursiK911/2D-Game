#include "Map.h"
#include"ISpawner.h"
#include"DarkGroundSpawner.h"
#include"GroundSpawner.h"



Map::Map()
{
}
Map::~Map()
{
	delete darkGround;
	delete ground;
	delete tmpSprite;
}

void Map::buildMap(RenderWindow& window, String * mapString, int h, int w)
{
	heightMap = h;
	widthMap = w;
	for (int i = 0; i < heightMap; i++)
		for (int j = 0; j < widthMap; j++)
		{
			if (mapString[i][j] == ' ')  *tmpSprite = darkGround->spawn();
			if (mapString[i][j] == '0') *tmpSprite = ground->spawn();


			tmpSprite->setPosition(j * 32, i * 32);

			window.draw(*tmpSprite);
		}
}