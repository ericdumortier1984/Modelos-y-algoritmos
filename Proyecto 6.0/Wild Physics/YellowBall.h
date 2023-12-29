#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Objetives.h"
using namespace sf;

class YellowBall : public Objetives {
protected:
	Sprite yellowBall;
	Texture yellowBall_tx;
	bool _shotDown;
	bool _isAlive;
	bool _isVisible;
public:
	YellowBall();
	~YellowBall();
	void SetPosition(Vector2f pos);
};