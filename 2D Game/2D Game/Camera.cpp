#include "Camera.h"


Camera::Camera()
{
	camera = new View();
	camera->reset(FloatRect(0, 0, 800, 600));
}


Camera::~Camera()
{
	delete camera;
}

void Camera::setCameraPosition(float x, float y, int leftBorder, int rightBorder, int upperBorder, int lowerBorder)
{
	float tempX = x; float tempY = y;

	if (x < leftBorder) tempX = leftBorder;
	if (x > rightBorder) tempX = rightBorder;
	if (y < upperBorder) tempY = upperBorder;
	if (y > lowerBorder) tempY = lowerBorder;

	camera->setCenter(tempX, tempY);
}

View & Camera::getCamera()
{
	return *camera;
}
