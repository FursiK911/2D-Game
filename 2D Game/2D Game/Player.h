#pragma once
#include "SFML\Graphics.hpp"
#include "Entity.h"
#include <list>
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
	void InteractionWithEntity(std::list<Entity*> &entities, std::list<Entity*>::iterator it);

	enum { left, right, up, down, jump, stay } state;

	bool getCombo();
};


//for (it = entities.begin(); it != entities.end();)
//{
//	Entity *b = *it;
//	if (b->getLife() == false)
//	{
//		it = entities.erase(it);
//		delete b;
//	}
//	else it++;
//}
//
//for (it = entities.begin(); it != entities.end(); it++)
//{
//	if ((*it)->getRect().intersects(player->getRect()))//если прямоугольник спрайта объекта пересекается с игроком
//	{
//		if ((player->getCombo() == true && (int)player->getCurrentFrame() % 2 != 0))
//		{
//			(*it)->setCoordinateX((*it)->getCoordinateX() - 4);
//			(*it)->setDY((*it)->getDY() - 0.12);
//			(*it)->setHealth(0);
//		}
//		else
//		{
//			//иначе враг что-то сделал
//		}
//	}
//}

