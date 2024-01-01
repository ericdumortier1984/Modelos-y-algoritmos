#include "Game.h"

Game::Game() {
	MENU = new RenderWindow(VideoMode(960, 720), "MAIN MENU");
	MENU->setFramerateLimit(60);

	mainMenu = new MainMenu(MENU->getSize().x, MENU->getSize().y);

	mikeTx.loadFromFile("Asset/Images/Mike.png");
	mikeTx.setSmooth(true);
	mikeSp.setTexture(mikeTx);
	mikeSp.setPosition(200.0f, 300.0f);

	wheelTx.loadFromFile("Asset/Images/neumatico.png");
	wheelSp.setTexture(wheelTx);
	wheelSp.setPosition(0.0f, 600.0f);

	fondoPlayTx.loadFromFile("Asset/Images/Taller.png");
	fondoPlaySp.setTexture(fondoPlayTx);
	fondoPlaySp.setPosition(0.0f, 240.0f);

	MENU->setFramerateLimit(60);
	MENU->setMouseCursorVisible(false);

	music.openFromFile("Asset/Audio/rock.ogg");
}

void Game::ProcessEvents() {
	music.setLoop(true);
	music.play();
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
					Play.setFramerateLimit(60);
					RenderWindow OPTIONS(VideoMode(960, 720), "OPTIONS");
					RenderWindow ABOUT(VideoMode(960, 720), "ABOUT");

					int x = mainMenu->MainMenuPressed();
					if (x == 0) {
						music.stop();
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
							Play.draw(fondoPlaySp);
							Play.draw(wheelSp);
							Play.draw(mikeSp);
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
			MENU->clear(Color::Black);
			mainMenu->Draw(MENU);
			MENU->display();
		}
	}
}

//void Game::UpdateGame(float deltaTime) {
	//Actualizamos posicion y movimientos de Mike
	/*if (Keyboard::isKeyPressed(Keyboard::D)) {
		mike->AddAcceleration(Vector2f(30.0, 0.0f));
	}
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		mike->AddAcceleration(Vector2f(-30.0, 0.0f));
	}
	if (Keyboard::isKeyPressed(Keyboard::Space)) {
		mike->AddAcceleration(Vector2f(0.0f, -90.0f));
	}
	if (mike->GetPosition().y < 350.0f) {
		mike->SetVelocity(Vector2f(0.0f, 60.0f));
	}
	if (mike->GetPosition().y > 580.0f) {
		mike->SetVelocity(Vector2f(0.0f, -10.0f));
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
	mike->UpdateMike(deltaTime);*/
//}

void Game::Go() {
	//Loop
	Clock clock;
	clock.restart();
	float deltaTime;
	while (MENU->isOpen()) {
		float deltaTime = clock.restart().asSeconds();
		ProcessEvents();
		//UpdateGame(deltaTime);
		DrawGame();
	}
}

void Game::DrawGame() {

}

Game::~Game() {

}
