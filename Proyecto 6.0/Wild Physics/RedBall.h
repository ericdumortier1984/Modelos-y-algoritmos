#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Objetives.h"
using namespace sf;

class RedBall : public Objetives {
protected:
	Sprite redBall;
	Texture redBall_tx;
	bool _shotDown;
	bool _isAlive;
	bool _isVisible;
public:
	RedBall();
	~RedBall();
	void SetPosition(Vector2f pos);
};