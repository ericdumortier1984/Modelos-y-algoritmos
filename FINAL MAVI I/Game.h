#include "stdafx.h"
#include "Menu.h"

class Game {
private:
	RenderWindow* MENU; 
	MainMenu* mainMenu;

	void ProcessEvents();
	void UpdateGame(float deltaTime);
	void DrawGame();
public:
	Game();
	~Game();

	void Play();
};
