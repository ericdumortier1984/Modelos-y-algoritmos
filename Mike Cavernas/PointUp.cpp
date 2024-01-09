#include "PointUp.h"

PointUp::PointUp(int points) {

	_chickenTx.loadFromFile("Asset/Images/Chicken.png");
	_chickenSp.setTexture(_chickenTx);
	_chickenSp.setPosition(Vector2f(80.0f, 520.0f));

	_points = points;
}

PointUp::~PointUp() {

}

void PointUp::Draw(RenderWindow* _wnd) {

	_wnd->draw(_chickenSp);
}

void PointUp::SetPointUpVisible(bool chicken_visible) {

	_isChickenVisible = chicken_visible;
}

void PointUp::SetPointUp() {

	float x = _chickenSp.getPosition().x;
	float y = _chickenSp.getPosition().y;

	if (GetPointUp(x, y)) {
		_points + 50;
	}
}

void PointUp::SetPosition(Vector2f pos) {

	_position = pos;
}

Vector2f PointUp::GetPosition() {

	return _position;
}

bool PointUp::GetPointUp(float x, float y) {

	FloatRect bounds_chicken = _chickenSp.getGlobalBounds();
	return bounds_chicken.contains(x, y);
}

bool PointUp::IsPointUpActive() {

	return _isChickenVisible;
}

int PointUp::GetPoints() {

	return _points;
}
