#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Crosshair.h"
#include "Objetives.h"
#include "BlueBall.h"
#include "RedBall.h"
#include "GreenBall.h"
#include "GreyBall.h"
#include "OrangeBall.h"
#include "YellowBall.h"
using namespace std;

class Game {
private:
	RenderWindow* _wnd;
	Crosshair* _crosshair;
	RedBall* _redBall;
	BlueBall* _blueBall;
	GreenBall* _greenBall;
	GreyBall* _greyBall;
	OrangeBall* _orangeBall;
	YellowBall* _yellowBall;
	void Update(float deltaTime);
	void ProcessEvents();
	void ScoreUpdate();
	bool _gameOver;
	float randomX;
	int _score;
	Text _textScore;
	Text _textTitle;
	Text _textDone;
	Text _textWinner;
	Text _textLoser;
	Font _font;
public:
	Game();
	~Game();
	void Loop();
	void Draw();
	void CheckCollision();
};