#include "Backgrounds.h"

Backgrounds::Backgrounds() {
	//Fondos
	fondoPlayTx.loadFromFile("Asset/Images/cueva.png");
	fondoPlaySp.setTexture(fondoPlayTx);
	moonTx.loadFromFile("Asset/Images/lunavioleta.png");
	moonSp.setTexture(moonTx);
	moonSp.setPosition(180.0f, 280.0f);
	caminoTx.loadFromFile("Asset/Images/camino.png");
	caminoSp.setTexture(caminoTx);
	caminoSp.setPosition(50.0f, 650.0f);
	pastoTx.loadFromFile("Asset/Images/pasto.png");
	pastoSp.setTexture(pastoTx);
	pastoSp.setPosition(50.0f, 550.0f);
	paisajeTx.loadFromFile("Asset/Images/paisaje.png");
	paisajeSp.setTexture(paisajeTx);
	cavermanOneTx.loadFromFile("Asset/Images/cavernicola 6.png");
	cavermanOneSp.setTexture(cavermanOneTx);
	cavermanOneSp.setPosition(500.0f, 560.0f);
}