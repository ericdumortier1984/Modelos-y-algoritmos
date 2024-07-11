#include "Game.h"

Game::Game() 
{

	_wnd = new RenderWindow(VideoMode(800, 600), "Wild Gunman");
	_fps = 60;
	_wnd->setFramerateLimit(_fps);
	_wnd->setMouseCursorVisible(false);

	_inst_Screen = new InstructionScreen;
	crosshair = new Player;
	
	// Variables de inicio //
	_score = 0, _lifes = 3;
	_GameOver = false;
	_YouWin = false;
	_ShowBang = false;

	// Cargamos textura saloon //
	saloonTexture = new Texture;
	saloon = new Sprite;
	saloonTexture->loadFromFile("Assets/imagenes/saloon.png");
	saloon->setTexture(*saloonTexture);
	saloon->setPosition(0.0, 100.0);

	// Cargamos fuentes //
	_font.loadFromFile("Assets/font/RioGrande.ttf");
	_textScore.setFont(_font);
	_textScore.setString("Score: 0");
	_textScore.setFillColor(Color::Magenta);
	_textScore.setPosition(20, 550);
	_textLifes.setFont(_font);
	_textLifes.setString("Lifes: 3");
	_textLifes.setFillColor(Color::Magenta);
	_textLifes.setPosition(650, 550);
	_textGameOver.setFont(_font);
	_textGameOver.setString("GameOver");
	_textGameOver.setFillColor(Color::Black);
	_textGameOver.setCharacterSize(42);
	_textGameOver.setPosition(300, 500);
	_textWin.setFont(_font);
	_textWin.setString("You Win ENTER para reiniciar");
	_textWin.setCharacterSize(32);
	_textWin.setPosition(180, 50);
	_textWin.setFillColor(Color::Green);
	_textFinalScore.setFont(_font);
	_textFinalScore.setString("Final Score: ");
	_textFinalScore.setCharacterSize(50);
	_textFinalScore.setPosition(230, 550);
	_textFinalScore.setFillColor(Color::Yellow);

	InitEnemies();
}

void Game::Loop() 
{

	_inst_Screen->Show(_wnd); // Primero va la pantalla de inicio //

	while (_wnd->isOpen()) 
	{
		Events();
		GameOverConditions();
		DrawGame();
	}
}

void Game::Events() 
{

	Event evt;
	while (_wnd->pollEvent(evt)) 
	{
		switch (evt.type) 
		{
		case Event::Closed:
			_wnd->close();
			break;
		case Event::MouseMoved:
			crosshair->SetPosition(evt.mouseMove.x, evt.mouseMove.y);
			break;
		case Event::MouseButtonPressed:
			if (evt.mouseButton.button == Mouse::Button::Left) 
			{
				CheckCollision();
			}
			break;
		case Event::KeyPressed:
			if (evt.key.code == Keyboard::Escape)
			{
				_wnd->close();
			}
			if (evt.key.code == Keyboard::Enter && _YouWin)
			{
				RestartGame();
			}
			break;
		default:
			break;
		}
	}
}

void Game::InitEnemies()
{

	enemies.push_back(new Enemy("Assets/imagenes/Innocent.png", windowSaloonPos[0], true));
	enemies.push_back(new Enemy("Assets/imagenes/Enemy1.png", windowSaloonPos[1], false));
	enemies.push_back(new Enemy("Assets/imagenes/Enemy2.png", windowSaloonPos[2], false));
	enemies.push_back(new Enemy("Assets/imagenes/Enemy3.png", windowSaloonPos[3], false));
}

void Game::GameOverConditions() 
{
	if (_GameOver || _YouWin)
	{
		return; // Si es Game Over o You Win, listo! //
		
		if (_score == 10)
		{
			_YouWin = true;
			FinalScore();
		}
		if (_lifes == 0) 
		{
			_GameOver = true;
			FinalScore();
		}
	}
}

void Game::LifeUpdate()
{
	_textLifes.setString("Lifes: " + to_string(_lifes));
}

void Game::ScoreUpdate() 
{
	_textScore.setString("Score: " + to_string(_score));
}

void Game::FinalScore() 
{
	_textFinalScore.setString("Final Score: " + to_string ((_score - (3 - _lifes)) * 10));
}

void Game::CheckCollision() 
{
	Vector2f playerPos = crosshair->Getpos();

	ScoreUpdate();
	LifeUpdate();
}

void Game::ShotAtPlayer()
{
    _ShowBang = true;
	_lifes-- && _score--;
	LifeUpdate();
	ScoreUpdate();
}

void Game::DrawGame()
{
	_wnd->clear();

	for (Enemy* _enemies : enemies)
	{
		_enemies->Draw(_wnd);
	}
	_wnd->draw(*saloon);
	crosshair->Draw(_wnd);
	
	if (_GameOver) 
	{
		_wnd->draw(_textGameOver);
		_wnd->draw(_textFinalScore);
		_wnd->setMouseCursorVisible(true);
	}

	else if (_YouWin) 
	{
		_wnd->draw(_textWin);
		_wnd->draw(_textFinalScore);
	}

	_wnd->draw(_textScore);
	_wnd->draw(_textLifes);
	_wnd->display();
}

void Game::RestartGame()
{
	// Restablecemos variables del juego //
	_wnd->setMouseCursorVisible(false);
	_score = 0;
	_lifes = 3;
	_GameOver = false;
	_YouWin = false;
	_ShowBang = false;
	
	ScoreUpdate();
	LifeUpdate();
	FinalScore();
}

Game::~Game() 
{

	delete crosshair;
	delete saloon;
	delete saloonTexture;
	delete _wnd;
}
