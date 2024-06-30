#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Player {
protected:
	Sprite playerSprite;
	Texture playerTexture;
public:
	Player();
	void Draw(RenderWindow* _wnd);
	void SetPosition(float x, float y);
	Vector2f Getpos();
};
