#include "Stadx.h"

class Obstacles 
{
private:

	Sprite _pteroSp;
	Texture _pteroTx;

	Vector2f _position;
	Vector2f _velocity;
	Vector2f _acceleration;

	bool _isVisible;
public:

	Obstacles();
	~Obstacles();

	void Update(float deltaTime);
	void Draw(RenderWindow* _wnd);
	void SetVisible(bool visible);
	void SetPosition(Vector2f pos);
	void SetVelocity(Vector2f vel);
	void SetAcceleration(Vector2f acc);
	void AddAcceleration(Vector2f acc);

	Vector2f GetPosition();
	Vector2f GetVelocity();
	Vector2f GetAcceleration();

	bool isActive();
};
