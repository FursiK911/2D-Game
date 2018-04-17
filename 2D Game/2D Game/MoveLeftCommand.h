#pragma once
#include "Command.h"
#include "Player.h"

class MoveLeftCommand :
	public Command
{
public:
	MoveLeftCommand();
	~MoveLeftCommand();
	void execute();
};

