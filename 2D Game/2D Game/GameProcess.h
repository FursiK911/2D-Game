#pragma once
#include "SFML\Graphics.hpp"
#include "Player.h"
#include "Map.h"
using namespace sf;


class GameProcess
{
private:
	RenderWindow* window;
	Clock* clock;
	Player* player;
	Camera* camera;
	Map* map;
	float time, speedGame;

public:
	GameProcess();
	~GameProcess();
	void start();
};

