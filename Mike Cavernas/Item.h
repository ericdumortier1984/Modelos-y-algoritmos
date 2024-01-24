#include "Stadx.h"

class Item
{
private:

	Sprite _chickenSp;
	Texture _chickenTx;

	Vector2f _position;
	
	float x;
	float y;

	bool _isChickenVisible;

public:

	Item();
	~Item();

	void Update(float deltaTime);
	void Draw(RenderWindow* _wnd);
	void SetVisible(bool chicken_visible);
	void SetPosition(Vector2f pos);

	Vector2f GetPosition();

	bool IsActive();
};
