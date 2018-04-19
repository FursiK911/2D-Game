#pragma once
#include "SFML\Graphics.hpp"
#include "Entity.h"
#include "Player.h"
#include "Map.h"
#include "Camera.h"
using namespace sf;


class GameProcess
{
private:
	RenderWindow* window;
	Clock* clock;
	Entity* player;
	Map* map;
	Camera* camera;
	float time;
public:
	GameProcess();
	~GameProcess();
	void start();
};

