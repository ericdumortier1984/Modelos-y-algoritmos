#include "Estalactita.h"

Estalactita::Estalactita()
{

	_estalaTx.loadFromFile("Asset/Images/Estala.png");
	_estalaSp.setTexture(_estalaTx);
	_estalaSp.setOrigin(_estalaTx.getSize().x / 2, _estalaTx.getSize().y / 2);

	_position.x = 0.0f;
	_position.y = 0.0f;
	_velocity.x = 0.0f;
	_velocity.y = 0.0f;
	_acceleration.x = 0.0f;
	_acceleration.y = 0.0f;
}

Estalactita::~Estalactita()
{


}

void Estalactita::Update(float deltaTime)
{

	_estalaSp.setPosition(_position);
	_position.x += _velocity.x * deltaTime;
	_position.y += _velocity.y * deltaTime;
	_velocity.x += _acceleration.x * deltaTime;
	_velocity.y += _acceleration.y * deltaTime;
	_acceleration.x = 0.0f;
	_acceleration.y = 0.0f;
}

void Estalactita::AddAcceleration(Vector2f acc) {

	_acceleration.x += acc.x;
	_acceleration.y += acc.y;
}

void Estalactita::Draw(RenderWindow* _wnd) {


	_wnd->draw(_estalaSp);
}

void Estalactita::SetVisible(bool visible) {

	_isVisible = visible;
}

void Estalactita::SetPosition(Vector2f pos) {

	_position = pos;
}

void Estalactita::SetVelocity(Vector2f vel) {

	_velocity = vel;
}

void Estalactita::SetAcceleration(Vector2f acc) {

	_acceleration = acc;
}

Vector2f Estalactita::GetPosition() {

	return _position;
}

Vector2f Estalactita::GetVelocity() {

	return _velocity;
}

Vector2f Estalactita::GetAcceleration() {

	return _acceleration;
}

bool Estalactita::isActive() {

	return _isVisible;
}
