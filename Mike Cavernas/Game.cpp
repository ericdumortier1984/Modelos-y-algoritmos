#include "Game.h"

Game::Game() {

	_wnd = new RenderWindow(VideoMode(800, 600), "Mike Cavernas");
	_wnd->setFramerateLimit(60);
	_wnd->setMouseCursorVisible(false);

	_cave = new Backgrounds();

	_estala = new Obstacles();

	_mike = new Mike(3);
	_mike->SetPosition(Vector2f(30.0f, 500.0f));

	_chicken = new PointUp(0);

	_font.loadFromFile("Asset/Font/junegull.ttf");
	_lifesText.setFont(_font);
	_lifesText.setCharacterSize(20);
	_lifesText.setFillColor(Color::White);
	_lifesText.setString("MIKE: 3");
	_lifesText.setPosition(200.0f, 200.0f);

	_font.loadFromFile("Asset/Font/junegull.ttf");
	_pointsText.setFont(_font);
	_pointsText.setCharacterSize(20);
	_pointsText.setFillColor(Color::White);
	_pointsText.setString("MIKE: 0");
	_pointsText.setPosition(300.0f, 200.0f);
}

Game::~Game() {

	delete _mike;
	delete _chicken;
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

	if (Keyboard::isKeyPressed(Keyboard::D)) {
		_mike->SetVelocity(Vector2f(50.0f, 0.0f));
	}
	else if
		(Keyboard::isKeyPressed(Keyboard::A)) {
			_mike->SetVelocity(Vector2f(-50.0f, 0.0f));
	}
	else {
		_mike->SetVelocity(Vector2f(0.0f, 0.0f));
	}
	_mike->Update(deltaTime);
}

void Game::CheckCollision() {

	Vector2f estalaPos = _estala->GetPosition();
	if (_estala->isActive()){
		if (_mike->GetPricked(estalaPos.x, estalaPos.y)) {
			_mike->Pricked();
			_estala->SetVisible(false);
		}
	}
}

int Game::UpdateLifes() {

	int _mikeLifes = _mike->GetLifes();
	_lifesText.setString("MIKE: " + to_string(_mikeLifes));
	return _mikeLifes;
}

void Game::Go() {

	Clock clock;
	clock.restart();
	float deltaTime;
	while (_wnd->isOpen()) {
		float deltaTime = clock.restart().asSeconds();
		ProcessEvents();
		Update(deltaTime);
		CheckCollision();
		UpdateLifes();
		Draw();
	}
}

void Game::Draw() {

	_wnd->clear();
	_cave->Draw(_wnd);
	_estala->Draw(_wnd);
	_chicken->Draw(_wnd);
	_mike->Draw(_wnd);
	_wnd->draw(_lifesText);
	_wnd->draw(_pointsText);
	_wnd->display();
}