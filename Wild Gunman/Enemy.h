#pragma once
#include "Include&using.h"

class Enemy 
{
private:

	Sprite* sprite;
	Texture* texture;
	Vector2f position;
	bool isInnocent;

public:

	Enemy(const string& texturePath, const Vector2f& pos, bool innocent);
	~Enemy();

	void Draw(RenderWindow* _wnd);

	const Vector2f& GetPosition() const 
	{
		return sprite->getPosition();
	}

	bool IsInnocent() const 
	{
		return isInnocent;
	}
};