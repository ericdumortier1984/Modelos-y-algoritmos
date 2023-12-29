#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;

class Crosshair{
private:
	Sprite crosshair;
	Texture crosshair_tx;
public:
	Crosshair();
	~Crosshair();
	Vector2f Getposition();
	void SetPosition(float x, float y);
	void SetOrigin();
	void Draw(RenderWindow* _wnd);
};