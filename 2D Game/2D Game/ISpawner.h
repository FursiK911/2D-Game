#pragma once
class  ISpawner
{
public:
	ISpawner() { };
	virtual ~ISpawner() { };

	virtual void spawn() = 0;
}