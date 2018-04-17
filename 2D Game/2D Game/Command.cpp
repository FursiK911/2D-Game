#include "Command.h"



Command::Command()
{
}


Command::~Command()
{
	delete player;
}

Command::Command(Player* p)
{
	player = p;
}
