#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Objetives.h"
using namespace sf;

class GreyBall : public Objetives {
protected:
	Sprite greyBall;
	Texture greyBall_tx;
	bool _shotDown;
	bool _isAlive;
	bool _isVisible;
public:
	GreyBall();
	~GreyBall();
	void SetPosition(Vector2f pos);
};