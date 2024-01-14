#include "Stadx.h"

class Menu
{
private:

	Sprite _cursorSp;
	Texture _cursorTx;

	Sprite _startSp, _resetSp;
	Texture _startTx, _resetTx;
public:

	Menu();
	~Menu();

	void Draw(RenderWindow* _wnd);
	void CursorSetPosition(float x, float y);
	Vector2f CursorGetPosition();

	bool GetStartPressed(float x, float y);
	bool GetResetPressed(float x, float y);

};
