#include <SFML/Graphics.hpp>
#include "Player.h"

using namespace sf;

int main()
{
	RenderWindow window(sf::VideoMode(800, 600), "2D Game");

	Clock clock; //создаем переменную времени, т.о. привязка ко времени(а не загруженности/мощности процессора).

	Player p("hero.png", 0, 0, 50, 75);

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time /= 200; //скорость игры

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}



		p.update(time);
		window.clear();
		window.draw(p.getHeroSprite());
		window.display();
	}

	return 0;
}