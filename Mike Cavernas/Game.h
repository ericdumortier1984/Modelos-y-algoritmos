#include "Stadx.h"
#include "Pterodactile.h"
#include "Estalactita.h"
#include "Mike.h"
#include "Item.h"
#include "Menu.h"

class Game 
{
private:

	RenderWindow* _wnd;
	Estalactita* _estala;
	Pterodactile* _ptero;
	Mike* _mike;
	Item* _chicken;
	Menu* _cursor;

	Sprite _cave, _path, _landscape, _stair, _level, _mikeWinner, _sign, _startButton;
	Texture _caveTx, _pathTx, _landscapeTx, _stairTx, _levelTx, _mikeWinnerTx, _signTx, _startTx;

	Music _musicPrincipal, _musicLevel, _musicGameOver;

	SoundBuffer _woohooBf, _dohBf;
	Sound _woohoo, _doh;

	Font _font;
	Text _lifesText, _pointsText, _titleText, _winText, _loseText, _signTextOne, _signTextTwo;
	
	void ProcessEvents();
	void Update(float deltaTime);
	void Draw();
	void CheckCollision();
	void RespawnChicken();
	void RespawnEstala();
	void RespawnPtero();
	void RestartGame();
	void GamePause();
	void GameOver();
	void YouWin();

	int UpdateLifes();
	int UpdatePoints();

	float _randomX;

	bool GetStartPressed(float x, float y);
	bool _gameStarted;
	bool _restartGame;
	bool _gameOver;
	bool _youWin;
public:

	Game();
	~Game();

	void Go();
};