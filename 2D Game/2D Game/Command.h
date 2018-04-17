#pragma once
#include "Player.h"
// TODO:Реализовать все существующие команды
class Command
{
public:
	Command();
	virtual ~Command();
	virtual void execute() = 0;
protected:
	Command(Player* p);
	Player* player;
};

