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
	Menu* _start;
	Menu* _game_over;

	Sprite _cave, _path, _landscape, _stair, _level;
	Texture _caveTx, _pathTx, _landscapeTx, _stairTx, _levelTx;

	Music _musicPrincipal, _musicLevel, _musicGameOver;

	SoundBuffer _woohooBf, _dohBf;
	Sound _woohoo, _doh;

	Font _font;
	Text _lifesText, _pointsText, _titleText; 
	
	void ProcessEvents();
	void Update(float deltaTime);
	void Draw();
	void CheckCollision();
	void RespawnChicken();
	void RespawnEstala();
	void RespawnPtero();
	void RestartGame();
	void WinGame();

	int UpdateLifes();
	int UpdatePoints();

	float _randomX;

	bool _gameStarted;
	bool _restartGame;
	bool _youWin;
public:

	Game();
	~Game();

	void Go();
};