#include "Stadx.h"

class Menu
{
private:

	Sprite _cursorSp;
	Texture _cursorTx;
public:

	Menu();
	~Menu();

	void Draw(RenderWindow* _wnd);
	void CursorSetPosition(float x, float y);
	Vector2f CursorGetPosition();
};
