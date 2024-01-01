#include "stdafx.h"
#include "Menu.h"
//#include "Mike.h"

class Game {
private:
	RenderWindow* MENU; 
	MainMenu* mainMenu;

	Sprite mikeSp;
	Texture mikeTx;

	Sprite fondoMenuSp;
	Texture fondoMenuTx;

	Sprite wheelSp;
	Texture wheelTx;

	Sprite fondoPlaySp;
	Texture fondoPlayTx;

	Music music;

	void ProcessEvents();
	//void UpdateGame(float deltaTime);
	void DrawGame();
public:
	Game();
	~Game();

	void Go();
};
