#pragma once
class Settings
{
private:
	static Settings * p_instance;
	// ������������ � �������� ������������ ���������� ��������
	Settings();
	Settings(const Settings&);
	Settings& operator=(Settings&);
	int speedGame = 200;
public:
	static Settings & getInstance();
	int getSpeedGame() const;
	void setSpeedGame(int speed);
};



