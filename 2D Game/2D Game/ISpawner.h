#pragma once
#include "SFML\Graphics.hpp"
// TODO:ƒобавить новые классы и спрайты текстур
class  ISpawner
{
public:
	virtual ~ISpawner() { };
	virtual sf::Sprite& spawn() = 0;
};