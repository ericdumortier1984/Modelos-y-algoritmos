#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;

class Enemy
{
protected:

	Sprite* _sprite;
	Texture* _texture;
	Vector2f _position;
	Clock _clock;
	int _typeEnemy;
	bool _isAlive;
	bool _isVisible;
	float timeVisible;
	float timeNotVisible;

public:

	Enemy();
	~Enemy();
	void Draw(RenderWindow& wnd);
	void EnemyUpdate(RenderWindow& wnd);
	void Reset(RenderWindow& wnd);
	void InitEnemies(); // Inicia los enemigos
	void SetTexture(const string& texturePath);
	float GetVisibleTime();
	bool IsAlive();
	bool IsInGame();
	bool IsAbove(float x, float y);
	bool Shoot();
	bool Die();
};