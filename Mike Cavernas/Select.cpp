#include "Select.h"

Select::Select()
{
	_cursorTx.loadFromFile("Asset/Images/Cursor.png");
	_cursorTx.setSmooth(true);
	_cursorSp.setTexture(_cursorTx);
	Vector2u size = _cursorTx.getSize();
	_cursorSp.setOrigin(size.x / 2.0f, size.y / 2.0f);

	_startTx.loadFromFile("Asset/Images/Start.png");
	_startTx.setSmooth(true);
	_startSp.setTexture(_startTx);
	_startSp.setPosition(300.0f, 0.0f);

	_resetTx.loadFromFile("Asset/Images/reset.png");
	_resetTx.setSmooth(true);
	_resetSp.setTexture(_resetTx);
	_resetSp.setPosition(400.0f, 0.0f);
}

Select::~Select()
{

}

void Select::Draw(RenderWindow* _wnd) 
{

	_wnd->draw(_resetSp);
	_wnd->draw(_startSp);
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

bool Select::GetStartPressed(float x, float y)
{

	FloatRect bounds_startSp = _startSp.getGlobalBounds();
	return bounds_startSp.contains(x, y);
}

bool Select::GetResetPressed(float x, float y)
{

	FloatRect bounds_resetSp = _resetSp.getGlobalBounds();
	return bounds_resetSp.contains(x, y);
}
