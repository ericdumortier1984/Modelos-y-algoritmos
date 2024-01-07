#include "stdafx.h"

class Player {
private:
	Sprite mikeSp;
	Texture mikeTx;
	Vector2f position;
	Vector2f acceleration;
	Vector2f velocity;
	int lifes;
public:
	Player(int lf);
	~Player();

	void Draw(RenderWindow* _wnd);
	void UpdatePlayer(float deltaTime);
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
