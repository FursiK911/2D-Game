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
	texts[0] = new Text("Приветствую тебя,\n меня зовут Шарповый.\nЯ помогу тебе освоиться\n в игре!", *font, 20);
	texts[1] = new Text("Управление:\nпередвижение стрелками,\nдля атаки зажми \nпробел", *font, 20);
	texts[2] = new Text("8 бит...8 бит...\nЭто лучше чем 16...\nХорошая песня,\nне так ли?", *font, 20);
	texts[3] = new Text("\nА вы любите JAVA?", *font, 20);
	texts[4] = new Text("Хорошо, что \nя не видел твой код\nэтой игры", *font, 20);
	for (int i = 0; i < 5; i++) 
	{
		texts[i]->setColor(Color::Black);
	}
	dialogCloudTexture = new Texture();
	dialogCloudTexture->loadFromFile("images/Interface/dialogCloud.png");
	dialogCloud = new Sprite();
	dialogCloud->setTexture(*dialogCloudTexture);
	
	showDialogText = false;
	dialogAppTimer = 0;
	numberText = 0;
}


NPC::~NPC()
{
	for (int i = 0; i < 5; i++)
		delete texts[i];
	delete font, dialogCloud, dialogCloudTexture;
}

void NPC::update(float t, String * map)
{
	if (showDialogText)
	{
		if (dialogAppTimer > 2000)
		{
			showDialogText = false;
			dialogAppTimer = 0;
			if (numberText > 3)
				numberText = 0;
			else
				++numberText;
		}
		texts[numberText]->setPosition(x + 70, y - 110);
		dialogCloud->setPosition(x + 15, y - 150); //задаём позицию облачку
		dialogAppTimer += 1;
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
	return *texts[numberText];
}

Sprite & NPC::getDialogCloud()
{
	return *dialogCloud;
}
