#include "Game.h"

Game::Game() {
	wnd = new RenderWindow(VideoMode(960, 960), "Mike Cavernas");
	wnd->setFramerateLimit(60);
	wnd->setMouseCursorVisible(false);

	mike = new Player(3);
	mike->SetPosition(Vector2f(50.0f, 650.0f));

	menu = new MainMenu();
	fondoPlay = new Background();
	camino = new Background();
	pasto = new Background();
	paisaje = new Background();
	cavermanOne = new Background();

	music.openFromFile("Asset/Audio/Musica_principal.ogg");
	music.setLoop(true);
}

void Game::Go() {
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
	music.play();
	Event evt;
	while (wnd->pollEvent(evt)) {
		if (evt.type == Event::Closed) {
			wnd->close();
		}
		if (evt.type == Event::KeyPressed) {
			if (evt.key.code == Keyboard::Escape) {
				wnd->close();
			}
			if (evt.key.code == Keyboard::Up) {
				menu->MoveUp();
			}
			if (evt.key.code == Keyboard::Down) {
				menu->MoveDown();
			}
		}
	}
}


void Game::UpdateGame(float deltaTime) {

	mike->UpdatePlayer(deltaTime);
}

void Game::DrawGame() {
		paisaje->Draw(wnd);
		menu->Draw(wnd);
}

Game::~Game() {
	delete mike;
	delete wnd;
}