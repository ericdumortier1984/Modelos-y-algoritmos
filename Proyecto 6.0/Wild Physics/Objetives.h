#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;

class Objetives {
protected:
	Sprite sprite;
	Texture texture;
	Vector2f _position;
	Vector2f _velocity;
	Vector2f _acceleration;
	float _randomX;
	bool _shotDown;
	bool _isAlive;
	bool _isVisible;
public:
	Objetives();
	~Objetives();
	virtual void Draw(RenderWindow* _wnd);
	virtual void Update(float deltaTime);
	virtual void SetPosition(Vector2f pos);
	virtual void SetVelocity(Vector2f vel);
	virtual void SetAcceleration(Vector2f acc);
	virtual void AddAcceleration(Vector2f acc);
	virtual Vector2f GetPosition();
	virtual Vector2f GetVelocity();
	virtual Vector2f GetAcceleration();
	virtual bool isAbove(float x, float y);
	virtual bool isInGame();
	virtual bool IsAlive();
	virtual bool ShotDown();
};