#include "GameProcess.h"
#include "Scene1.h"
using namespace sf;



GameProcess::GameProcess()
{
	window = new RenderWindow(sf::VideoMode(800, 600), "2D Game");
	clock = new Clock();
	player = new Player("hero.png", 200, 200, 50, 75);
	map = new Map();
	camera = new Camera();
	speedGame = 200;
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
		time /= speedGame; //скорость игры

		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}
		player->update(time);
		camera->setCameraPosition(player->getCoordinateX() + 100, player->getCoordinateY(), LEFT_BORDER, RIGHT_BORDER, UPPER_BORDER, LOWER_BORDER);
		window->clear();
		window->setView(camera->getCamera());
		map->buildMap(*window, TileMap, HEIGHT_MAP, WIDTH_MAP);
		window->draw(player->getSprite());
		window->display();
	}
}
