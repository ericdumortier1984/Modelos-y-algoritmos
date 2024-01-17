#include "Stadx.h"
#include "Obstacles.h"
#include "Mike.h"
#include "Item.h"
#include "Menu.h"

class Game 
{
private:

	RenderWindow* _wnd;
	Obstacles* _estala;
	Obstacles* _ptero;
	Mike* _mike;
	Item* _chicken;
	Menu* _cursor;
	Menu* _start;

	Sprite _cave, _path, _landscape, _stair, _level;
	Texture _caveTx, _pathTx, _landscapeTx, _stairTx, _levelTx;

	Music _musicPrincipal;
	Music _musicLevel;

	SoundBuffer _woohooBf, _dohBf;
	Sound _woohoo, _doh;

	Font _font;
	Text _lifesText, _pointsText, _titleText; 
	
	void ProcessEvents();
	void Update(float deltaTime);
	void Draw();
	void CheckCollision();
	void RespawnChicken();
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