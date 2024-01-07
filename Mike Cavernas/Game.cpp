#include "Game.h"

Game::Game() {

	_wnd = new RenderWindow(VideoMode(800, 600), "Mike Cavernas");
	_wnd->setFramerateLimit(60);
	_wnd->setMouseCursorVisible(false);

	_cave = new Backgrounds();

	_estala = new Obstacles();
}

Game::~Game() {

	delete _estala;
	delete _cave;
	delete _wnd;
}

void Game::ProcessEvents() {

	Event evt;
	while (_wnd->pollEvent(evt)) {
		if (evt.type == Event::Closed) {
			_wnd->close();
		}
		if (evt.type == Event::KeyPressed) {
			if (evt.key.code == Keyboard::Escape) {
				_wnd->close();
			}
		}
	}
}

void Game::Update() {

}

void Game::Go() {

	while (_wnd->isOpen()) {
		ProcessEvents();
		Update();
		Draw();
	}
}

void Game::Draw() {

	_wnd->clear();
	_cave->Draw(_wnd);
	_estala->Draw(_wnd);
	_wnd->display();
}