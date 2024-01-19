#include "Menu.h"

Menu::Menu()
{
	_cursorTx.loadFromFile("Asset/Images/Cursor.png");
	_cursorTx.setSmooth(true);
	_cursorSp.setTexture(_cursorTx);
	Vector2u size = _cursorTx.getSize();
	_cursorSp.setOrigin(size.x / 2.0f, size.y / 2.0f);

	_startTx.loadFromFile("Asset/Images/Start.png");
	_startTx.setSmooth(true);
	_startSp.setTexture(_startTx);
	_startSp.setPosition(250.0f, 100.0f);

	_game_overTx.loadFromFile("Asset/Images/Game_over.png");
	_game_overTx.setSmooth(true);
	_game_overSp.setTexture(_game_overTx);
	_game_overSp.setPosition(250.0f, 300.0f);
}

Menu::~Menu()
{

}

void Menu::Draw(RenderWindow* _wnd) 
{
	_wnd->draw(_game_overSp);
	_wnd->draw(_startSp);
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

bool Menu::GetStartPressed(float x, float y)
{

	FloatRect bounds_startSp = _startSp.getGlobalBounds();
	return bounds_startSp.contains(x, y);
}

