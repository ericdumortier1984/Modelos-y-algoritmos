#include"Backgrounds.h"

Backgrounds::Backgrounds() {

	_caveTx.loadFromFile("Asset/Images/Cave.png");
	_caveSp.setTexture(_caveTx);
	_caveSp.setPosition(0.0f, -80.0f);

}

Backgrounds::~Backgrounds() {

}

void Backgrounds::Draw(RenderWindow* _wnd) {

	_wnd->draw(_caveSp);
}