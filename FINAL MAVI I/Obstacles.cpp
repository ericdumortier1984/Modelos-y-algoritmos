#include "Obstacles.h"

Obstacles::Obstacles() {
	//Obstaculos
	wheelTx.loadFromFile("Asset/Images/rueda.png");
	wheelSp.setTexture(wheelTx);
	wheelSp.setPosition(20.0f, 650.0f);
}