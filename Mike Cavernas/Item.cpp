#include "Item.h"

Item::Item()
{

	_chickenTx.loadFromFile("Asset/Images/Chicken.png");
	_chickenSp.setTexture(_chickenTx);
	_chickenSp.setOrigin(_chickenTx.getSize().x / 2, 0);

	_position.x = 0.0f;
	_position.y = 0.0f;
}

Item::~Item() 
{

}

void Item::Update(float deltaTime)
{

	_chickenSp.setPosition(_position);
}

void Item::Draw(RenderWindow* _wnd)
{

	_wnd->draw(_chickenSp);
}

void Item::SetVisible(bool chicken_visible)
{

	_isChickenVisible = chicken_visible;
}

void Item::SetPosition(Vector2f pos) 
{

	_position = pos;
}

Vector2f Item::GetPosition()
{

	return _position;
}

bool Item::IsActive()
{

	return _isChickenVisible;
}


