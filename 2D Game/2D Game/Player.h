#pragma once
#include "SFML\Graphics.hpp"
#include "Entity.h"
using namespace sf;

class Player : public Entity
{
private:
	int directionMove;
	bool attack, combo, onGround;
public:
	Player(String f, float x, float y, float w, float h);
	~Player();

	void update(float t, String * map);
	void control(float & t);
	void checkCollisionWithMap(float Dx, float Dy, String* TileMap);


	enum { left, right, up, down, jump, stay } state;
};

