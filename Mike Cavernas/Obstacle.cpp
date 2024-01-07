#include "Obstacle.h"

Obstacle::Obstacle() {
	_obstacleTexture.loadFromFile("Asset/neumatico.png");
	_obstacleSprite.setTexture(_obstacleTexture);
}

Obstacle::~Obstacle(){

}

void Obstacle::Draw(RenderWindow* _wnd) {
	_wnd->draw(_obstacleSprite);
}

bool Obstacle::isAbove(float x, float y) {
	FloatRect bounds_obstacle = _obstacleSprite.getGlobalBounds();
	return bounds_obstacle.contains(x, y);
}

void Obstacle::UpdateObstacle(float deltaTime) {
	_position.x += _velocity.x * deltaTime;
	_position.y += _velocity.y * deltaTime;
	_velocity.x += _acceleration.x * deltaTime;
	_velocity.y += _acceleration.y * deltaTime;
	_acceleration.x = 0.0f;
	_acceleration.y = 0.0f;
	_obstacleSprite.setPosition(_position);
	_obstacleSprite.rotate(2.0f);
}

void Obstacle::AddAcceleration(Vector2f Acc) {
	_acceleration.x += Acc.x;
	_acceleration.y += Acc.y;
}

void Obstacle::SetPosition(Vector2f Pos) {
	_position = Pos;
}

void Obstacle::SetVelocity(Vector2f Vel) {
	_velocity = Vel;
}

void Obstacle::SetAcceleration(Vector2f Acc) {
	_acceleration = Acc;
}

Vector2f Obstacle::GetAcceleration() {
	return _acceleration;
}

Vector2f Obstacle::GetVelocity() {
	return _velocity;
}

Vector2f Obstacle::GetPosition() {
	return _position;
}