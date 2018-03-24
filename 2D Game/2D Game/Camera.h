#pragma once
#include "SFML\Graphics.hpp"
using namespace sf;

class Camera
{
private:
	View* camera;
public:
	Camera();
	~Camera();

	void setCameraPosition(float x, float y, int leftBorder, int rightBorder, int upperBorder, int lowerBorder);
	View& getCamera();
};

