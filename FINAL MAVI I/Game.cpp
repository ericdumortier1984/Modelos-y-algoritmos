#include "Game.h"

Game::Game() {
	//Ventana principal
	MENU = new RenderWindow(VideoMode(960, 960), "MAIN MENU");
	MENU->setFramerateLimit(60);
	MENU->setMouseCursorVisible(false);
	//Opciones de menu
	mainMenu = new MainMenu(MENU->getSize().x, MENU->getSize().y);
	//Personaje
	mikeTx.loadFromFile("Asset/Images/cavernicola.png");
	mikeTx.setSmooth(true);
	mikeSp.setTexture(mikeTx);
	mikeSp.setPosition(50.0f, 650.0f);
	//Obstaculos
	wheelTx.loadFromFile("Asset/Images/rueda.png");
	wheelSp.setTexture(wheelTx);
	wheelSp.setPosition(20.0f, 650.0f);
	//Fondos
	fondoPlayTx.loadFromFile("Asset/Images/cueva.png");
	fondoPlaySp.setTexture(fondoPlayTx);
	moonTx.loadFromFile("Asset/Images/lunavioleta.png");
	moonSp.setTexture(moonTx);
	moonSp.setPosition(180.0f, 280.0f);
	caminoTx.loadFromFile("Asset/Images/camino.png");
	caminoSp.setTexture(caminoTx);
	caminoSp.setPosition(50.0f, 650.0f);
	pastoTx.loadFromFile("Asset/Images/pasto.png");
	pastoSp.setTexture(pastoTx);
	pastoSp.setPosition(50.0f, 550.0f);
	paisajeTx.loadFromFile("Asset/Images/paisaje.png");
	paisajeSp.setTexture(paisajeTx);
	cavermanOneTx.loadFromFile("Asset/Images/cavernicola 6.png");
	cavermanOneSp.setTexture(cavermanOneTx);
	cavermanOneSp.setPosition(500.0f, 560.0f);
	//Musica y sonidos
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
							}
							OPTIONS.close();
							ABOUT.close();
							Play.clear(Color::Cyan);
							Play.draw(pastoSp);
							Play.draw(moonSp);
							Play.draw(cavermanOneSp);
							Play.draw(caminoSp);
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
			MENU->draw(paisajeSp);
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
		DrawGame();
	}
}

void Game::Update(float deltaTime) {

}

void Game::DrawGame() {

}

Game::~Game() {
	delete MENU;
}
