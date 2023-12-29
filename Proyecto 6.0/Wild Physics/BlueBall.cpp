#include "BlueBall.h"

BlueBall::BlueBall() {
	texture.loadFromFile("Asset/bcircle.png");
	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setScale(0.5f, 0.5f);
}

BlueBall::~BlueBall() {

}

void BlueBall::SetPosition(Vector2f pos) {
	_randomX = rand() % 750;
	_position.y = pos.y;
	_position.x = _randomX;
}
