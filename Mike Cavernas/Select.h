#include "Stadx.h"

class Select
{
private:

	Sprite _cursorSp;
	Texture _cursorTx;
public:

	Select();
	~Select();

	void Draw(RenderWindow* _wnd);
	void CursorSetPosition(float x, float y);
	Vector2f CursorGetPosition();

};
