#include "LifeBar.h"



LifeBar::LifeBar()
{
	image->loadFromFile("images/Interface/life.png");
	image->createMaskFromColor(Color(50, 96, 166));
	texture->loadFromImage(*image);
	sprite->setTexture(*texture);
	sprite->setTextureRect(IntRect(783, 2, 15, 84));
	bar = new RectangleShape();

	bar->setFillColor(Color(0, 0, 0));//������ ������������� ������������� ������ � ���������� ������ ���������� ��������
	max = 100;
}

LifeBar::~LifeBar()
{
	delete bar;
}

void LifeBar::update(int k)
{
	if (k>0 && k<max)
		bar->setSize(Vector2f(10, (max - k) * 70 / max));//���� �� ������������ � ��� ���� ������ ���������, �� ������������� ����� �������� (����� ������) ��� ������� ��������������
}

void LifeBar::draw(RenderWindow* window, Camera* camera)
{
	Vector2f center = window->getView().getCenter();
	Vector2f size = window->getView().getSize();

	sprite->setPosition(camera->getCamera().getCenter().x - 390, camera->getCamera().getCenter().y - 300);
	bar->setPosition(camera->getCamera().getCenter().x - 386, camera->getCamera().getCenter().y - 296);

	window->draw(*sprite);//������� ������ ������� ��������
	window->draw(*bar);//������ �� ��� ������ �������������, �� ��� �� ��������� �
}
