#include "GreyBall.h"

GreyBall::GreyBall() {
	texture.loadFromFile("Asset/gycircle.png");
	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setScale(0.5f, 0.5f);
}

GreyBall::~GreyBall() {

}

void GreyBall::SetPosition(Vector2f pos) {
	_randomX = rand() % 750;
	_position.x = _randomX;
	_position.y = pos.y;
}
