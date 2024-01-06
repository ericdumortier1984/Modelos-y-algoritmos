#include "Game.h"

Game::Game() {
	wnd = new RenderWindow(VideoMode(960, 960), "Final MAVI");
	wnd->setFramerateLimit(60);
	mike = new Player(3);
	_music = new Audio();
	_menu = new MainMenu(960, 960);
	fondoPlay = new Background();
	camino = new Background();
	pasto = new Background();
	paisaje = new Background();
	cavermanOne = new Background();

	wnd->setFramerateLimit(60);
	wnd->setMouseCursorVisible(false);
	
	mike->SetPosition(Vector2f(50.0f, 650.0f));
	
}

void Game::Play() {
//Loop
	Clock clock;
	clock.restart();
	float deltaTime;
	while (wnd->isOpen()) {
		float deltaTime = clock.restart().asSeconds();
		ProcessEvents();
		UpdateGame(deltaTime);
		wnd->clear();
		DrawGame();
		wnd->display();
	}
}

void Game::ProcessEvents() {
	_music->PlayMusicGame();
	Event evt;
	while (wnd->pollEvent(evt)) {
		if (evt.type == Event::Closed) {
			wnd->close();
		}
		if (!_gameStarted) {
			if (evt.type == Event::KeyPressed) {
				if (evt.key.code == Keyboard::Up) {
					_menu->MoveUp();
				}
				else if (evt.key.code == Keyboard::Down) {
					_menu->MoveDown();
				}
				else if (evt.key.code == Keyboard::Enter) {
					_gameStarted = true;
				}
			}
		}
	}
}


void Game::UpdateGame(float deltaTime) {
	//Actualizamos posicion y movimiento Player
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		mike->AddAcceleration(Vector2f(80.0f, 0.0f));
	}
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		mike->AddAcceleration(Vector2f(-80.0, 0.0f));
	}
	if (Keyboard::isKeyPressed(Keyboard::Space)) {
		mike->AddAcceleration(Vector2f(0.0f, -90.0f));
	}
	if (mike->GetPosition().y < 350.0f) {
		mike->SetVelocity(Vector2f(0.0f, 100.0f));
	}
	if (mike->GetPosition().y > 580.0f) {
		mike->SetVelocity(Vector2f(0.0f, -100.0f));
	}
	if (mike->GetPosition().y > 450.0f) {
		mike->SetPosition(Vector2f(mike->GetPosition().x, 450.0f));
	}
	if (mike->GetPosition().x > 725.0f) {
		mike->SetPosition(Vector2f(725.0f, mike->GetPosition().y));
	}
	if (mike->GetPosition().x < 0.0f) {
		mike->SetPosition(Vector2f(0.0f, mike->GetPosition().y));
	}
	mike->UpdatePlayer(deltaTime);
}

void Game::DrawGame() {
	if (!_gameStarted) {
		paisaje->Draw(wnd);
		_menu->Draw(wnd);
	}
	else {
		mike->Draw(wnd);
	}
		
}

Game::~Game() {
	delete mike;
	delete wnd;
}