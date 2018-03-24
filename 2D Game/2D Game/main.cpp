#include <SFML/Graphics.hpp>
#include "GameProcess.h"

using namespace sf;

int main()
{
	GameProcess* game = new GameProcess();
	game->start();
	delete game;
}