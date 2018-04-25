#include "NPC.h"



NPC::NPC()
{
	image = new Image();
	texture = new Texture();
	sprite = new Sprite();
	image->loadFromFile("images/Entities/sharpoviy.png");
	texture->loadFromImage(*image);
	sprite->setTexture(*texture);

	font = new Font();
	font->loadFromFile("fonts/CyrilicOld.ttf");
	text = new Text("Приветствую тебя,\n меня зовут Шарповый.\nЯ помогу тебе освоиться\n в игре!", *font, 20);
	text->setColor(Color::Black);

	dialogCloudTexture = new Texture();
	dialogCloudTexture->loadFromFile("images/Interface/dialogCloud.png");
	dialogCloud = new Sprite();
	dialogCloud->setTexture(*dialogCloudTexture);
	
	showDialogText = false;
	dialogAppTimer = 0;
}


NPC::~NPC()
{
	delete font, text, dialogCloud, dialogCloudTexture;
}

void NPC::update(float t, String * map)
{
	if (showDialogText)
	{
		text->setPosition(x + 70, y - 110);
		dialogCloud->setPosition(x + 15, y - 150); //задаём позицию облачку
		dialogAppTimer += 1;
		if (dialogAppTimer > 1000)
		{
			showDialogText = false;
			dialogAppTimer = 0;
		}
	}
}

bool NPC::getShowDialogText()
{
	return showDialogText;
}

void NPC::setShowDialogText(bool isShow)
{
	showDialogText = isShow;
}

Text & NPC::getText()
{
	return *text;
}

Sprite & NPC::getDialogCloud()
{
	return *dialogCloud;
}
