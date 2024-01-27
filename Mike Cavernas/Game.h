#include "Stadx.h"
#include "Pterodactile.h"
#include "Estalactita.h"
#include "Mike.h"
#include "Item.h"
#include "Key.h"
#include "Menu.h"

class Game 
{
private:

	RenderWindow* _wnd;
	Estalactita* _estala;
	Pterodactile* _ptero;
	Mike* _mike;
	Item* _chicken;
	Key* _key;
	Menu* _cursor;

	Sprite _cave, _path, _landscape, _stair, _level, _winBackground, _loseBackground, _sign, _startButton, _infoButton, _gameOverSign;
	Texture _caveTx, _pathTx, _landscapeTx, _stairTx, _levelTx, _winBackgroundTx, _loseBackgroundTx, _signTx, _startTx, _infoTx, _gameOverSignTx;

	Music _musicPrincipal, _musicLevel, _musicGameOver, _musicWinner;

	SoundBuffer _woohooBf, _dohBf;
	Sound _woohoo, _doh;

	Font _font;
	Text _lifesText, _pointsText, _titleText, _winText, _winnerText, _hiScoreText, _loseText, _signTextOne, _signTextTwo, _pauseText, _restartText;
	
	void ProcessEvents();
	void Update(float deltaTime);
	void Draw();
	void CheckCollision();
	void RespawnChicken();
	void RespawnEstala();
	void RespawnPtero();
	void RespawnKey();
	void RestartGame();
	void GamePause();
	void GameOver();
	void YouWin();
	void ShowInfoScreen();
	void ShowGameOverScreen();
	void ShowWinnerScreen();

	int UpdateLifes();
	int UpdatePoints();

	float _randomX;

	bool GetStartPressed(float x, float y);
	bool GetInfoPressed(float x, float y);
	bool _gameStarted;
	bool _restartGame;
	bool _gameOver;
	bool _youWin;
public:

	Game();
	~Game();

	void Go();
};