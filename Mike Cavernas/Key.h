#include "Stadx.h"

class Key {
private:

	Sprite _keySp;
	Texture _keyTx;

	Vector2f _position;

	float x;
	float y;

	bool _isKeyVisible = false;

public:

	Key();
	~Key();

	void Update(float deltaTime);
	void Draw(RenderWindow* _wnd);
	void SetKeyVisible(bool key_visible);
	void SetPosition(Vector2f keyPos);

	Vector2f GetPosition();

	bool IsKeyActive();
};
