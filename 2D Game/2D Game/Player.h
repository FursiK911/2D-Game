#pragma once
#include "SFML\Graphics.hpp"
#include "Entity.h"
#include "Settings.h"
#include <list>
using namespace sf;

class Player : public Entity
{
private:
	float oldCurrentFrame;
	int directionMove;
	bool attack, combo, onGround, kickL = false, kickR = false, kickUp = false;
	Settings* settings;
public:
	Player(String f, float x, float y, float w, float h);
	~Player();

	void update(float t, String * map);
	void control(float & t);
	void checkCollisionWithMap(float Dx, float Dy, String* TileMap);
	void InteractionWithEntity(std::list<Entity*> &entities, std::list<Entity*>::iterator it);

	enum { left, right, up, down, jump, stay } state;
};
