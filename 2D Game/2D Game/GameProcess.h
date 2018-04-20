#pragma once
#include "SFML\Graphics.hpp"
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "Map.h"
#include "Camera.h"
#include "Settings.h"
#include <list>
using namespace sf;


class GameProcess
{
private:
	RenderWindow* window;
	Clock* clock;
	Player* player;
    std::list<Entity*> entities;
	std::list<Entity*>::iterator it;
	Map* map;
	Camera* camera;
	//Settings* settings;
	float time;
public:
	GameProcess();
	~GameProcess();
	void start();
};

