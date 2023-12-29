#include "Game.h"

Game::Game() {
	srand(time(NULL));
	randomX = rand() % 800;
	_gameOver = false;

	//puntaje inicial
	_score = 500;

	_wnd = new RenderWindow(VideoMode(800, 600), "Wild physics");
	_crosshair = new Crosshair();
	_redBall = new RedBall();
	_blueBall = new BlueBall();
	_greenBall = new GreenBall();
	_greyBall = new GreyBall();
	_orangeBall = new OrangeBall();
	_yellowBall = new YellowBall();

	//seteo posiciones de las bolas de colores
	_redBall->SetPosition(Vector2f(randomX, 0.0f));
	_blueBall->SetPosition(Vector2f(randomX, 0.0f));
	_greenBall->SetPosition(Vector2f(randomX, 0.0f));
	_greyBall->SetPosition(Vector2f(randomX, 0.0f));
	_orangeBall->SetPosition(Vector2f(randomX, 0.0f));
	_yellowBall->SetPosition(Vector2f(randomX, 0.0f));
	
	//Inicialización de fuentes y posicionamento de textos
	_font.loadFromFile("Asset/junegull.ttf");
	_textTitle.setFont(_font);
	_textTitle.setString("wild Physics");
	_textTitle.setFillColor(Color::Cyan);
	_textTitle.setCharacterSize(48);
	_textTitle.setPosition(_wnd->getSize().x /2 - _textTitle.getLocalBounds().width / 2, _wnd->getSize().y /2);
	_textScore.setFont(_font);
	_textScore.setString("SCORE");
	_textScore.setFillColor(Color::White);
	_textScore.setCharacterSize(36);
	_textDone.setFont(_font);
	_textDone.setString("DONE!");
	_textDone.setFillColor(Color::Magenta);
	_textDone.setCharacterSize(54);
	_textDone.setPosition(_wnd->getSize().x / 2 - _textDone.getLocalBounds().width / 2, 450.0f);
	_textWinner.setFont(_font);
	_textWinner.setString("YOUR GREAT!");
	_textWinner.setFillColor(Color::Magenta);
	_textWinner.setCharacterSize(60);
	_textWinner.setPosition(_wnd->getSize().x / 2 - _textWinner.getLocalBounds().width / 2, 500.0f);
	_textLoser.setFont(_font);
	_textLoser.setString("TRY HARDER!");
	_textLoser.setFillColor(Color::Magenta);
	_textLoser.setCharacterSize(60);
	_textLoser.setPosition(_wnd->getSize().x / 2 - _textLoser.getLocalBounds().width / 2, 500.0f);
}

Game::~Game() {
	//Liberación de memoria
	delete _yellowBall;
	delete _orangeBall;
	delete _greyBall;
	delete _greenBall;
	delete _blueBall;
	delete _redBall;
	delete _crosshair;
	delete _wnd;
}

void Game::Loop() {
	//Bucle principal
	Clock clock;
	clock.restart();
	float deltaTime;
	while (_wnd->isOpen()) {
		if (!_gameOver) {
			_wnd->setMouseCursorVisible(false);
			float deltaTime = clock.restart().asSeconds();
			ProcessEvents();
			Update(deltaTime);
			Draw();
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			_wnd->close();
		}
	}
}

void Game::Update(float deltaTime) {
	//Actualización de la logica
	_yellowBall->AddAcceleration(Vector2f(0.0f, 300.0f));
	_greyBall->AddAcceleration(Vector2f(0.0f, 400.0f));
	_redBall->AddAcceleration(Vector2f(0.0f, 500.0f));
	_blueBall->AddAcceleration(Vector2f(0.0f, 600.0f));
	_greenBall->AddAcceleration(Vector2f(0.0f, 700.0f));
	_orangeBall->AddAcceleration(Vector2f(0.0f, 800.0f));

	//Si la bola de color toca el piso resta puntaje
	if (_yellowBall->GetPosition().y > 550.0f) {
		_yellowBall->SetVelocity(Vector2f(0.0f, -600.0f));
		_score -= 10;
	}
	_yellowBall->Update(deltaTime);
	ScoreUpdate();

	if (_greyBall->GetPosition().y > 550.0f) {
		_greyBall->SetVelocity(Vector2f(0.0f, -650.0f));
		_score -= 30;
	}
	_greyBall->Update(deltaTime);
	ScoreUpdate();

	if (_redBall->GetPosition().y > 550.0f) {
		_redBall->SetVelocity(Vector2f(0.0f, -700.0f));
		_score -= 50;
	}
	_redBall->Update(deltaTime);
	ScoreUpdate();
	
	if (_blueBall->GetPosition().y > 550.0f) {
		_blueBall->SetVelocity(Vector2f(0.0f, -750.0f));
		_score -= 70;
	}
	_blueBall->Update(deltaTime);
	ScoreUpdate();
	
	if (_greenBall->GetPosition().y > 550.0f) {
		_greenBall->SetVelocity(Vector2f(0.0f, -800.0f));
		_score -= 80;
	}
		_greenBall->Update(deltaTime);
		ScoreUpdate();
	
	if (_orangeBall->GetPosition().y > 550.0f) {
		_orangeBall->SetVelocity(Vector2f(0.0f, -850.0f));
		_score -= 100;
		ScoreUpdate();
	}
	_orangeBall->Update(deltaTime);
	

	//Si no quedan bolas de colores en pantalla termina el juego
	if (!_redBall->isInGame() && !_blueBall->isInGame() && !_greenBall->isInGame() && !_greyBall->isInGame() && !_orangeBall->isInGame() && !_yellowBall->isInGame()) {
		ScoreUpdate();
		_gameOver = true;
	}
}

void Game::ProcessEvents() {
	//Proceso de eventos del juego
	Event evt;
	while (_wnd->pollEvent(evt)) {
		if (evt.type == Event::Closed) {
			_wnd->close();
		}
		if (evt.type == Event::MouseMoved) {
			_crosshair->SetPosition(evt.mouseMove.x, evt.mouseMove.y);
			_crosshair->SetOrigin();
		}
		if (evt.mouseButton.button == Mouse::Button::Left) {
			CheckCollision();
		}
	}
}

void Game::CheckCollision() {
	/*Comprobamos colisiones entre el cursor y las bolas de colores
	Si acertamos a las bolas de colores sumamos puntaje*/
	Vector2f getPos = _crosshair->Getposition();
	
	if (_yellowBall->isInGame()) {
		if (_yellowBall->isAbove(getPos.x, getPos.y)) {
			_yellowBall->ShotDown();
			_score += 50;
			ScoreUpdate();
		}
	}

	if (_greyBall->isInGame()) {
		if (_greyBall->isAbove(getPos.x, getPos.y)) {
			_greyBall->ShotDown();
			_score += 80;
			ScoreUpdate();
		}
	}

	if (_redBall->isInGame()) {
		if (_redBall->isAbove(getPos.x, getPos.y)) {
			_redBall->ShotDown();
			_score += 100;
			ScoreUpdate();
		}
	}

	if (_blueBall->isInGame()) {
		if (_blueBall->isAbove(getPos.x, getPos.y)) {
			_blueBall->ShotDown();
			_score += 150;
			ScoreUpdate();
		}
	}

	if (_greenBall->isInGame()) {
		if (_greenBall->isAbove(getPos.x, getPos.y)) {
			_greenBall->ShotDown();
			_score += 200;
			ScoreUpdate();
		}
	}

	if (_orangeBall->isInGame()) {
		if (_orangeBall->isAbove(getPos.x, getPos.y)) {
			_orangeBall->ShotDown();
			_score += 250;
			ScoreUpdate();
		}
	}
}

void Game::ScoreUpdate() {
	//Actualización del marcador de puntuación
	_textScore.setString("SCORE " + to_string(_score));
}

void Game::Draw() {
	//Dibujamos elementos en pantalla
	_wnd->clear();
	_wnd->draw(_textTitle);
	_yellowBall->Draw(_wnd);
	_orangeBall->Draw(_wnd);
	_greyBall->Draw(_wnd);
	_redBall->Draw(_wnd);
	_blueBall->Draw(_wnd);
	_greenBall->Draw(_wnd);
	_crosshair->Draw(_wnd);
	if (_gameOver) {
		_wnd->draw(_textDone);
		if (_score > 0) {
			_wnd->draw(_textWinner);
		}
		if (_score < 0) {
			_wnd->draw(_textLoser);
		}
	}
	_wnd->draw(_textScore);
	_wnd->display();
}