#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Objetives.h"
using namespace sf;

class GreenBall : public Objetives {
protected:
	Sprite greenBall;
	Texture greenBall_tx;
	bool _shotDown;
	bool _isAlive;
	bool _isVisible;
public:
	GreenBall();
	~GreenBall();
	void SetPosition(Vector2f pos);
};