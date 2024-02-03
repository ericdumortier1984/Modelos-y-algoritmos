#include "Pterodactile.h"

Pterodactile::Pterodactile()
{

	_pteroTx.loadFromFile("Asset/Images/Ptero.png");
	_pteroSp.setTexture(_pteroTx);
	_pteroSp.setOrigin(_pteroTx.getSize().x / 2, _pteroTx.getSize().y / 2);

	_position.x = 0.0f;
	_position.y = 0.0f;
	_velocity.x = 0.0f;
	_velocity.y = 0.0f;
	_acceleration.x = 0.0f;
	_acceleration.y = 0.0f;
}

Pterodactile::~Pterodactile()
{

}

void Pterodactile::Update(float deltaTime)
{

	_pteroSp.setPosition(_position);

	_position.x += _velocity.x * deltaTime;
	_position.y += _velocity.y * deltaTime;
	_velocity.x += _acceleration.x * deltaTime;
	_velocity.y += _acceleration.y * deltaTime;
	_acceleration.x = 0.0f;
	_acceleration.y = 0.0f;
}
void Pterodactile::AddAcceleration(Vector2f acc) {

	_acceleration.x += acc.x;
	_acceleration.y += acc.y;
}

void Pterodactile::Draw(RenderWindow* _wnd) {

	_wnd->draw(_pteroSp);
}

void Pterodactile::SetVisible(bool visible) {

	_isVisible = visible;
}

void Pterodactile::SetPosition(Vector2f pos) {

	_position = pos;
}

void Pterodactile::SetVelocity(Vector2f vel) {

	_velocity = vel;
}

void Pterodactile::SetAcceleration(Vector2f acc) {

	_acceleration = acc;
}

Vector2f Pterodactile::GetPosition() {

	return _position;
}

Vector2f Pterodactile::GetVelocity() {

	return _velocity;
}

Vector2f Pterodactile::GetAcceleration() {

	return _acceleration;
}

bool Pterodactile::isActive() {

	return _isVisible;
}
