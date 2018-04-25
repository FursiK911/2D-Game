#pragma once
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include "Entity.h"
#include "Settings.h"
#include "Enum.h"
#include "NPC.h"
#include <list>
using namespace sf;

class Player : public Entity
{
private:
	float oldCurrentFrame;
	bool combo, onGround, kickL = false, kickR = false, kickUp = false;
	Settings* settings;
	SoundBuffer* hitBuffer, *attack1Buffer, *attack2Buffer, *jumpBuffer, *walkBuffer, *loseBuffer;
	Sound* hit, *attack1, *attack2, *jump, *walk, *lose;
	Status state, directionMove;
public:
	Player(String f, float x, float y, float w, float h);
	~Player();

	void update(float t, String * map);
	void control(float & t);
	void attackedAnimation(float& t);
	void checkCollisionWithMap(float Dx, float Dy, String* TileMap);
	void InteractionWithEntity(std::list<Entity*> &entities, std::list<Entity*>::iterator it, NPC* sharpoviy);
	void lifeCheck(float& t);
};
