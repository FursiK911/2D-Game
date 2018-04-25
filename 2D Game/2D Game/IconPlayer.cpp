#include "IconPlayer.h"



IconPlayer::IconPlayer()
{
	image->loadFromFile("images/Interface/life.png");
	image->createMaskFromColor(Color(50, 96, 166));
	texture->loadFromImage(*image);
	sprite->setTexture(*texture);
	sprite->setTextureRect(IntRect(600, 0, 60, 66));
}

IconPlayer::~IconPlayer()
{
}

void IconPlayer::draw(RenderWindow * window, Camera * camera)
{
	sprite->setPosition(camera->getCamera().getCenter().x - 370, camera->getCamera().getCenter().y - 290);
	window->draw(*sprite);
}
