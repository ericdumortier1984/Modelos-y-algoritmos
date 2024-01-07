#include "Obstacles.h"

Obstacles::Obstacles() {

	_estalaTx.loadFromFile("Asset/Images/Estala.png");
	_estalaSp.setTexture(_estalaTx);
	_estalaSp.setPosition(50.0f, -30.0f);
}

Obstacles::~Obstacles() {

}

void Obstacles::Draw(RenderWindow* _wnd) {

	_wnd->draw(_estalaSp);
}

