#pragma once
#include "Player.h"
// TODO:����������� ��� ������������ �������
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

