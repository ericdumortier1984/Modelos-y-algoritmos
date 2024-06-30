#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Innocent.h"
#include "InstructionScreen.h"

using namespace sf;
using namespace std;

class Game {
private:
	RenderWindow* _wnd;
	Player* _player;
	Enemy* _enemy;
	Innocent* _innocent;
	InstructionScreen* _inst_Screen;
	Sprite _backScreen_Sp;
	Texture _backScreen_Tx;
	Sprite _bang;
	Texture _bang_Tx;
	Text _textScore, _textLifes, _textGameOver, _textWin, _textFinalScore;
	Font _font;
	int _score, _lifes;
	bool _GameOver; 
	bool _YouWin;
	bool _ShowBang;
	void ScoreUpdate();
	void LifeUpdate();
	void FinalScore();
	float _ShotTime;
	Clock _ShotClock;
public:
	Game();
	void Loop();
	void EventsUpdate();
	void GameUpdate();
	void CheckCollision();
	void ShotAtPlayer();
	void Draw();
	void RestartGame();
	~Game();

};

