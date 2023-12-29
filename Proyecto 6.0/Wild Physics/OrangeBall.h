#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Objetives.h"
using namespace sf;

class OrangeBall : public Objetives {
protected:
	Sprite orangeBall;
	Texture orangeBall_tx;
	bool _shotDown;
	bool _isAlive;
	bool _isVisible;
public:
	OrangeBall();
	~OrangeBall();
	void SetPosition(Vector2f pos);
};