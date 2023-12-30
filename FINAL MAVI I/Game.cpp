#include "Game.h"

Game::Game() {
	MENU = new RenderWindow(VideoMode(960, 720), "MAIN MENU");
	mainMenu = new MainMenu(MENU->getSize().x, MENU->getSize().y);

	MENU->setFramerateLimit(60);
	MENU->setMouseCursorVisible(false);
}

void Game::ProcessEvents() {
	while (MENU->isOpen()) {
		Event event;
		while (MENU->pollEvent(event)) {
			if (event.type == Event::Closed) {
				MENU->close();
			}
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Up) {
					mainMenu->MoveUp();
					break;
				}
				if (event.key.code == Keyboard::Down) {
					mainMenu->MoveDown();
					break;
				}
				if (event.key.code == Keyboard::Enter) {
					RenderWindow Play(VideoMode(960, 720), "GAME");
					RenderWindow OPTIONS(VideoMode(960, 720), "OPTIONS");
					RenderWindow ABOUT(VideoMode(960, 720), "ABOUT");

					int x = mainMenu->MainMenuPressed();
					if (x == 0) {
						while (Play.isOpen()) {
							Event aevent;
							while (Play.pollEvent(aevent)) {
								if (aevent.type == Event::Closed) {
									Play.close();
								}
								if (aevent.type == Event::KeyPressed) {
									if (aevent.key.code == Keyboard::Escape) {
										Play.close();
									}
								}
							}
							OPTIONS.close();
							ABOUT.close();
							Play.clear();
							Play.display();
						}
					}
					if (x == 1) {
						while (OPTIONS.isOpen()) {
							Event aevent;
							while (OPTIONS.pollEvent(aevent)) {
								if (aevent.type == Event::Closed) {
									OPTIONS.close();
								}
								if (aevent.type == Event::KeyPressed) {
									if (aevent.key.code == Keyboard::Escape) {
										OPTIONS.close();
									}
								}
							}
							Play.close();
							OPTIONS.clear();
							ABOUT.close();
							OPTIONS.display();
						}
					}
					if (x == 2) {
						while (ABOUT.isOpen()) {
							Event aevent;
							while (ABOUT.pollEvent(aevent)) {
								if (aevent.type == Event::Closed) {
									ABOUT.close();
								}
								if (aevent.type == Event::KeyPressed) {
									if (aevent.key.code == Keyboard::Escape) {
										ABOUT.close();
									}
								}
							}
							Play.close();
							OPTIONS.close();
							ABOUT.clear();
							ABOUT.display();
						}
					}
					if (x == 3) {
						MENU->close();
						break;
					}
				}
			}
			MENU->clear();
			mainMenu->Draw(MENU);
			MENU->display();
		}
	}
}

void Game::UpdateGame(float deltaTime) {

}

void Game::Play() {
	//Loop
	Clock clock;
	clock.restart();
	float deltaTime;
	while (MENU->isOpen()) {
		float deltaTime = clock.restart().asSeconds();
		ProcessEvents();
		UpdateGame(deltaTime);
		DrawGame();
	}
}

void Game::DrawGame() {
	
}

Game::~Game() {

}
