#include "Mike.h"

Mike::Mike(int lifes) {

	_mikeTx.loadFromFile("Asset/Images/Mike.png");
	_mikeSp.setTexture(_mikeTx);

	_lifes = lifes;

	_position.x = 0.0f;
	_position.y = 0.0f;
	_velocity.x = 0.0f;
	_velocity.y = 0.0f;
	_acceleration.x = 0.0f;
	_acceleration.y = 0.0f;
}

Mike::~Mike() {

}

void Mike::Update(float deltaTime) {

	_mikeSp.setPosition(_position);
	_position.x += _velocity.x * deltaTime;
	_position.y += _velocity.y * deltaTime;
	_velocity.x += _acceleration.x * deltaTime;
	_velocity.y += _acceleration.y * deltaTime;
	_acceleration.x = 0.0f;
	_acceleration.y = 0.0f;
}

void Mike::AddAcceleration(Vector2f acc) {

	_acceleration.x += acc.x;
	_acceleration.y += acc.y;
}

void Mike::Draw(RenderWindow* _wnd) {

	_wnd->draw(_mikeSp);
}

void Mike::Pricked() {

	float x = _mikeSp.getPosition().x;
	float y = _mikeSp.getPosition().y;

	if (GetPricked(x, y)) {
		_lifes--;
	}
}

void Mike::SetPosition(Vector2f pos) {

	_position = pos;
}

void Mike::SetVelocity(Vector2f vel) {

	_velocity = vel;
}

void Mike::SetAcceleration(Vector2f acc) {

	_acceleration = acc;
}

Vector2f Mike::GetPosition() {

	return _position;
}

Vector2f Mike::GetVelocity() {

	return _velocity;
}

Vector2f Mike::GetAcceleration() {

	return _acceleration;
}

bool Mike::GetPricked(float x, float y) {

	FloatRect bounds = _mikeSp.getGlobalBounds();
	return bounds.contains(x, y);
}

int Mike::GetLifes() {

	return _lifes;
}