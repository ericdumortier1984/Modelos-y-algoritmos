#include "Player.h"

Player::Player(int lf) {
	int lifes = lf;
	mikeTx.loadFromFile("Asset/Images/cavernicola.png");
	mikeTx.setSmooth(true);
	mikeSp.setTexture(mikeTx);

	position.x = 0.0f;
	position.y = 0.0f;
	acceleration.x = 0.0f;
	acceleration.y = 0.0f;
	velocity.x = 0.0f;
	velocity.y = 0.0f;
}

Player::~Player() {
	
}

void Player::Draw(RenderWindow* wnd) {
	wnd->draw(mikeSp);
}

void Player::UpdatePlayer(float deltaTime) {
	position.x += velocity.x * deltaTime;
	position.y += velocity.y * deltaTime;
	velocity.x += acceleration.x * deltaTime;
	velocity.y += acceleration.y * deltaTime;
	acceleration.x = 0.0f;
	acceleration.y = 0.0f;
	mikeSp.setPosition(position);
}

void Player::AddAcceleration(Vector2f Acc) {
	acceleration.x += Acc.x;
	acceleration.y += Acc.y;
}

void Player::SetPosition(Vector2f Pos) {
	position = Pos;
}

void Player::SetVelocity(Vector2f Vel) {
	velocity = Vel;
}

void Player::SetAcceleration(Vector2f Acc) {
	acceleration = Acc;
}

Vector2f Player::GetAcceleration() {
	return acceleration;
}

Vector2f Player::GetVelocity() {
	return velocity;
}

Vector2f Player::GetPosition() {
	return position;
}

void Player::LoseLife() {
	 lifes--;
}

int Player::GetLife() {
	return lifes;
}

