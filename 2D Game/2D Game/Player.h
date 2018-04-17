#pragma once
#include "SFML\Graphics.hpp"
#include "Camera.h"
#include "Entity.h"
using namespace sf;
// TODO:Сделать общий класс родителя для игрока и врага
class Player : public Entity
{
public:
	Player(String f, float x, float y, float w, float h);
	~Player();
	bool combo;

	void ControlPlayer(float time);
	void update(float t);

	bool getCombo();
	void setCombo(bool c);
	

};

