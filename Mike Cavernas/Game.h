#include "Stadx.h"
#include "Backgrounds.h"
#include "Obstacles.h"
#include "Mike.h"
#include "PointUp.h"

class Game 
{
private:

	RenderWindow* _wnd;
	Backgrounds* _cave;
	Backgrounds* _landscape;
	Backgrounds* _rockPath;
	Obstacles* _estala;
	Mike* _mike;
	PointUp* _chicken;

	Sprite _startSp, _resetSp;
	Texture _starTx, _resetTx;

	Font _font;
	Text _lifesText;
	Text _pointsText;

	void ProcessEvents();
	void Update(float deltaTime);
	void Draw();
	void CheckCollision();
	void GameOver();
	void RestartGame();

	int UpdateLifes();
	int UpdatePoints();

	bool _gameStarted;
	bool _gameOver;
	bool _restartGame;
public:

	Game();
	~Game();

	void Go();
};