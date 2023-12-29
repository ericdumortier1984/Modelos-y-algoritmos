#include "YellowBall.h"

YellowBall::YellowBall() {
	texture.loadFromFile("Asset/ycircle.png");
	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setScale(0.5f, 0.5f);
}

YellowBall::~YellowBall() {

}

void YellowBall::SetPosition(Vector2f pos) {
	_randomX = rand() % 750;
	_position.x = _randomX;
	_position.y = pos.y;
}
