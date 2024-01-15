#include "Stadx.h"

class Menu
{
private:

	Sprite _cursorSp, _startSp;
	Texture _cursorTx, _startTx;
public:

	Menu();
	~Menu();

	void Draw(RenderWindow* _wnd);
	void CursorSetPosition(float x, float y);
	Vector2f CursorGetPosition();

	bool GetStartPressed(float x, float y);
};
