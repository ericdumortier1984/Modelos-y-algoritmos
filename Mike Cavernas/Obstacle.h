#include "stdafx.h"

class Obstacle  {
private:
	Sprite _obstacleSprite;
	Texture _obstacleTexture;
	Vector2f _position;
	Vector2f _acceleration;
	Vector2f _velocity;
public:
	Obstacle();
	~Obstacle();

	void Draw(RenderWindow* _wnd);
	void UpdateObstacle(float deltaTime);
	void SetPosition(Vector2f Pos);
	void SetAcceleration(Vector2f Acc);
	void SetVelocity(Vector2f Vel);
	void AddAcceleration(Vector2f Acc);

	Vector2f GetPosition();
	Vector2f GetAcceleration();
	Vector2f GetVelocity();

	bool isAbove(float x, float y);
};
