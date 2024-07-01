#include "SaloonWindow.h"

SaloonWindow::SaloonWindow(int x, int y) 
{
	_position.x = x;
	_position.x = y;
}

Vector2i SaloonWindow::GetPos() 
{
	return _position;
}

void SaloonWindow::SetPosition(Vector2i position)
{
	_position = position;
}
