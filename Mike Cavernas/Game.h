#include "stdafx.h"
#include "Player.h"
#include "Obstacle.h"
#include "Audio.h"
#include "Menu.h"
#include "Background.h"

class Game {
private:
	RenderWindow* wnd;
	Player* mike;
	MainMenu* menu;
	Background* fondoPlay;
	Background* camino;
	Background* pasto;
	Background* paisaje;
	Background* cavermanOne;

	Music music;

	void ProcessEvents();
	void UpdateGame(float deltaTime);
	void DrawGame();

	bool _gameStarted;
	bool _gameOver = false;

public:

	Game();
	~Game();

	void Go();
};
