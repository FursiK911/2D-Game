#include "MainMenu.h"



MainMenu::MainMenu()
{
	newGameImage = new Image();
	exitImage = new Image();
	aboutProgramImage = new Image();
	menuBackgroundImage = new Image();

	newGameTexture = new Texture();
	exitTexture = new Texture();
	aboutProgramTexture = new Texture();
	menuBackgroundTexture = new Texture();

	newGame = new Sprite();
	exitButton = new Sprite();
	aboutProgram = new Sprite();
	menuBackground = new Sprite();

	isMenu = true;
	menuNum = 0;

	newGameImage->loadFromFile("images/Menu/newGame.png");
	exitImage->loadFromFile("images/Menu/exit.png");
	aboutProgramImage->loadFromFile("images/Menu/about.png");
	menuBackgroundImage->loadFromFile("images/Menu/menu.png");

	newGameTexture->loadFromImage(*newGameImage);
	exitTexture->loadFromImage(*exitImage);
	aboutProgramTexture->loadFromImage(*aboutProgramImage);
	menuBackgroundTexture->loadFromImage(*menuBackgroundImage);

	newGame->setTexture(*newGameTexture);
	exitButton->setTexture(*exitTexture);
	aboutProgram->setTexture(*aboutProgramTexture);
	menuBackground->setTexture(*menuBackgroundTexture);

	newGame->setPosition(100, 180);
	aboutProgram->setPosition(100, 240);
	exitButton->setPosition(100, 240);
	menuBackground->setPosition(0, 0);
}

MainMenu::~MainMenu()
{
	delete newGameImage, newGameTexture, newGame, exitImage,
		exitTexture, exitButton, aboutProgramImage, aboutProgramTexture, aboutProgram, menuBackgroundImage, menuBackgroundTexture, menuBackground;
}

void MainMenu::start(RenderWindow * window)
{
	while (isMenu)
	{
		newGame->setColor(Color::White);
		//aboutProgram->setColor(Color::White);
		exitButton->setColor(Color::White);
		menuNum = 0;
		window->clear(Color(129, 181, 221));

		if (IntRect(100, 180, 300, 50).contains(Mouse::getPosition(*window))) { newGame->setColor(Color::Blue); menuNum = 1; }
		//if (IntRect(100, 240, 300, 50).contains(Mouse::getPosition(*window))) { aboutProgram->setColor(Color::Blue); menuNum = 2; }
		if (IntRect(100, 240, 300, 50).contains(Mouse::getPosition(*window))) { exitButton->setColor(Color::Blue); menuNum = 3; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;//если нажали первую кнопку, то выходим из меню 
			//if (menuNum == 2) {window->draw(about); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }
			if (menuNum == 3) { window->close(); isMenu = false; }

		}

		window->draw(*menuBackground);
		window->draw(*newGame);
		//window->draw(*aboutProgram);
		window->draw(*exitButton);

		window->display();
	}
}
