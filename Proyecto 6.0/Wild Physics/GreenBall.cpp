#include "GreenBall.h"

GreenBall::GreenBall() {
	texture.loadFromFile("Asset/gcircle.png");
	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setScale(0.5f, 0.5f);
}

GreenBall::~GreenBall() {

}

void GreenBall::SetPosition(Vector2f pos) {
	_randomX = rand() % 750;
	_position.x = _randomX;
	_position.y = pos.y;
}
