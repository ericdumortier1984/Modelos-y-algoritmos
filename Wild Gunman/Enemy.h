#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Enemy {
protected:
	Sprite _sprite;
	Texture _tx, _tx2, _tx3;
	Clock _clock;
	bool _isAlive;
	bool _isVisible;
	float timeVisible;
	float timeNotVisible;
	Vector2f enemyPositions[5]; // Arreglo para almacenar las diferentes posiciones del enemigo //
public:
	Enemy();
	void Draw(RenderWindow* _wnd);
	void EnemyUpdate(RenderWindow* _wnd);
	void Reset(RenderWindow* _wnd);
	float GetVisibleTime();
	bool IsAlive();
	bool IsInGame();
	bool IsAbove(float x, float y);
	bool Shoot();
	bool Die();
};