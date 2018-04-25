#pragma once
#include "SFML\Graphics.hpp"
using namespace sf;
class MainMenu
{
private:
	Image *newGameImage, *aboutProgramImage, *exitImage, *menuBackgroundImage;
	Texture *newGameTexture, *aboutProgramTexture, *exitTexture, *menuBackgroundTexture;
	Sprite *newGame, *exitButton, *aboutProgram, *menuBackground;
	bool isMenu = 1;
	int menuNum = 0;
public:
	MainMenu();
	~MainMenu();
	void start(RenderWindow* window);
};

