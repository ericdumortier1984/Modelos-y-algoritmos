#include "Player.h"

Player::Player() {
	playerTexture.loadFromFile("Assets/imagenes/puntoDeMira.png");
	playerSprite.setTexture(playerTexture);
	playerSprite.setScale(0.10f, 0.10f);
	playerTexture.setSmooth(true);
	Vector2u size = playerTexture.getSize();
	playerSprite.setOrigin(size.x / 2.0f, size.y / 2.0f);
}
void Player::Draw(RenderWindow* _wnd) {
	_wnd->draw(playerSprite);
}
void Player::SetPosition(float x, float y) {
	playerSprite.setPosition(x, y);
}
Vector2f Player::Getpos() {
	return playerSprite.getPosition();
}

