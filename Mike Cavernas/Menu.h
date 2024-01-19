#include "Stadx.h"

class Menu
{
private:

	Sprite _cursorSp, _startSp, _game_overSp;
	Texture _cursorTx, _startTx, _game_overTx;
public:

	Menu();
	~Menu();

	void Draw(RenderWindow* _wnd);
	void CursorSetPosition(float x, float y);
	Vector2f CursorGetPosition();

	bool GetStartPressed(float x, float y);
};
