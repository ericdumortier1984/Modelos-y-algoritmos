#pragma once
#include "Include&using.h"
#include "Player.h"
#include "InstructionScreen.h"
#include "Enemy.h"

class Game 
{
private:

	const Vector2f windowSaloonPos[5] =
	{
	Vector2f(140.0, 150.0), // Ventana 1
	Vector2f(600.0, 150.0), // Ventana 2
	Vector2f(120.0, 350.0), // Ventana 3
	Vector2f(620.0, 350.0), // Ventana 4
	Vector2f(370.0, 350.0), // Puerta
	};
	RenderWindow* _wnd;
	Player* crosshair;
	vector<Enemy*> enemies;
	InstructionScreen* _inst_Screen;
	Sprite* saloon;
	Texture* saloonTexture;

	Text _textScore, _textLifes, _textGameOver, _textWin, _textFinalScore;
	Font _font;

	int _score, _lifes, _fps;

	bool _GameOver; 
	bool _YouWin;
	bool _ShowBang;
	
public:

	Game();
	~Game();

	void Loop();
	void Events();
	void GameOverConditions();
	void CheckCollision();
	void ShotAtPlayer();
	void InitEnemies();
	void DrawGame();
	void RestartGame();
	void ScoreUpdate();
	void LifeUpdate();
	void FinalScore();
};

