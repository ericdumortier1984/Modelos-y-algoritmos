#include "Stadx.h"

class Item
{
private:

	Sprite _chickenSp, _keySp;
	Texture _chickenTx, _keyTx;

	Vector2f _position;
	Vector2f _keyPosition;

	float x;
	float y;

	bool _isChickenVisible;
	bool _isKeyVisible;

public:

	Item();
	~Item();

	void Update(float deltaTime);
	void Draw(RenderWindow* _wnd);
	void SetVisible(bool chicken_visible);
	void SetKeyVisible(bool key_visible);
	void SetPosition(Vector2f pos);
	void SetKeyPosition(Vector2f keyPos);
	
	Vector2f GetPosition();
	Vector2f GetKeyPosition();

	bool IsActive();
	bool IsKeyActive();
};
