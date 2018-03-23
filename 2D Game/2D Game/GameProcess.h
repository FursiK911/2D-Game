#pragma once
#include "SFML\Graphics.hpp"
#include "Player.h"
#include "Map.h"
#include "Scene1.h"
using namespace sf;


class GameProcess
{
private:
	RenderWindow* window;
	Clock* clock;
	Player* player;
	Map* map;
	float time;
public:
	GameProcess();
	~GameProcess();
	void start();
};

