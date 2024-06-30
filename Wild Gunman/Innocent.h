#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"

using namespace sf;

class Innocent : public Enemy {
protected:
	Sprite innocent_Sp;
	Texture innocent_Tx;
	Vector2f innocentPositions[5]; // arreglo para almacenar las diferentes posiciones del inocente
public:
	Innocent();
	void Draw(RenderWindow* _wnd);
	void InnocentUpdate(RenderWindow* _wnd);
	bool ShootAtInnocent();
	bool IsAbove(float x, float y);
	Clock _clock;
};