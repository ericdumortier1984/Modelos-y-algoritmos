#pragma once
#include "Include&using.h"

class Player
{
protected:

	Sprite* sprite;
	Texture* texture;

public:

	Player();
	~Player();

	void Draw(RenderWindow* _wnd);
	void SetPosition(float x, float y);
	Vector2f Getpos();
};