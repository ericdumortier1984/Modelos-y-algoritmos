#include "Stadx.h"

class Mike {
private:

	Sprite _mikeSp;
	Texture _mikeTx;

	Vector2f _position;
	Vector2f _velocity;
	Vector2f _acceleration;

public:

	Mike();
	~Mike();

	void Update(float deltaTime);
	void Draw(RenderWindow* _wnd);
	void SetPosition(Vector2f pos);
	void SetVelocity(Vector2f vel);
	void SetAcceleration(Vector2f acc);
	void AddAcceleration(Vector2f acc);

	Vector2f GetPosition();
	Vector2f GetVelocity();
	Vector2f GetAcceleration();
};
