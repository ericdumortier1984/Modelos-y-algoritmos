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

void Game::Update(float deltaTime) {

	_estala->AddAcceleration(Vector2f(0.0f, 10.0f));
	_estala->Update(deltaTime);

}

void Game::Go() {

	Clock clock;
	clock.restart();
	float deltaTime;
	while (_wnd->isOpen()) {
		float deltaTime = clock.restart().asSeconds();
		ProcessEvents();
		Update(deltaTime);
		Draw();
	}
}

void Game::Draw() {

	_wnd->clear();
	_cave->Draw(_wnd);
	_estala->Draw(_wnd);
	_wnd->display();
}