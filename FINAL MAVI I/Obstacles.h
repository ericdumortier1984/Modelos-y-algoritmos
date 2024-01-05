#include "stdafx.h"

class Obstacles {
public:
	Obstacles();
	~Obstacles();
	Sprite wheelSp;
	Texture wheelTx;
	Sprite pincheSp;
	Texture pincheTx;
	Vector2f position;
	Vector2f velocity;
	Vector2f acceleration;

	void Update(float deltaTime);
	void SetPosition(Vector2f pos);
	void SetVelocity(Vector2f vel);
	void SetAcceleration(Vector2f acc);
	void AddAcceleration(Vector2f acc);
	Vector2f GetPosition();
	Vector2f GetVelocity();
	Vector2f GetAcceleration();
};
