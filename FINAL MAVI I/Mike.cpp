#include "Mike.h"

Mike::Mike(float width, float height) {
	int _lifes = lifes;
	mikeTx.loadFromFile("Asset/Images/Mike.png");
	mikeTx.setSmooth(true);
	mikeSp.setTexture(mikeTx);
	mikeSp.setScale(1.0f, 1.0f);
	position.x = 0.0f;
	position.y = 0.0f;
	acceleration.x = 0.0f;
	acceleration.y = 0.0f;
	velocity.x = 0.0f;
	velocity.y = 0.0f;
}

Mike::~Mike() {

}

void Mike::Draw(RenderWindow* window) {
	window->draw(mikeSp);
}

void Mike::UpdateMike(float deltaTime) {
	position.x += velocity.x * deltaTime;
	position.y += velocity.y * deltaTime;
	velocity.x += acceleration.x * deltaTime;
	velocity.y += acceleration.y * deltaTime;
	acceleration.x = 0.0f;
	acceleration.y = 0.0f;
	mikeSp.setPosition(position);
}

void Mike::AddAcceleration(Vector2f Acc) {
	acceleration.x += Acc.x;
	acceleration.y += Acc.y;
}

void Mike::SetPosition(Vector2f Pos) {
	position = Pos;
}

void Mike::SetVelocity(Vector2f Vel) {
	velocity = Vel;
}

void Mike::SetAcceleration(Vector2f Acc) {
	acceleration = Acc;
}

Vector2f Mike::GetAcceleration() {
	return acceleration;
}

Vector2f  Mike::GetVelocity() {
	return velocity;
}

Vector2f Mike::GetPosition() {
	return position;
}

void Mike::LoseLife() {
	lifes--;
}

int Mike::GetLife() {
	return lifes;
}
