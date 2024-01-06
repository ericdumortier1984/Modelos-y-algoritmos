#include "Crosshair.h"

Crosshair::Crosshair() {
	crosshair_tx.loadFromFile("Asset/crosshair.png");
	crosshair_tx.setSmooth(true);
	crosshair.setTexture(crosshair_tx);
}

Crosshair::~Crosshair() {

}

void Crosshair::Draw(RenderWindow* _wnd) {
	_wnd->draw(crosshair);
}

void Crosshair::SetPosition(float x, float y) {
	crosshair.setPosition(x, y);
}

void Crosshair::SetOrigin() {
	Vector2u size = crosshair_tx.getSize();
	crosshair.setOrigin(size.x/2.0f, size.y/2.0f);
}

Vector2f Crosshair::Getposition() {
	return crosshair.getPosition();
}