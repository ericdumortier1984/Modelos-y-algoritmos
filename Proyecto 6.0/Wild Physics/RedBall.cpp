#include "RedBall.h"

RedBall::RedBall() {
	texture.loadFromFile("Asset/rcircle.png");
	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setScale(0.5f, 0.5f);
}

RedBall::~RedBall() {

}

void RedBall::SetPosition(Vector2f pos) {
	_randomX = rand() % 750;
	_position.x = _randomX;
	_position.y = pos.y;
}
