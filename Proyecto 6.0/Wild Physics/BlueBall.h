#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Objetives.h"
using namespace sf;

class BlueBall : public Objetives {
protected:
	Sprite blueBall;
	Texture blueBall_tx;
	bool _shotDown;
	bool _isAlive;
	bool _isVisible;
public:
	BlueBall();
	~BlueBall();
	void SetPosition(Vector2f pos);
};