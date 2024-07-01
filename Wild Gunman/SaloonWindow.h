#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class SaloonWindow 
{
private:
	Vector2i _position;
public:
	SaloonWindow(int x, int y);
	void SetPosition(Vector2i position);
	Vector2i GetPos();
};
	