#include "Game.h"

Game::Game() 
{
	srand(time(NULL));
	_randomX = rand() % 700;

	_wnd = new RenderWindow(VideoMode(800, 600), "Mike Cavernas");
	_wnd->setFramerateLimit(60);
	_wnd->setMouseCursorVisible(false);

	_cave = new Backgrounds();
	_landscape = new Backgrounds();
	_rockPath = new Backgrounds();

	_estala = new Obstacles();
	_estala->SetPosition(Vector2f(_randomX, -30.0f));

	_mike = new Mike(1);
	_mike->SetPosition(Vector2f(30.0f, 500.0f));

	_chicken = new Item(0);
	_chicken->SetPosition(Vector2f(_randomX, 520.0f));

	_cursor = new Menu();
	_start = new Menu();
	_reset = new Menu();

	_gameStarted = false;
	_gameOver = false;
	_restartGame = false;

	_music.openFromFile("Asset/Audio/Musica_principal.ogg");
	_music.setLoop(true);
	_music.play();

	_font.loadFromFile("Asset/Font/junegull.ttf");
	_lifesText.setFont(_font);
	_lifesText.setCharacterSize(20);
	_lifesText.setFillColor(Color::White);
	_lifesText.setString("MIKE: 3");
	_lifesText.setPosition(0.0f, 0.0f);

	_font.loadFromFile("Asset/Font/junegull.ttf");
	_pointsText.setFont(_font);
	_pointsText.setCharacterSize(20);
	_pointsText.setFillColor(Color::White);
	_pointsText.setString("POINTS: 0");
	_pointsText.setPosition(700.0f, 0.0f);
}

Game::~Game() 
{

	delete _mike;
	delete _chicken;
	delete _estala;
	delete _cursor;
	delete _rockPath;
	delete _cave;
	delete _landscape;
	delete _wnd;
}

void Game::ProcessEvents() 
{

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
		if (evt.type == Event::MouseMoved) {
		    _cursor->CursorSetPosition(evt.mouseMove.x, evt.mouseMove.y);
		}
		if (evt.type == Event::MouseButtonPressed) {
			if (evt.mouseButton.button == Mouse::Left) {
				if (!_gameStarted && _start->GetStartPressed(evt.mouseButton.x, evt.mouseButton.y)) {
					_gameStarted = true;
					_music.stop();
				}
			}
		}
	}
}

void Game::Update(float deltaTime)
{

	_estala->AddAcceleration(Vector2f(0.0f, 20.0f));
	_estala->Update(deltaTime);

	if (Keyboard::isKeyPressed(Keyboard::D)) {
		if (_mike->GetPosition().x >= 700.0f)
		_mike->SetPosition(Vector2f(700.0f, _mike->GetPosition().y));
		_mike->SetVelocity(Vector2f(100.0f, 0.0f));
	}
	else if
		(Keyboard::isKeyPressed(Keyboard::A)) {
		if (_mike->GetPosition().x <= 0.0f)
			_mike->SetPosition(Vector2f(0.0f, _mike->GetPosition().y));
			_mike->SetVelocity(Vector2f(-100.0f, 0.0f));
	}
	else {
		_mike->SetVelocity(Vector2f(0.0f, 0.0f));
	}
	_mike->Update(deltaTime);
	_chicken->Update(deltaTime);
}

void Game::CheckCollision() 
{

	Vector2f estalaPos = _estala->GetPosition();
	if (_estala->isActive()){
		if (_mike->GetPricked(estalaPos.x, estalaPos.y)) {
			_mike->Pricked();
			_estala->SetVisible(false);
		}
	}

	Vector2f mikePos = _mike->GetPosition();
	if (_chicken->IsActive()) {
		if (_chicken->GetChicken(mikePos.x, mikePos.y)) {
			_chicken->SetPointUp();
			_chicken->SetVisible(false);
		}
	}
}

int Game::UpdateLifes() 
{

	int _mikeLifes = _mike->GetLifes();
	_lifesText.setString("MIKE: " + to_string(_mikeLifes));

	if (_mikeLifes <= 0) {
		RestartGame();
	}

	return _mikeLifes;
}

int Game::UpdatePoints() 
{

	int _mikePoints = _chicken->GetPoints();
	_pointsText.setString("POINTS: " + to_string(_mikePoints));
	return _mikePoints;
}

void Game::Go() 
{

	Clock clock;
	clock.restart();
	float deltaTime;
	while (_wnd->isOpen()) {
		float deltaTime = clock.restart().asSeconds();
		ProcessEvents();
		Update(deltaTime);
		CheckCollision();
		UpdatePoints();
		UpdateLifes();
		Draw();
	}
}

void Game::GameOver() 
{
	if (_mike->GetLifes() <= 0) {
		_gameOver = true;
		_wnd->setMouseCursorVisible(true);
	}
}

void Game::RestartGame()
{

	if (_mike->GetLifes() <= 0) {
		_restartGame = true;
		_mike->SetPosition(Vector2f(30.0f, 500.0f));
	}
}

void Game::Draw() 
{

	_wnd->clear();
	if (!_gameStarted) {
		_landscape->Draw(_wnd);
		_cave->Draw(_wnd);
		_rockPath->Draw(_wnd);
		_start->Draw(_wnd);
		_reset->Draw(_wnd);
		_cursor->Draw(_wnd);
	}
	else {
		_landscape->Draw(_wnd);
		_cave->Draw(_wnd);
		_rockPath->Draw(_wnd);
		_wnd->draw(_lifesText);
		_wnd->draw(_pointsText);
		_estala->Draw(_wnd);
		_chicken->Draw(_wnd);
		_mike->Draw(_wnd);
	}
	_wnd->display();
}