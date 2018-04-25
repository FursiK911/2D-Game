#include "GameProcess.h"
#include "Scene1.h"
using namespace sf;



GameProcess::GameProcess()
{
	window = new RenderWindow(sf::VideoMode(800, 600), "2D Game");
	menu = new MainMenu();
	clock = new Clock();
	player = new Player("hero.png", 400, 150, 50, 75);
	sharpoviy = new NPC();
	sharpoviy->setCoordinateX(300); sharpoviy->setCoordinateY(160);
	sharpoviy->getSprite().setPosition(sharpoviy->getCoordinateX(), sharpoviy->getCoordinateY());
	for (int i = 1; i < 5; i++)
	{
		entities.push_back(new Enemy("enemy.png", XEnemies[i], YEnemies[i], 60, 60));
	}
	map = new Map();
	camera = new Camera();
	lifeBar = new LifeBar();
	iconPlayer = new IconPlayer();
}

GameProcess::~GameProcess()
{
	delete window, clock, player, map, camera, settings, lifeBar, iconPlayer, menu;
}

void GameProcess::start()
{
	menu->start(window);
	while (window->isOpen())
	{
		time = clock->getElapsedTime().asMicroseconds();
		clock->restart();
		time /= settings->getInstance()->getSpeedGame();//скорость игры

		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}
		if (player->getLife())
		{
			player->InteractionWithEntity(entities, it, sharpoviy);
			player->update(time, TileMap);
		}
		sharpoviy->update(time,TileMap);
		lifeBar->update(player->getHealth());
		for (it = entities.begin(); it != entities.end(); it++)
		{ 
			(*it)->update(time, TileMap); 
		}
		camera->setCameraPosition(player->getCoordinateX() + 100, player->getCoordinateY(), LEFT_BORDER, RIGHT_BORDER, UPPER_BORDER, LOWER_BORDER);
		window->clear();
		map->buildMap(*window, TileMap, HEIGHT_MAP, WIDTH_MAP);
		window->setView(camera->getCamera());
		window->draw(sharpoviy->getSprite());
		for (it = entities.begin(); it != entities.end(); it++)
		{
			window->draw((*it)->getSprite());
		}
		if (sharpoviy->getShowDialogText())
		{
			window->draw(sharpoviy->getDialogCloud());
			window->draw(sharpoviy->getText());
		}
		window->draw(player->getSprite());
		lifeBar->draw(window, camera);
		iconPlayer->draw(window, camera);
		window->display();
	}
}
