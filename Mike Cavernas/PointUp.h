#include "Stadx.h"

class PointUp {
private:

	Sprite _chickenSp;
	Texture _chickenTx;

	Vector2f _position;

	int _points;
	float x;
	float y;

	bool _isChickenVisible;

public:

	PointUp(int points);
	~PointUp();

	void Draw(RenderWindow* _wnd);
	void SetVisible(bool chicken_visible);
	void SetPointUp();
	void SetPosition(Vector2f pos);
	
	Vector2f GetPosition();

	bool GetChicken(float x, float y);
	bool IsActive();
	int GetPoints();
};
