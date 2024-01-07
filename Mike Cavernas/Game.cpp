#include "Game.h"

Game::Game() {

	_wnd = new RenderWindow(VideoMode(960, 720), "Mike Cavernas");
}

Game::~Game() {

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
	_wnd->display();
}