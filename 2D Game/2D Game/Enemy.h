#pragma once
#include "Entity.h"
class Enemy :
	public Entity
{
public:
	Enemy(String f, float PositionX, float PositionY, float w, float h);
	~Enemy();
	void update(float t, String * map);
	void checkCollisionWithMap(float Dx, float Dy, String * TileMap);
};

