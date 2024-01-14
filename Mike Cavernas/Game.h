#include "Stadx.h"
#include "Backgrounds.h"
#include "Obstacles.h"
#include "Mike.h"
#include "Item.h"
#include "Menu.h"

class Game 
{
private:

	RenderWindow* _wnd;
	Backgrounds* _cave;
	Backgrounds* _landscape;
	Backgrounds* _rockPath;
	Obstacles* _estala;
	Mike* _mike;
	Item* _chicken;
	Menu* _cursor;
	Menu* _start;
	Menu* _reset;

	Music _music;

	Font _font;
	Text _lifesText;
	Text _pointsText;
	
	void ProcessEvents();
	void Update(float deltaTime);
	void Draw();
	void CheckCollision();
	void RespawnChicken();
	void GameOver();
	void RestartGame();

	int UpdateLifes();
	int UpdatePoints();

	float _randomX;

	bool _gameStarted;
	bool _gameOver;
	bool _restartGame;
public:

	Game();
	~Game();

	void Go();
};