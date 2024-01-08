#include "Obstacles.h"

Obstacles::Obstacles() {

	_estalaTx.loadFromFile("Asset/Images/Estala.png");
	_estalaSp.setTexture(_estalaTx);
	_estalaSp.setPosition(50.0f, -30.0f);

	_position.x = 0.0f;
	_position.y = 0.0f;
	_velocity.x = 0.0f;
	_velocity.y = 0.0f;
	_acceleration.x = 0.0f;
	_acceleration.y = 0.0f;
}

Obstacles::~Obstacles() {

}

void Obstacles::Update(float deltaTime) {

	_estalaSp.setPosition(_position);
	_position.x += _velocity.x * deltaTime;
	_position.y += _velocity.y * deltaTime;
	_velocity.x += _acceleration.x * deltaTime;
	_velocity.y += _acceleration.y * deltaTime;
	_acceleration.x = 0.0f;
	_acceleration.y = 0.0f;
}

void Obstacles::AddAcceleration(Vector2f acc) {

	_acceleration.x += acc.x;
	_acceleration.y += acc.y;
}

void Obstacles::Draw(RenderWindow* _wnd) {

	_wnd->draw(_estalaSp);
}

void Obstacles::SetVisible(bool visible) {

	isVisible = visible;
}

void Obstacles::SetPosition(Vector2f pos) {

	_position = pos;
}

void Obstacles::SetVelocity(Vector2f vel) {

	_velocity = vel;
}

void Obstacles::SetAcceleration(Vector2f acc) {

	_acceleration = acc;
}

Vector2f Obstacles::GetPosition() {

	return _position;
}

Vector2f Obstacles::GetVelocity() {

	return _velocity;
}

Vector2f Obstacles::GetAcceleration() {

	return _acceleration;
}

bool Obstacles::isActive() {

	return isVisible;
}
