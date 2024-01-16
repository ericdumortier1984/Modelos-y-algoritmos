#include "Game.h"

Game::Game() 
{
	srand(time(NULL));
	_randomX = rand() % 700;

	_wnd = new RenderWindow(VideoMode(800, 600), "Mike Cavernas");
	_wnd->setFramerateLimit(60);
	_wnd->setMouseCursorVisible(false);

	_pathTx.loadFromFile("Asset/Images/RockPath.png");
	_path.setTexture(_pathTx);
	_path.setPosition(0.0f, 190.0f);

	_landscapeTx.loadFromFile("Asset/Images/Landscape.png");
	_landscape.setTexture(_landscapeTx);
	_landscape.setPosition(0.0f, 0.0f);

	_caveTx.loadFromFile("Asset/Images/Cave.png");
	_cave.setTexture(_caveTx);
	_cave.setPosition(0.0f, 30.0f);

	_estala = new Obstacles;
	_estala->SetPosition(Vector2f(_randomX, -30.0f));

	_mike = new Mike(3, 0);
	_mike->SetPosition(Vector2f(30.0f, 500.0f));

	_chicken = new Item();
	_chicken->SetPosition(Vector2f(_randomX, 520.0f));

	_cursor = new Menu();
	_start = new Menu();

	_gameStarted = false;
	_gameOver = false;
	_restartGame = false;

	_musicPrincipal.openFromFile("Asset/Audio/Musica_principal.ogg");
	_musicPrincipal.setLoop(true);
	_musicPrincipal.setVolume(75);
	_musicPrincipal.play();

	_musicLevel.openFromFile("Asset/Audio/Musica_nivel.ogg");
	_musicLevel.setLoop(true);
	_musicLevel.setVolume(25);

	_font.loadFromFile("Asset/Font/junegull.ttf");
	_titleText.setFont(_font);
	_titleText.setCharacterSize(50);
	_titleText.setFillColor(Color::White);
	_titleText.setString("MIKE CAVERNAS");
	_titleText.setPosition(250.0f, 250.0f);

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
	_pointsText.setPosition(650.0f, 0.0f);
}

Game::~Game() 
{

	delete _mike;
	delete _chicken;
	delete _estala;
	delete _cursor;
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
					_wnd->setMouseCursorVisible(false);
					_musicPrincipal.stop();
					_musicLevel.play();
				}
			}
		}
	}
}

void Game::Update(float deltaTime)
{

	if (Keyboard::isKeyPressed(Keyboard::D)) {
		if (_mike->GetPosition().x >= 750.0f)
		_mike->SetPosition(Vector2f(750.0f, _mike->GetPosition().y));
		_mike->SetVelocity(Vector2f(100.0f, 0.0f));
	}
	else if
		(Keyboard::isKeyPressed(Keyboard::A)) {
		if (_mike->GetPosition().x <= 50.0f)
			_mike->SetPosition(Vector2f(50.0f, _mike->GetPosition().y));
			_mike->SetVelocity(Vector2f(-100.0f, 0.0f));
	}
	else {
		_mike->SetVelocity(Vector2f(0.0f, 0.0f));
	}
	if (Keyboard::isKeyPressed(Keyboard::Space)) {
		_mike->SetVelocity(Vector2f(0.0f, -20.0f));	
	}

	_estala->AddAcceleration(Vector2f(0.0f, 20.0f));
	_estala->Update(deltaTime);
	if (_estala->GetPosition().y > 600) {
		_estala->SetPosition(Vector2f(rand() % 700, -30.0f));
	}

	_mike->Update(deltaTime);
	_mike->UpdateOrientation();
	_chicken->Update(deltaTime);
}

void Game::CheckCollision() 
{

	Vector2f estalaPos = _estala->GetPosition();
		if (_estala->isActive()) {
			if (_mike->GetPricked(estalaPos.x, estalaPos.y)) {
				_mike->Pricked();
				_estala->SetVisible(false);
			}
		}
	
	Vector2f chickenPos = _chicken->GetPosition();
	if (_chicken->IsActive()) {
		if (_mike->GetItem(chickenPos.x, chickenPos.y)) {
			_mike->PointUp();
			_chicken->SetVisible(false);
			RespawnChicken();
		}
	}
}

void Game::RespawnChicken()
{

	float _randomX = rand() % 700;
	_chicken->SetPosition(Vector2f(_randomX, 520.0f));
	_chicken->SetVisible(true);
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

	int _mikePoints = _mike->GetPoints();
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

void Game::RestartGame()
{

	_gameStarted = false;
	_gameOver = false;
	_restartGame = true;

	_mike = new Mike(3, 0);
	_mike->SetPosition(Vector2f(30.0f, 500.0f));
	_estala->SetPosition(Vector2f(_randomX, -30.0f));
	_chicken->SetPosition(Vector2f(_randomX, 520.0f));

	CheckCollision();
}

void Game::Draw() 
{

	_wnd->clear();

	if (!_gameStarted) {
		_wnd->draw(_landscape);
		_wnd->draw(_titleText);
		_start->Draw(_wnd);
		_cursor->Draw(_wnd);
	}
	else {
		_wnd->clear(Color::Cyan);
		_wnd->draw(_cave);
		_wnd->draw(_path);
		_wnd->draw(_lifesText);
		_wnd->draw(_pointsText);
		_estala->Draw(_wnd);
		_chicken->Draw(_wnd);
		_mike->Draw(_wnd);
	}

	_wnd->display();
}