#include "GameProcess.h"
#include "Scene1.h"
using namespace sf;



GameProcess::GameProcess()
{
	window = new RenderWindow(sf::VideoMode(800, 600), "2D Game");
	clock = new Clock();
	player = new Player("hero.png", 250, 500, 50, 75);
	int Xc = 100, Yc = 300;
	for (int i = 0; i < 5; i++)
	{
		entities.push_back(new Enemy("enemy.png", Xc, Yc, 60, 60));
		Xc += 100;
	}
	map = new Map();
	camera = new Camera();
}

GameProcess::~GameProcess()
{
	delete window, clock, player, map, camera;
}

void GameProcess::start()
{
	while (window->isOpen())
	{
		time = clock->getElapsedTime().asMicroseconds();
		clock->restart();
		time /= 200; //скорость игры

		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}
		player->update(time, TileMap);
		for (it = entities.begin(); it != entities.end(); it++)
		{ 
			(*it)->update(time, TileMap); 
		}
		player->InteractionWithEntity(entities, it);
		camera->setCameraPosition(player->getCoordinateX() + 100, player->getCoordinateY(), LEFT_BORDER, RIGHT_BORDER, UPPER_BORDER, LOWER_BORDER);
		window->clear();
		map->buildMap(*window, TileMap, HEIGHT_MAP, WIDTH_MAP);
		window->setView(camera->getCamera());
		for (it = entities.begin(); it != entities.end(); it++)
		{
			window->draw((*it)->getSprite());
		}
		window->draw(player->getSprite());
		window->display();
	}
}
