#pragma once
#include "SFML\Graphics.hpp"
// TODO:�������� ����� ������ � ������� �������
class  ISpawner
{
public:
	virtual ~ISpawner() { };
	virtual sf::Sprite& spawn() = 0;
};