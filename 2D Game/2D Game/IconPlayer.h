#pragma once
#include "GameInterface.h"
class IconPlayer :
	public GameInterface
{
public:
	IconPlayer();
	~IconPlayer();
	void draw(RenderWindow *window, Camera* camera);
};

