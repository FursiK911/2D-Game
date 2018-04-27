#pragma once
#include "Entity.h"
#include "list"
class NPC :
	public Entity
{
private:
	Font* font;
	Text* texts[5];
	Texture* dialogCloudTexture;
	Sprite* dialogCloud;
	bool showDialogText;
	float dialogAppTimer;
	int numberText;
public:
	NPC();
	~NPC();
	void update(float t, String * map);
	bool getShowDialogText();
	void setShowDialogText(bool isShow);
	Text& getText();
	Sprite& getDialogCloud();
};

