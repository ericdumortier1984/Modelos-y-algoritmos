#include "stdafx.h"
#include "Menu.h"
//#include "Mike.h"

class Game {
private:
	//Ventana principal
	RenderWindow* MENU; 
	//Opciones de Menu
	MainMenu* mainMenu;
	//Personaje
	Sprite mikeSp;
	Texture mikeTx;
	int lifes;
	//Obstaculos
	Sprite wheelSp;
	Texture wheelTx;
	//Fondos
	Sprite fondoPlaySp;
	Texture fondoPlayTx;
	Sprite moonSp;
	Texture moonTx;
	Sprite caminoSp;
	Texture caminoTx;
	Sprite pastoSp;
	Texture pastoTx;
	Sprite paisajeSp;
	Texture paisajeTx;
	Sprite cavermanOneSp;
	Texture cavermanOneTx;
	//Musica y Sonidos
	Music music;

	void ProcessEvents();
	void Update(float deltaTime);
	void DrawGame();
public:
	Game();
	~Game();

	void Go();
};
