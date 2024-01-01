#include "Game.h"

void Game::ActualizarPuntaje() {
	puntaje.setString("Puntos: " + to_string(puntos));
}

Game::Game() {
	_wnd = new RenderWindow(VideoMode(800, 600), "6- Clickale");
	_player = new PlayerCrosshair();
	_enemy = new Enemy[5];
	fondoTexture.loadFromFile("Fondo.jpg");
	fondoSprite.setTexture(fondoTexture);
	fondoSprite.setScale(0.5f, 0.5f);
	moonTexture.loadFromFile("Moon.jpeg");
	moonSprite.setTexture(moonTexture);
	moonSprite.setScale(0.25f, 0.25f);
	moonSprite.setPosition(650, 0);
	puntaje.setPosition(0, 0);
	puntos = 0;
	font.loadFromFile("MICKEY.TTF");
	puntaje.setFont(font);
	puntaje.setCharacterSize(24);
	puntaje.setFillColor(Color::White);
	puntaje.setString("Puntos: 0");
}

void Game::Loop() {
	while (_wnd->isOpen()) {
		ProcesarEventos();
		Actualizar();
		Dibujar();
	}
}

void Game::ProcesarEventos() {
	Event evt;
	while (_wnd->pollEvent(evt)) {
		switch (evt.type) {
		case Event::Closed:
			_wnd->close();
			break;
		case Event::MouseMoved:
			_player->Posicionar(evt.mouseMove.x, evt.mouseMove.y);
			break;
		case Event::MouseButtonPressed:
			if (evt.mouseButton.button == Mouse::Button::Left)
				Disparar();
			break;
		}
	}
}

void Game::Disparar() {
	Vector2f playerPos = _player->ObtenerPosicion();
	for (int i = 0; i < 5; i++) {
		if (_enemy[i].EstaActivo()) {
			if (_enemy[i].EstaEncima(playerPos.x, playerPos.y)) {
				_enemy[i].derrotado();
				puntos++;
				ActualizarPuntaje();
			}
		}
	}
}

void Game::Actualizar() {
	for (size_t i = 0; i < 5; i++) {
		_enemy[i].Actualizar(_wnd);
	}
}

void Game::Dibujar() {
	_wnd->clear();
	_wnd->draw(fondoSprite);
	_wnd->draw(moonSprite);

	for (int i = 0; i < 5; i++) {
		if (_enemy[i].EstaActivo()) {
			_enemy[i].Dibujar(_wnd);
		}
	}

	_player->Dibujar(_wnd);
	_wnd->draw(puntaje);
	_wnd->display();
}

Game::~Game() {
	delete[] _enemy;
	delete _player;
	delete _wnd;
}
