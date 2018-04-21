#include "Settings.h"

Settings* Settings::p_instance = 0;

Settings* Settings::getInstance()
{
	if (!p_instance)
	{
		p_instance = new Settings();
	}
	return p_instance;
}

int Settings::getSpeedGame() const
{
	return speedGame;
}

void Settings::setSpeedGame(int speed)
{
	speedGame = speed;
}

bool Settings::getStun()
{
	return drawStunnedEnemies;
}

void Settings::setStun(bool stun)
{
	drawStunnedEnemies = stun;
}

Settings::Settings()
{
}
