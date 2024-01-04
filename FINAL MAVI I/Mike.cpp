#include "Mike.h"

Mike::Mike() {
	//Personaje
	mikeTx.loadFromFile("Asset/Images/cavernicola.png");
	mikeTx.setSmooth(true);
	mikeSp.setTexture(mikeTx);
	mikeSp.setPosition(50.0f, 650.0f);
}