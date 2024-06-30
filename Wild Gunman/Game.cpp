#include "Game.h"

Game::Game() {
	_wnd = new RenderWindow(VideoMode(780, 438, 32), "Wild Gunman");
	_inst_Screen = new InstructionScreen();
	_player = new Player();
	_enemy = new Enemy[20];
	_innocent = new Innocent[20];

	// Variables de inicio //
	_wnd->setMouseCursorVisible(false);
	_score = 0, _lifes = 3;
	_GameOver = false;
	_YouWin = false;
	_ShowBang = false;
	_ShotTime = 8.0f;
	_ShotClock.restart();

	// Cargamos textura saloon //
	_backScreen_Tx.loadFromFile("Assets/imagenes/saloon.png");
	_backScreen_Sp.setTexture(_backScreen_Tx);

	// Cargamos textura del disparo enemigo //
	_bang_Tx.loadFromFile("Assets/imagenes/Bang.png");
	_bang.setTexture(_bang_Tx);
	_bang.setScale(0.15f, 0.15f);
	_bang.setPosition(150, 150);

	// Cargamos fuentes //
	_font.loadFromFile("Assets/font/RioGrande.ttf");
	_textScore.setFont(_font);
	_textScore.setString("Score: 0");
	_textScore.setFillColor(Color::Magenta);
	_textScore.setPosition(0, 400);
	_textLifes.setFont(_font);
	_textLifes.setString("Lifes: 3");
	_textLifes.setFillColor(Color::Magenta);
	_textLifes.setPosition(350, 400);
	_textGameOver.setFont(_font);
	_textGameOver.setString("GameOver");
	_textGameOver.setFillColor(Color::Black);
	_textGameOver.setCharacterSize(42);
	_textGameOver.setPosition(300, 10);
	_textWin.setFont(_font);
	_textWin.setString("You Win ENTER para reiniciar");
	_textWin.setCharacterSize(32);
	_textWin.setPosition(180, 50);
	_textWin.setFillColor(Color::Green);
	_textFinalScore.setFont(_font);
	_textFinalScore.setString("Final Score: ");
	_textFinalScore.setCharacterSize(50);
	_textFinalScore.setPosition(230, 80);
	_textFinalScore.setFillColor(Color::Yellow);
}

void Game::Loop() {
	_inst_Screen->Show(_wnd); // Primero va la pantalla de inicio //
	while (_wnd->isOpen()) {
		EventsUpdate();
		GameUpdate();
		Draw();
	}
}

void Game::EventsUpdate() {
	Event evt;
	while (_wnd->pollEvent(evt)) {
		switch (evt.type) {
		case Event::Closed:
			_wnd->close();
			break;
		case Event::MouseMoved:
			_player->SetPosition(evt.mouseMove.x, evt.mouseMove.y);
			break;
		case Event::MouseButtonPressed:
			if (evt.mouseButton.button == Mouse::Button::Left) {
				CheckCollision();
			}
			break;
		case Event::KeyPressed:
			if (evt.key.code == Keyboard::Enter && _YouWin) {
					RestartGame();
				}
			break;
		default:
			break;
		}
	}
}

void Game::GameUpdate() {
	if (_GameOver || _YouWin) {
		return; // Si es Game Over o You Win, listo! //
	}
	for (int i = 0; i < 20; i++) {
		_enemy[i].EnemyUpdate(_wnd);
		_innocent[i].InnocentUpdate(_wnd);

		if (_enemy[i].IsInGame()) {
			if (_ShotClock.getElapsedTime().asSeconds() >= _ShotTime && _enemy[i].Shoot()) {
				ShotAtPlayer();
				_ShotClock.restart();
			}
		}
		
		if (_score == 10) {
			_YouWin = true;
			FinalScore();
		}
		if (_lifes == 0) {
			_GameOver = true;
			FinalScore();
		}
	}
}


void Game::LifeUpdate() {
	_textLifes.setString("Lifes: " + to_string(_lifes));
}

void Game::ScoreUpdate() {
	_textScore.setString("Score: " + to_string(_score));
}

void Game::FinalScore() {
	_textFinalScore.setString("Final Score: " + to_string ((_score - (3 - _lifes)) * 10));
}

void Game::CheckCollision() {
	Vector2f playerPos = _player->Getpos();

	for (int i = 0; i < 20; i++) {
			if (_enemy[i].IsInGame()) {
				if (_enemy[i].IsAbove(playerPos.x, playerPos.y)) {
					_enemy[i].Die();
					_score++;

					ScoreUpdate();
					LifeUpdate();
					break;
			    } 
		    }

		if (_innocent[i].IsInGame()) {
			if (_innocent[i].IsAbove(playerPos.x, playerPos.y)) {
				_innocent[i].ShootAtInnocent();
				_lifes-- && _score--;

				ScoreUpdate();
				LifeUpdate();
				break;
			}
		}
		
	}
	
}

void Game::ShotAtPlayer() {
    _ShowBang = true;
	_lifes-- && _score--;
	LifeUpdate();
	ScoreUpdate();
}

void Game::Draw() {
	_wnd->clear();

	for (int i = 0; i < 20; i++) {
		if (_enemy[i].IsInGame()) {
			_enemy[i].Draw(_wnd);
		}
		if (_innocent[i].IsInGame()) {
			_innocent[i].Draw(_wnd);
		}
	}

	_wnd->draw(_backScreen_Sp);
	_player->Draw(_wnd);

	if (_ShowBang) {
		_wnd->draw(_bang);
		if (_ShotClock.getElapsedTime().asSeconds() >= _ShotTime) {
			_ShowBang = false; // Ocultar el efecto después de un tiempo determinado
		}
	}

	if (_GameOver) {
		_wnd->draw(_textGameOver);
		_wnd->draw(_textFinalScore);
		_wnd->setMouseCursorVisible(true);
	}
	else if (_YouWin) {
		_wnd->draw(_textWin);
		_wnd->draw(_textFinalScore);
	}

	_wnd->draw(_textScore);
	_wnd->draw(_textLifes);
	_wnd->display();
}

void Game::RestartGame() {
	// Restablecemos variables del juego //
	_wnd->setMouseCursorVisible(false);
	_score = 0;
	_lifes = 3;
	_GameOver = false;
	_YouWin = false;
	_ShowBang = false;
	_ShotTime = 10.0f;
	_ShotClock.restart();

	// Reiniciamos la posicion y el estado de los enemigos //
	for (int i = 0; i < 20; i++) {
			_enemy[i].Reset(_wnd);
			_enemy[i].EnemyUpdate(_wnd);
			_innocent[i].Reset(_wnd);
			_innocent[i].InnocentUpdate(_wnd);
	}
	ScoreUpdate();
	LifeUpdate();
	FinalScore();
}

Game::~Game() {
	delete[] _innocent;
	delete[] _enemy;
	delete _player;
	delete _wnd;
}
