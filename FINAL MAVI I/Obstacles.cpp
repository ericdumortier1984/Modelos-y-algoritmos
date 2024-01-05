#include "Obstacles.h"

Obstacles::Obstacles() {
	wheelTx.loadFromFile("Asset/Images/rueda.png");
	wheelSp.setTexture(wheelTx);
	wheelSp.setPosition(20.0f, 650.0f);
	pincheTx.loadFromFile("Asset/Images/estala 2.png");
	pincheSp.setTexture(pincheTx);
	pincheTx.setSmooth(true);
	pincheSp.setPosition(100.0f, 20.0f);

	position.x = 0.0f;
	position.y = 0.0f;
	velocity.x = 0.0f;
	velocity.y = 0.0f;
	acceleration.x = 0.0f;
	acceleration.y = 0.0f;
}

Obstacles::~Obstacles() {

}

void Obstacles::Update(float deltaTime) {
	position.x += velocity.x * deltaTime;
	position.y += velocity.y * deltaTime;
	velocity.x += acceleration.x * deltaTime;
	velocity.y += acceleration.y * deltaTime;
	acceleration.x = 0.0f;
	acceleration.y = 0.0f;
}

void Obstacles::SetPosition(Vector2f pos) {
	position = pos;
}

void Obstacles::SetVelocity(Vector2f vel) {
	velocity = vel;
}

void Obstacles::SetAcceleration(Vector2f acc) {
	acceleration = acc;
}

void Obstacles::AddAcceleration(Vector2f acc) {
	acceleration.x += acc.x;
	acceleration.y += acc.y;
}

Vector2f Obstacles::GetPosition() {
	return position;
}

Vector2f Obstacles::GetVelocity() {
	return velocity;
}

Vector2f Obstacles::GetAcceleration() {
	return acceleration;
}
