#include "Item.h"

Item::Item() 
{

	_chickenTx.loadFromFile("Asset/Images/Chicken.png");
	_chickenSp.setTexture(_chickenTx);
	_chickenSp.setOrigin(_chickenTx.getSize().x / 2, 0);

	_keyTx.loadFromFile("Asset/Images/Key.png");
	_keySp.setTexture(_keyTx);
	_keySp.setOrigin(_keyTx.getSize().x / 2, 0);

	_position.x = 0.0f;
	_position.y = 0.0f;
	_keyPosition.x = 0.0f;
	_keyPosition.y = 0.0f;
}

Item::~Item() 
{

}

void Item::Update(float deltaTime) 
{

	_chickenSp.setPosition(_position);
	_keySp.setPosition(_keyPosition);
}

void Item::Draw(RenderWindow* _wnd)
{

	_wnd->draw(_chickenSp);
	_wnd->draw(_keySp);
}

void Item::SetVisible(bool chicken_visible)
{

	_isChickenVisible = chicken_visible;
}

void Item::SetKeyVisible(bool key_visible)
{

	_isKeyVisible = key_visible;
}

void Item::SetPosition(Vector2f pos) 
{

	_position = pos;
}

void Item::SetKeyPosition(Vector2f keyPos)
{

	_keyPosition = keyPos;
}

Vector2f Item::GetPosition()
{

	return _position;
}

Vector2f Item::GetKeyPosition()
{

	return _keyPosition;
}

bool Item::IsActive()
{

	return _isChickenVisible;
}

bool Item::IsKeyActive()
{

	return _isKeyVisible;
}

