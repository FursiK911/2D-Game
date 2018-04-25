#pragma once
#include "SFML\Graphics.hpp"
#include "MainMenu.h"
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "NPC.h"
#include "Map.h"
#include "Camera.h"
#include "Settings.h"
#include "GameInterface.h"
#include "LifeBar.h"
#include "IconPlayer.h"
#include <list>
using namespace sf;


class GameProcess
{
private:
	RenderWindow* window;
	MainMenu* menu;
	Clock* clock;
	Player* player;
	NPC* sharpoviy;
    std::list<Entity*> entities;
	std::list<Entity*>::iterator it;
	Map* map;
	Camera* camera;
	Settings* settings;
	LifeBar* lifeBar;
	GameInterface* iconPlayer;
	float time;
public:
	GameProcess();
	~GameProcess();
	void start();
};

