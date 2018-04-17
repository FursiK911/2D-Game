#include "MoveLeftCommand.h"



MoveLeftCommand::MoveLeftCommand()
{
}

MoveLeftCommand::~MoveLeftCommand()
{
}

void MoveLeftCommand::execute()
{
	player->setCombo(false);
	float currentFrame = player->getCurrentFrame();
	currentFrame += 0.001*time; // скорость анимации
	if (currentFrame > 3) currentFrame -= 3;
	player->getSprite().setScale(-1, 1); //отразим по горизонтали
	player->getSprite().setTextureRect(IntRect(50 * int(player->getCurrentFrame()), 0, 50, 75));
	player->setDX(-player->getSpeed()); player->setDY(0);
	float x = player->getCoordinateX();
	x += player->getDX() * time;
	player->setCoordinateX(x);
	player->getSprite().move(x, 0);
	player->setCurrentFrame(currentFrame);
}
