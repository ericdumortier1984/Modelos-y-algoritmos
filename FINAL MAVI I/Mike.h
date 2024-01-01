#include "stdafx.h"

class Mike {
private:
	Sprite mikeSp;
	Texture mikeTx;
	Vector2f position;
	Vector2f acceleration;
	Vector2f velocity;
	int lifes;
public:
	Mike(float width, float height);
	~Mike();

	void Draw(RenderWindow* window);
	void UpdateMike(float deltaTime);
	void SetPosition(Vector2f Pos);
	void SetAcceleration(Vector2f Acc);
	void SetVelocity(Vector2f Vel);
	void AddAcceleration(Vector2f Acc);
	Vector2f GetPosition();
	Vector2f GetAcceleration();
	Vector2f GetVelocity();
	void LoseLife();
	int GetLife();
};
