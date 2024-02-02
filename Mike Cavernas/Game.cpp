#include "Game.h"

Game::Game() 
{
	srand(time(NULL));
	_randomX = rand() % 700;

	_wnd = new RenderWindow(VideoMode(800, 600), "Mike Cavernas");
	_wnd->setFramerateLimit(30);
	_wnd->setMouseCursorVisible(false);

	_estala = new Estalactita;
	_estala->SetPosition(Vector2f(_randomX, -30.0f));

	_ptero = new Pterodactile;
	_ptero->SetPosition(Vector2f(830.0f, 230.0f));

	_mike = new Mike(3, 0);
	_mike->SetPosition(Vector2f(30.0f, 500.0f));

	_chicken = new Item();
	_chicken->SetPosition(Vector2f(_randomX, 520.0f));

	_key = new Key();
	_key->SetPosition(Vector2f(370.0f, 350));

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

	_musicWinner.openFromFile("Asset/Audio/Musica_ganador.ogg");
	_musicWinner.setLoop(true);
	_musicWinner.setVolume(75);

	_woohooBf.loadFromFile("Asset/Audio/Woo_hoo.wav");
	_woohoo.setBuffer(_woohooBf);
	_woohoo.setVolume(50);

	_dohBf.loadFromFile("Asset/Audio/Doh.wav");
	_doh.setBuffer(_dohBf);
	_doh.setVolume(50);

	_font.loadFromFile("Asset/Font/junegull.ttf");
	_titleText.setFont(_font);
	_titleText.setCharacterSize(100);
	_titleText.setFillColor(Color::White);
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
	_restartText.setFont(_font);
	_restartText.setCharacterSize(20);
	_restartText.setFillColor(Color::Black);
	_restartText.setString("PRESS R TO RESTART");
	_restartText.setPosition(150.0f, 0.0f);

	_font.loadFromFile("Asset/Font/junegull.ttf");
	_pauseText.setFont(_font);
	_pauseText.setCharacterSize(20);
	_pauseText.setFillColor(Color::Black);
	_pauseText.setString("PRESS P TO PAUSE");
	_pauseText.setPosition(400.0f, 0.0f);

	_font.loadFromFile("Asset/Font/junegull.ttf");
	_signTextOne.setFont(_font);
	_signTextOne.setCharacterSize(12);
	_signTextOne.setFillColor(Color::Black);
	_signTextOne.setString("GET  1000  POINTS");
	_signTextOne.setPosition(115.0f, 490.0f);

	_font.loadFromFile("Asset/Font/junegull.ttf");
	_signTextTwo.setFont(_font);
	_signTextTwo.setCharacterSize(12);
	_signTextTwo.setFillColor(Color::Black);
	_signTextTwo.setString("THEN  GET THE  KEY");
	_signTextTwo.setPosition(120.0f, 510.0f);

	_startTx.loadFromFile("Asset/Images/Start.png");
	_startButton.setTexture(_startTx);
	_startButton.setOrigin(_startButton.getLocalBounds().width / 2, 0);
	_startButton.setPosition(400.0f, 200.0f);

	_infoTx.loadFromFile("Asset/Images/Info.png");
	_infoButton.setTexture(_infoTx);
	_infoButton.setOrigin(_infoButton.getLocalBounds().width / 2, 0);
	_infoButton.setPosition(50.0f, 0.0f);

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
	delete _key;
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
				if (!_gameStarted && GetInfoPressed(evt.mouseButton.x, evt.mouseButton.y)) {
					_wnd->setMouseCursorVisible(false);
					ShowInfoScreen();
				}
			}
		}
		if (evt.type == Event::MouseButtonPressed) {
			if (evt.mouseButton.button == Mouse::Left) {
				if (!_gameStarted && GetStartPressed(evt.mouseButton.x, evt.mouseButton.y)) {
					_gameStarted = true;
					_wnd->setMouseCursorVisible(false);
					_musicPrincipal.stop();
					_musicGameOver.stop();
					_musicWinner.stop();
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

	//Movimientos de personajes y obstaculos
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
	else if ((_mike->GetPosition().x >= 0.0f && _mike->GetPosition().x <= 300.0f && _mike->GetPosition().y <= 500.0f) || (_mike->GetPosition().x >= 400.0f && _mike->GetPosition().x <= 800.0f && _mike->GetPosition().y <= 500.0f)) {
		_mike->AddAcceleration(Vector2f(0.0f, 150.0f));
	}
	else {
		_mike->SetVelocity(Vector2f(0.0f, 0.0f));
	}

	_estala->SetVelocity(Vector2f(0.0f, 150.0f));
	if (_estala->GetPosition().y > 600) {
		_estala->SetPosition(Vector2f(rand() % 700, -30.0f));
	}
	else if (_mike->GetPoints() >= 500) {
		_estala->SetVelocity(Vector2f(0.0f, 250.0f));
	}
	else if (_mike->GetPoints() >= 900) {
		_estala->SetVelocity(Vector2f(0.0f, 350.0f));
	}
	
	_ptero->SetVelocity(Vector2f(-150.0f, 00.0f));
	if (_ptero->GetPosition().x < 0.0f) {
		_ptero->SetPosition(Vector2f(830.0f, 300.0f));
	}
	
	_mike->Update(deltaTime);
	_mike->UpdateOrientation();
	_estala->Update(deltaTime);
	_ptero->Update(deltaTime);
	_chicken->Update(deltaTime);
	_key->Update(deltaTime);

	//Condiciones del juego
	if (_mike->GetPoints() >= 1000) {
		_key->SetKeyVisible(true);
	}

	if (_gameStarted) {
		if (_mike->GetLifes() == 0) {
			GameOver();
			RestartGame();
		}
		else if (_key->IsKeyActive() && _mike->GetKey(_key->GetPosition().x, _key->GetPosition().y)) {
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

		Vector2f keyPos = _key->GetPosition();
		if (_key->IsKeyActive()) {
			if (_mike->GetKey(keyPos.x, keyPos.y)) {
				RespawnKey();
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

void Game::RespawnKey()
{

	_key->SetPosition(Vector2f(830.0f, 300.0f));
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

bool Game::GetInfoPressed(float x, float y)
{

	FloatRect bounds_infoButton = _infoButton.getGlobalBounds();
	return bounds_infoButton.contains(x, y);
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
	_musicPrincipal.stop();
	_musicLevel.stop();
	_musicGameOver.play();
	ShowGameOverScreen();
}

void Game::ShowInfoScreen()
{

	RenderWindow _info_wnd(VideoMode(800, 600),"INFO");

	_infoBackgroundTx.loadFromFile("Asset/Images/Info_background.png");
	_infoBackground.setTexture(_infoBackgroundTx);
	_infoBackground.setPosition(-100.0f, 0.0f);

	vector<Text> moveTexts;
	vector<string> instructions = { "MATERIA: MAVI I", "", "MOVES OF MIKE", "FORWARD: KEY D", "BACKWARD: KEY A", "UP: KEY W", "DOWN: KEY S", "", "GAME FUNCTIONS", "PAUSE GAME: KEY P", "RESTART GAME: KEY R"};

	_font.loadFromFile("Asset/Font/junegull.ttf");

	for (int i = 0; i < instructions.size(); i++) {
	
		_text.setFont(_font);
		_text.setCharacterSize(40);
		_text.setString(instructions[i]);
		_text.setFillColor(Color::Black);
		_text.setPosition(250.0f, 0.0f + i * 50);
		moveTexts.push_back(_text);
	}

	_font.loadFromFile("Asset/Font/junegull.ttf");
	_returnText.setFont(_font);
	_returnText.setCharacterSize(40);
	_returnText.setFillColor(Color::Red);
	_returnText.setString("PRESS ESCAPE TO RETURN TO MAIN MENU");
	_returnText.setOrigin(_returnText.getLocalBounds().width / 2, 0);
	_returnText.setPosition(400.0f, 550.0f);

	while (_info_wnd.isOpen()) {
		Event ev;
		while (_info_wnd.pollEvent(ev)) {
			if (ev.type == Event::Closed) {
				_info_wnd.close();
			}
			if (ev.key.code == Keyboard::Escape) {
				_info_wnd.close();
			}
		}
		_info_wnd.clear();
		_info_wnd.draw(_infoBackground);

		for (const auto& _text : moveTexts) {
			_info_wnd.draw(_text);
		}

		_info_wnd.draw(_returnText);
		_info_wnd.display();
	}
}

void Game::ShowGameOverScreen()
{

	RenderWindow _gameOver_wnd(VideoMode(800, 600), "GAME OVER");

	_loseBackgroundTx.loadFromFile("Asset/Images/Lose_background.png");
	_loseBackground.setTexture(_loseBackgroundTx);

	_gameOverSignTx.loadFromFile("Asset/Images/Game_over.png");
	_gameOverSign.setTexture(_gameOverSignTx);
	_gameOverSign.setOrigin(_gameOverSign.getLocalBounds().width / 2, 0);
	_gameOverSign.setPosition(400.0f, 200.0f);

	_font.loadFromFile("Asset/Font/junegull.ttf");
	_loseText.setFont(_font);
	_loseText.setCharacterSize(40);
	_loseText.setFillColor(Color::Red);
	_loseText.setString("PRESS ESCAPE TO RETURN TO MAIN MENU");
	_loseText.setOrigin(_loseText.getLocalBounds().width / 2, 0);
	_loseText.setPosition(400.0f, 100.0f);

	while (_gameOver_wnd.isOpen()) {
		Event event;
		while (_gameOver_wnd.pollEvent(event)) {
			if (event.type == Event::Closed) {
				_gameOver_wnd.close();
			}
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Escape) {
					_gameOver_wnd.close();
				}
			}
		}
		_gameOver_wnd.clear();
		_gameOver_wnd.draw(_loseBackground);
		_gameOver_wnd.draw(_loseText);
		_gameOver_wnd.draw(_gameOverSign);
		_gameOver_wnd.display();
	}
}

void Game::YouWin()
{

	_youWin = true;
	_musicPrincipal.stop();
	_musicLevel.stop();
	_musicWinner.play();
	ShowWinnerScreen();
}

void Game::ShowWinnerScreen()
{

	RenderWindow _winner_wnd(VideoMode(800, 600), "YOU WIN");

	_winBackgroundTx.loadFromFile("Asset/Images/Win_background.png");
	_winBackground.setTexture(_winBackgroundTx);

	_font.loadFromFile("Asset/Font/junegull.ttf");
	_winText.setFont(_font);
	_winText.setCharacterSize(40);
	_winText.setFillColor(Color::Red);
	_winText.setString("PRESS ESCAPE TO RETURN TO MAIN MENU");
	_winText.setOrigin(_winText.getLocalBounds().width / 2, 0);
	_winText.setPosition(400.0f, 170.0f);

	_font.loadFromFile("Asset/Font/junegull.ttf");
	_winnerText.setFont(_font);
	_winnerText.setCharacterSize(60);
	_winnerText.setFillColor(Color::Black);
	_winnerText.setString("YOU MADE IT");
	_winnerText.setOrigin(_winnerText.getLocalBounds().width / 2, 0);
	_winnerText.setPosition(400.0f, 50.0f);

	int final_score = UpdatePoints();

	_hiScoreText.setFont(_font);
	_hiScoreText.setCharacterSize(40);
	_hiScoreText.setFillColor(Color::Black);
	_hiScoreText.setString("Hi Score: " + to_string(final_score));
	_hiScoreText.setOrigin(_hiScoreText.getLocalBounds().width / 2, 0);
	_hiScoreText.setPosition(420.0f, 120.0f);

	while (_winner_wnd.isOpen()) {
		Event e;
		while (_winner_wnd.pollEvent(e)) {
			if (e.type == Event::Closed) { 
				_winner_wnd.close();
			}
			if (e.type == Event::KeyPressed) {
				if (e.key.code == Keyboard::Escape) {
					_winner_wnd.close();
				}
			}
		}
		_winner_wnd.clear(Color::Black);
		_winner_wnd.draw(_winBackground);
		_winner_wnd.draw(_winText);
		_winner_wnd.draw(_winnerText);
		_winner_wnd.draw(_hiScoreText);
		_winner_wnd.display();
	}
}

void Game::Draw() 
{

	_wnd->clear();

	if (!_gameStarted) {
		_wnd->draw(_landscape);
		_wnd->draw(_titleText);
		_wnd->draw(_infoButton);
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
		_wnd->draw(_restartText);
		_wnd->draw(_pauseText);
		_wnd->draw(_signTextOne);
		_wnd->draw(_signTextTwo);
		_estala->Draw(_wnd);
		_ptero->Draw(_wnd);
		_chicken->Draw(_wnd);
		if (_mike->GetPoints() >= 1000) {
			_key->Draw(_wnd);
		}
		_mike->Draw(_wnd);
	}

	_wnd->display();
}