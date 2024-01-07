#include "Game.h"

Game::Game() {
	wnd = new RenderWindow(VideoMode(960, 960), "Final MAVI");
	wnd->setFramerateLimit(60);
	wnd->setMouseCursorVisible(false);

	mike = new Player(3);
	mike->SetPosition(Vector2f(50.0f, 650.0f));

	music = new Audio();
	menu = new MainMenu(960, 960);
	fondoPlay = new Background();
	camino = new Background();
	pasto = new Background();
	paisaje = new Background();
	cavermanOne = new Background();
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
	//music.setLoop(true);
	//music.play();
	Event evt;
	while (wnd->pollEvent(evt)) {
		if (evt.type == Event::Closed) {
			wnd->close();
		}
		if (evt.type == Event::KeyPressed) {
			if (evt.key.code == Keyboard::Escape) {
				wnd->close();
			}
		}
		if (!_gameStarted) {
			if (evt.type == Event::KeyPressed) {
				if (evt.key.code == Keyboard::Up) {
					menu->MoveUp();
				}
				if (evt.key.code == Keyboard::Down) {
					menu->MoveDown();
				}
				if (evt.key.code == Keyboard::Enter) {
					_gameStarted = true;
				}
			}
		}
	}
}


void Game::UpdateGame(float deltaTime) {

	mike->UpdatePlayer(deltaTime);
}

void Game::DrawGame() {
	if (!_gameStarted) {
		paisaje->Draw(wnd);
		menu->Draw(wnd);
	}
	if (_gameStarted) {
		fondoPlay->Draw(wnd);
		pasto->Draw(wnd);
		cavermanOne->Draw(wnd);
		camino->Draw(wnd);
		mike->Draw(wnd);
	}
		
}

Game::~Game() {
	delete mike;
	delete wnd;
}