#include "Game.h"

Game::Game() {
	//Ventana principal
	MENU = new RenderWindow(VideoMode(960, 960), "MAIN MENU");
	MENU->setFramerateLimit(60);
	MENU->setMouseCursorVisible(false);
	//Opciones de menu
	mainMenu = new MainMenu(MENU->getSize().x, MENU->getSize().y);
	//Personaje
	mike = new Mike();
	//Obstaculos
	wheel = new Obstacles();
	pinche = new Obstacles();
	// Inicializar fondos
	fondoPlay = new Backgrounds();
	moon = new Backgrounds();
	camino = new Backgrounds();
	pasto = new Backgrounds();
	paisaje = new Backgrounds();
	cavermanOne = new Backgrounds();
	//Musica y sonidos
	music.openFromFile("Asset/Audio/rock.ogg");
}

void Game::ProcessEvents() {
	music.setLoop(true);
	music.play();
	float deltaTime = 1.0f / 60.0f;
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
					RenderWindow Play(VideoMode(960, 960), "GAME");
					Play.setFramerateLimit(60);
					RenderWindow OPTIONS(VideoMode(960, 960), "OPTIONS");
					RenderWindow ABOUT(VideoMode(960, 960), "ABOUT");

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
								if (aevent.type == Event::KeyPressed) {
									if (aevent.key.code == Keyboard::D) {
										mike->mikeSp.move(5.0f, 0.0f);
									}
									if (aevent.key.code == Keyboard::A) {
										mike->mikeSp.move(-5.0f, 0.0f);
									}
									if (mike->mikeSp.getPosition().x < 0.0f) {
										mike->mikeSp.setPosition(Vector2f(0.0f, mike->mikeSp.getPosition().y));
									}
									if (mike->mikeSp.getPosition().x > 850.0f) {
										mike->mikeSp.setPosition(Vector2f(850.0f, mike->mikeSp.getPosition().y));
									}
								}
							}
							OPTIONS.close();
							ABOUT.close();
							Play.clear(Color::Cyan);
							Play.draw(pasto->pastoSp);
							Play.draw(moon->moonSp);
							Play.draw(cavermanOne->cavermanOneSp);
							Play.draw(camino->caminoSp);
							Play.draw(fondoPlay->fondoPlaySp);
							Play.draw(wheel->wheelSp);
							Play.draw(mike->mikeSp);
							Play.draw(pinche->pincheSp);
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
			MENU->draw(paisaje->paisajeSp);
			mainMenu->Draw(MENU);
			MENU->display();
		}
	}
}
	
void Game::Go() {
	//Loop
	Clock clock;
	clock.restart();
	float deltaTime;
	while (MENU->isOpen()) {
		float deltaTime = clock.restart().asSeconds();
		ProcessEvents();
		Update(deltaTime);
	}
}

void Game::Update(float deltaTime) {
	pinche->AddAcceleration(Vector2f(0.0f, 300.0f));
	pinche->Update(deltaTime);
}

Game::~Game() {
	delete MENU;
}
