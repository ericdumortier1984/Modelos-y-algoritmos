#include "Game.h"

Game::Game() 
{
	srand(time(NULL));
	_randomX = rand() % 700;

	_wnd = new RenderWindow(VideoMode(800, 600), "Mike Cavernas");
	_wnd->setFramerateLimit(60);
	_wnd->setMouseCursorVisible(false);

	_estala = new Estalactita;
	_ptero = new Pterodactile;
	_estala->SetPosition(Vector2f(_randomX, -30.0f));
	_ptero->SetPosition(Vector2f(830.0f, 230.0f));

	_mike = new Mike(3, 0);
	_mike->SetPosition(Vector2f(30.0f, 500.0f));

	_chicken = new Item();
	_chicken->SetPosition(Vector2f(_randomX, 520.0f));
	_key = new Item();
	_key->SetKeyPosition(Vector2f(300.0f, 300.0f));

	_cursor = new Menu();

	_restartGame = false;
	_gameOver = false;
	_youWin = false;

	_musicPrincipal.openFromFile("Asset/Audio/Musica_principal.ogg");
	_musicPrincipal.setLoop(true);
	_musicPrincipal.setVolume(75);
	_musicPrincipal.play();

	_musicLevel.openFromFile("Asset/Audio/Musica_nivel.ogg");
	_musicLevel.setLoop(true);
	_musicLevel.setVolume(25);

	_musicGameOver.openFromFile("Asset/Audio/Musica_game_over.ogg");
	_musicGameOver.setLoop(true);
	_musicGameOver.setVolume(75);

	_woohooBf.loadFromFile("Asset/Audio/Woo_hoo.wav");
	_woohoo.setBuffer(_woohooBf);
	_woohoo.setVolume(50);

	_dohBf.loadFromFile("Asset/Audio/Doh.wav");
	_doh.setBuffer(_dohBf);
	_doh.setVolume(50);

	_font.loadFromFile("Asset/Font/junegull.ttf");
	_titleText.setFont(_font);
	_titleText.setCharacterSize(50);
	_titleText.setFillColor(Color::Black);
	_titleText.setString("MIKE CAVERNAS");
	_titleText.setOrigin(_titleText.getLocalBounds().width / 2, 0);
	_titleText.setPosition(400.0f, 100.0f);

	_font.loadFromFile("Asset/Font/junegull.ttf");
	_lifesText.setFont(_font);
	_lifesText.setCharacterSize(20);
	_lifesText.setFillColor(Color::Black);
	_lifesText.setString("MIKE: 3");
	_lifesText.setPosition(0.0f, 0.0f);

	_font.loadFromFile("Asset/Font/junegull.ttf");
	_pointsText.setFont(_font);
	_pointsText.setCharacterSize(20);
	_pointsText.setFillColor(Color::Black);
	_pointsText.setString("POINTS: 0");
	_pointsText.setPosition(650.0f, 0.0f);

	_font.loadFromFile("Asset/Font/junegull.ttf");
	_winText.setFont(_font);
	_winText.setCharacterSize(40);
	_winText.setFillColor(Color::White);
	_winText.setString("YOU WIN");
	_winText.setPosition(550.0f, 100.0f);

	_font.loadFromFile("Asset/Font/junegull.ttf");
	_loseText.setFont(_font);
	_loseText.setCharacterSize(40);
	_loseText.setFillColor(Color::White);
	_loseText.setString("GAME OVER");
	_loseText.setPosition(550.0f, 100.0f);

	_font.loadFromFile("Asset/Font/junegull.ttf");
	_signTextOne.setFont(_font);
	_signTextOne.setCharacterSize(12);
	_signTextOne.setFillColor(Color::Black);
	_signTextOne.setString("TAKE FIVE CHICKEN");
	_signTextOne.setPosition(115.0f, 490.0f);

	_font.loadFromFile("Asset/Font/junegull.ttf");
	_signTextTwo.setFont(_font);
	_signTextTwo.setCharacterSize(12);
	_signTextTwo.setFillColor(Color::Black);
	_signTextTwo.setString("THEN GET THE KEY");
	_signTextTwo.setPosition(120.0f, 510.0f);

	_startTx.loadFromFile("Asset/Images/Start.png");
	_startButton.setTexture(_startTx);
	_startButton.setOrigin(_startButton.getLocalBounds().width / 2, 0);
	_startButton.setPosition(400.0f, 100.0f);
	
	_pathTx.loadFromFile("Asset/Images/RockPath.png");
	_path.setTexture(_pathTx);
	_path.setPosition(0.0f, 190.0f);

	_landscapeTx.loadFromFile("Asset/Images/Landscape.png");
	_landscape.setTexture(_landscapeTx);
	_landscape.setPosition(0.0f, 0.0f);

	_caveTx.loadFromFile("Asset/Images/Cave.png");
	_cave.setTexture(_caveTx);
	_cave.setPosition(0.0f, 30.0f);

	_stairTx.loadFromFile("Asset/Images/Stair_wood.png");
	_stair.setTexture(_stairTx);
	_stair.setPosition(300.0f, 390.0f);
	_stair.setOrigin(_stairTx.getSize().x / 2, 0);

	_levelTx.loadFromFile("Asset/Images/Level.png");
	_level.setTexture(_levelTx);
	_level.setPosition(200.0f, 290.0f);

	_signTx.loadFromFile("Asset/Images/Sign_2.png");
	_sign.setTexture(_signTx);
	_sign.setPosition(80.0f, 470.0f);
}

Game::~Game() 
{

	delete _mike;
	delete _chicken;
	delete _estala;
	delete _ptero;
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
				if (!_gameStarted && GetStartPressed(evt.mouseButton.x, evt.mouseButton.y)) {
					_gameStarted = true;
					_wnd->setMouseCursorVisible(false);
					_musicPrincipal.stop();
					_musicGameOver.stop();
					_musicLevel.play();
				}
			}
		}
		if (evt.type == Event::KeyPressed) {
			if (evt.key.code == Keyboard::P) {
				GamePause();
			}
		}
		if (evt.type == Event::KeyPressed) {
			if (evt.key.code == Keyboard::R) {
				RestartGame();
			}
		}
	}
}

void Game::Update(float deltaTime)
{

	//Movimientos
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		if (_mike->GetPosition().x >= 750.0f) 
			_mike->SetPosition(Vector2f(750.0f, _mike->GetPosition().y));
			_mike->SetVelocity(Vector2f(100.0f, 0.0f));
			if (_mike->GetPosition().y >= 300.0f && _mike->GetPosition().y <= 498)
				_mike->SetVelocity(Vector2f(0.0f, 0.0f));
	}
    else if (Keyboard::isKeyPressed(Keyboard::A)) {
		if (_mike->GetPosition().x <= 50.0f) 
			_mike->SetPosition(Vector2f(50.0f, _mike->GetPosition().y));
			_mike->SetVelocity(Vector2f(-100.0f, 0.0f));
			if (_mike->GetPosition().y >= 300.0f && _mike->GetPosition().y <= 498.0f)
				_mike->SetVelocity(Vector2f(0.0f, 0.0f));
	}
	else if (Keyboard::isKeyPressed(Keyboard::W)) {
		if (_mike->GetPosition().x >= 295.0f && _mike->GetPosition().x <= 305.0f) 
			_mike->SetVelocity(Vector2f(0.0f, -50.0f));
		if (_mike->GetPosition().y <= 300.0f)
			_mike->SetVelocity(Vector2f(0.0f, 0.0f));
	}
	else if (Keyboard::isKeyPressed(Keyboard::S)) {
		if (_mike->GetPosition().y >= 500.0f) 
			_mike->SetPosition(Vector2f(_mike->GetPosition().x, 500.0f));
			_mike->SetVelocity(Vector2f(0.0f, 50.0f));
	}
	else if (_mike->GetPosition().x >= 0.0f && _mike->GetPosition().x <= 800.0f && _mike->GetPosition().y <= 350.0f) {
		_mike->SetPosition(Vector2f(_mike->GetPosition().x, 500.0f));
	}
	else {
		_mike->SetVelocity(Vector2f(0.0f, 0.0f));
	}

	_estala->SetVelocity(Vector2f(0.0f, 150.0f));
	_estala->Update(deltaTime);
	if (_estala->GetPosition().y > 600) {
		_estala->SetPosition(Vector2f(rand() % 700, -30.0f));
	}

	_ptero->SetVelocity(Vector2f(-150.0f, 00.0f));
	_ptero->Update(deltaTime);
	if (_ptero->GetPosition().x < 0.0f) {
		_ptero->SetPosition(Vector2f(830.0f, 300.0f));
	}

	_mike->Update(deltaTime);
	_mike->UpdateOrientation();
	_chicken->Update(deltaTime);

	//Funciones
	if (_gameStarted) {
		if (_mike->GetLifes() == 0) {
			_musicLevel.stop();
			_musicGameOver.play();
			GameOver();
			RestartGame();
		}
		else if (_mike->GetPoints() == 1000) {
			_musicLevel.stop();
			YouWin();
			RestartGame();
		}
	}
}

void Game::CheckCollision() 
{

	    Vector2f estalaPos = _estala->GetPosition();
		if (_estala->isActive()) {
			if (_mike->GetPricked(estalaPos.x, estalaPos.y)) {
				_doh.play();
				_mike->Pricked();
				RespawnEstala();
			}
		}

	    Vector2f pteroPos = _ptero->GetPosition();
		if (_ptero->isActive()) {
			if (_mike->GetPricked(pteroPos.x, pteroPos.y)) {
				_doh.play();
				_mike->Pricked();
				RespawnPtero();
			}
		}
	
	    Vector2f chickenPos = _chicken->GetPosition();
	    if (_chicken->IsActive()) {
		   if (_mike->GetItem(chickenPos.x, chickenPos.y)) {
			   _woohoo.play();
			   _mike->PointUp();
			   RespawnChicken();
		   }
	    }
}

void Game::RespawnChicken()
{

	float _randomX = rand() % 700;
	_chicken->SetPosition(Vector2f(_randomX, 520.0f));
}

void Game::RespawnEstala()
{

	float _randomX = rand() % 700;
	_estala->SetPosition(Vector2f(_randomX, -30.0f));
	_estala->SetVelocity(Vector2f(0.0f, -30.0f));
}

void Game::RespawnPtero()
{

	_ptero->SetPosition(Vector2f(830.0f, 300.0f));
	_ptero->SetVelocity(Vector2f(20.0f, 0.0f));
}

int Game::UpdateLifes() 
{

	int _mikeLifes = _mike->GetLifes();
	_lifesText.setString("MIKE: " + to_string(_mikeLifes));

	return _mikeLifes;
}

int Game::UpdatePoints() 
{

	int _mikePoints = _mike->GetPoints();
	_pointsText.setString("POINTS: " + to_string(_mikePoints));

	return _mikePoints;
}

bool Game::GetStartPressed(float x, float y)
{

	FloatRect bounds_startButton = _startButton.getGlobalBounds();
	return bounds_startButton.contains(x, y);
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
	_restartGame = true;

	_mike = new Mike(3, 0);
	_mike->SetPosition(Vector2f(30.0f, 500.0f));
	_estala->SetPosition(Vector2f(_randomX, -30.0f));
	_ptero->SetPosition(Vector2f(830.0f, 200.0f));
	_chicken->SetPosition(Vector2f(_randomX, 520.0f));

	_musicLevel.stop();
	
	CheckCollision();
}

void Game::GamePause()
{

	if (_gameStarted) {
		_gameStarted = false;
		_musicLevel.stop();
	}
	else {
		_gameStarted = true;
		_musicLevel.play();
	}
}

void Game::GameOver()
{

	_gameOver = true;
}

void Game::YouWin()
{

	_youWin = true;
}

void Game::Draw() 
{

	_wnd->clear();

	if (!_gameStarted) {
		_wnd->draw(_landscape);
		_wnd->draw(_titleText);
		_wnd->draw(_startButton);
		_cursor->Draw(_wnd);
	}
	else {
		_wnd->clear(Color::Cyan);
		_wnd->draw(_cave);
		_wnd->draw(_path);
		_wnd->draw(_level);
		_wnd->draw(_stair);
		_wnd->draw(_sign);
		_wnd->draw(_lifesText);
		_wnd->draw(_pointsText);
		_wnd->draw(_signTextOne);
		_wnd->draw(_signTextTwo);
		_estala->Draw(_wnd);
		_ptero->Draw(_wnd);
		_chicken->Draw(_wnd);
		_key->Draw(_wnd);
		_mike->Draw(_wnd);
		if (_youWin && !_gameStarted) {
			_wnd->draw(_winText);
		}
		if (_gameOver && !_gameStarted) {
			_wnd->draw(_loseText);
		}
	}

	_wnd->display();
}