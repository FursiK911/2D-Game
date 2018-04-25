#pragma once
#include "Entity.h"
class NPC :
	public Entity
{
private:
	Font* font;
	Text* text;
	Texture* dialogCloudTexture;
	Sprite* dialogCloud;
	bool showDialogText;
	float dialogAppTimer;
public:
	NPC();
	~NPC();
	void update(float t, String * map);
	bool getShowDialogText();
	void setShowDialogText(bool isShow);
	Text& getText();
	Sprite& getDialogCloud();
};

