#include "OrangeBall.h"

OrangeBall::OrangeBall() {
	texture.loadFromFile("Asset/ocircle.png");
	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setScale(0.5f, 0.5f);
}

OrangeBall::~OrangeBall() {

}

void OrangeBall::SetPosition(Vector2f pos) {
	_randomX = rand() % 750;
	_position.x = _randomX;
	_position.y = pos.y;
}
