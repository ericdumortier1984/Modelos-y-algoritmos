#include "stdafx.h"

class Background {
public:
	Background();
	//Fondos
	Sprite fondoPlaySp;
	Texture fondoPlayTx;
	Sprite caminoSp;
	Texture caminoTx;
	Sprite pastoSp;
	Texture pastoTx;
	Sprite paisajeSp;
	Texture paisajeTx;
	Sprite cavermanOneSp;
	Texture cavermanOneTx;

	void Draw(RenderWindow* _wnd);
};
