#include "Objetives.h"

Objetives::Objetives() {
	_shotDown = false;
	_isAlive = true;
	_isVisible = true;
	_position.x = 0.0f;
	_position.y = 0.0f;
	_velocity.x = 0.0f;
	_velocity.y = 0.0f;
	_acceleration.x = 0.0f;
	_acceleration.y = 0.0f;
}

 Objetives::~Objetives() {

}

 void Objetives::Draw(RenderWindow* _wnd) {
	if (_isAlive && _isVisible) {
		_wnd->draw(sprite);
	}
}
	

void Objetives::Update(float deltaTime) {
	_position.x += _velocity.x * deltaTime;
	_position.y += _velocity.y * deltaTime;
	_velocity.x += _acceleration.x * deltaTime;
	_velocity.y += _acceleration.y * deltaTime;
	sprite.setPosition(_position);
	_acceleration.x = 0.0f;
	_acceleration.y = 0.0f;
}

void Objetives::AddAcceleration(Vector2f acc) {
	_acceleration.x += acc.x;
	_acceleration.y += acc.y;
}

void Objetives::SetPosition(Vector2f pos) {
	_position = pos;
}

void Objetives::SetVelocity(Vector2f vel) {
	_velocity = vel;
}

void Objetives::SetAcceleration(Vector2f acc) {
	_acceleration = acc;
}

Vector2f Objetives::GetAcceleration() {
	return _acceleration;
}

Vector2f Objetives::GetVelocity() {
	return _velocity;
}

Vector2f Objetives::GetPosition() {
	return _position;
}

bool Objetives::isAbove(float x, float y) {
	FloatRect bounds_sprite = sprite.getGlobalBounds();
	return bounds_sprite.contains(x, y);
}

bool Objetives::IsAlive() {
	return _isAlive;
}

bool Objetives::isInGame() {
	return _isAlive && _isVisible;
}

bool Objetives::ShotDown() {
	_isAlive = false;
	return _isAlive;
}