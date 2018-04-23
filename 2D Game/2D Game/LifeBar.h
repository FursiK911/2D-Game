#pragma once
#include "GameInterface.h"
class LifeBar :
	public GameInterface
{
private:
	RectangleShape* bar;
	int max;
public:
	LifeBar();
	~LifeBar();
	void update(int k);
	void draw(RenderWindow *window, Camera* camera);
};

