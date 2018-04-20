#pragma once
class Settings
{
private:
	static Settings * p_instance;
	// Конструкторы и оператор присваивания недоступны клиентам
	Settings();
	Settings(const Settings&);
	Settings& operator=(Settings&);
	int speedGame = 200;
	bool drawStunnedEnemies = false;
public:
	static Settings & getInstance();
	int getSpeedGame() const;
	void setSpeedGame(int speed);
	bool getStun();
	void setStun(bool stun);
};



