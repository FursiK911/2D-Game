#pragma once
// TODO: ������� ����������
class Setting
{
private:
	static Setting * p_instance;
	// ������������ � �������� ������������ ���������� ��������
	Setting() {}
	Setting(const Setting&);
	Setting& operator=(Setting&);
public:
	static Setting * getInstance();
};

