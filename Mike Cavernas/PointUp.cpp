#include "PointUp.h"

PointUp::PointUp(int points) {

	_chickenTx.loadFromFile("Asset/Images/Chicken.png");
	_chickenSp.setTexture(_chickenTx);
	_chickenSp.setPosition(Vector2f(120.0f, 520.0f));

	_points = points;
}

PointUp::~PointUp() {

}

void PointUp::Draw(RenderWindow* _wnd) {

	_wnd->draw(_chickenSp);
}

void PointUp::SetVisible(bool chicken_visible) {

	_isChickenVisible = chicken_visible;
}

void PointUp::SetPointUp() {

	float x = _chickenSp.getPosition().x;
	float y = _chickenSp.getPosition().y;

	if (GetChicken(x, y)) {
		_points += 50;
	}
}

void PointUp::SetPosition(Vector2f pos) {

	_position = pos;
}

Vector2f PointUp::GetPosition() {

	return _position;
}

bool PointUp::GetChicken(float x, float y) {

	FloatRect bounds_chicken = _chickenSp.getGlobalBounds();
	return bounds_chicken.contains(x, y);
}

bool PointUp::IsActive() {

	return _isChickenVisible;
}

int PointUp::GetPoints() {

	return _points;
}
