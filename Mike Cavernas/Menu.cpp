#include "Menu.h"

Menu::Menu()
{
	_cursorTx.loadFromFile("Asset/Images/Cursor_hammer.png");
	_cursorTx.setSmooth(true);
	_cursorSp.setTexture(_cursorTx);
	Vector2u size = _cursorTx.getSize();
	_cursorSp.setOrigin(size.x / 2.0f, size.y / 2.0f);
}

Menu::~Menu()
{

}

void Menu::Draw(RenderWindow* _wnd) 
{

	_wnd->draw(_cursorSp);
}


void Menu::CursorSetPosition(float x, float y)
{

	_cursorSp.setPosition(x, y);
}

Vector2f Menu::CursorGetPosition()
{

	return _cursorSp.getPosition();
}


