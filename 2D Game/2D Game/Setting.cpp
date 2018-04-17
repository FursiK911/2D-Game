#include "Setting.h"

Setting* Setting::p_instance = 0;

Setting * Setting::getInstance()
{
	if (!p_instance)
		p_instance = new Setting();
	return p_instance;
}
