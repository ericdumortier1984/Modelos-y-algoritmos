#include "Item.h"

Item::Item(int points) 
{

	_chickenTx.loadFromFile("Asset/Images/Chicken.png");
	_chickenSp.setTexture(_chickenTx);

	_points = points;

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

void Item::SetPointUp()
{

	float x = _chickenSp.getPosition().x;
	float y = _chickenSp.getPosition().y;

	if (GetChicken(x, y)) {
		_points += 50;
	}
}

void Item::SetPosition(Vector2f pos) 
{

	_position = pos;
}

Vector2f Item::GetPosition()
{

	return _position;
}

bool Item::GetChicken(float x, float y) 
{

	FloatRect bounds_chicken = _chickenSp.getGlobalBounds();
	return bounds_chicken.contains(x, y);
}

bool Item::IsActive()
{

	return _isChickenVisible;
}

int Item::GetPoints() 
{

	return _points;
}
