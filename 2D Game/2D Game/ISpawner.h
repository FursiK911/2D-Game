#pragma once
#include "SFML\Graphics.hpp"
class  ISpawner
{
public:
	virtual ~ISpawner() { };
	virtual sf::Sprite& spawn() = 0;
};