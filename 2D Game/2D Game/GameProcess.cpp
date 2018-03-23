#include "GameProcess.h"
using namespace sf;



GameProcess::GameProcess()
{
	window = new RenderWindow(sf::VideoMode(800, 600), "2D Game");
	clock = new Clock();
	player = new Player("hero.png", 0, 0, 50, 75);
	map = new Map();
}


GameProcess::~GameProcess()
{
	delete window, clock, player, map;
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
		player->update(time);
		window->clear();
		map->buildMap(*window, TileMap, HEIGHT_MAP, WIDTH_MAP);
		window->draw(player->getHeroSprite());
		window->display();
	}
}
