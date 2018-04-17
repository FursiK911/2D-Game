#pragma once
#include "SFML\Graphics.hpp"
#include "Player.h"
#include "Map.h"
#include <vector>
using namespace sf;


class GameProcess
{
private:
	RenderWindow* window;
	Clock* clock;
	Entity* player;
	std::vector<Entity*> entity;
	Camera* camera;
	Map* map;
	float speedGame;

public:
	GameProcess();
	~GameProcess();
	void start();
};

