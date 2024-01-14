#include "Stadx.h"

class Mike 
{
private:

	Sprite _mikeSp;
	Texture _mikeTx;

	int _lifes;
	float x;
	float y;

	Vector2f _position;
	Vector2f _velocity;
	Vector2f _acceleration;

public:

	Mike(int lifes);
	~Mike();

	void Update(float deltaTime);
	void UpdateOrientation();
	void Draw(RenderWindow* _wnd);
	void Pricked();
	void SetPosition(Vector2f pos);
	void SetVelocity(Vector2f vel);
	void SetAcceleration(Vector2f acc);
	void AddAcceleration(Vector2f acc);

	Vector2f GetPosition();
	Vector2f GetVelocity();
	Vector2f GetAcceleration();

	bool GetPricked(float x, float y);
	int GetLifes();
};
