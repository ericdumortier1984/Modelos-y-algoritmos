#include "Stadx.h"

class Select
{
private:

	Sprite _cursorSp;
	Texture _cursorTx;

	Sprite _startSp, _resetSp;
	Texture _startTx, _resetTx;
public:

	Select();
	~Select();

	void Draw(RenderWindow* _wnd);
	void CursorSetPosition(float x, float y);
	Vector2f CursorGetPosition();

	bool GetStartPressed(float x, float y);
	bool GetResetPressed(float x, float y);

};
