#pragma once
// TODO: Сделать синглтоном
class Setting
{
private:
	static Setting * p_instance;
	// Конструкторы и оператор присваивания недоступны клиентам
	Setting() {}
	Setting(const Setting&);
	Setting& operator=(Setting&);
public:
	static Setting * getInstance();
};

