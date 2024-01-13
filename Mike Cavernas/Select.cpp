#include "Select.h"

Select::Select()
{
	_cursorTx.loadFromFile("Asset/Images/Cursor.png");
	_cursorSp.setTexture(_cursorTx);
	Vector2u size = _cursorTx.getSize();
	_cursorSp.setOrigin(size.x / 2.0f, size.y / 2.0f);
}

Select::~Select()
{

}

void Select::Draw(RenderWindow* _wnd) 
{

	_wnd->draw(_cursorSp);
}


void Select::CursorSetPosition(float x, float y)
{

	_cursorSp.setPosition(x, y);
}

Vector2f Select::CursorGetPosition()
{

	return _cursorSp.getPosition();
}