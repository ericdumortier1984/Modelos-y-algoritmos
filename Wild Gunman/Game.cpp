#include "Game.h" // Incluye el archivo de encabezado de la clase Game

Game::Game() // Constructor de la clase Game
{

	// Crea la ventana de renderizado
	_wnd = new RenderWindow(VideoMode(800, 600), "Wild Gunman");
	_fps = 60;
	_wnd->setFramerateLimit(_fps);
	_wnd->setMouseCursorVisible(false);

	// Crea los objetos pantalla de inicio y el crosshair
	_inst_Screen = new InstructionScreen;
	crosshair = new Player;
	
	// Inicializa las variables de juego
	_score = 0, _lifes = 3;
	_GameOver = false;
	_YouWin = false;
	_ShowBang = false;
	
	// Inicializa los enemigos
	InitEnemies();

	// Carga la textura y el sprite del saloon
	saloonTexture = new Texture;
	saloon = new Sprite;
	saloonTexture->loadFromFile("Assets/imagenes/saloon.png");
	saloon->setTexture(*saloonTexture);
	saloon->setPosition(0.0, 100.0);

	// Carga las fuentes y configura los textos
	_font.loadFromFile("Assets/font/RioGrande.ttf");
	_textScore.setFont(_font);
	_textScore.setString("Score: 0");
	_textScore.setFillColor(Color::Magenta);
	_textScore.setPosition(20, 550);
	_textLifes.setFont(_font);
	_textLifes.setString("Lifes: 3");
	_textLifes.setFillColor(Color::Magenta);
	_textLifes.setPosition(650, 550);
	_textGameOver.setFont(_font);
	_textGameOver.setString("GameOver");
	_textGameOver.setFillColor(Color::Black);
	_textGameOver.setCharacterSize(42);
	_textGameOver.setPosition(300, 500);
	_textWin.setFont(_font);
	_textWin.setString("You Win ENTER para reiniciar");
	_textWin.setCharacterSize(32);
	_textWin.setPosition(180, 50);
	_textWin.setFillColor(Color::Green);
	_textFinalScore.setFont(_font);
	_textFinalScore.setString("Final Score: ");
	_textFinalScore.setCharacterSize(50);
	_textFinalScore.setPosition(230, 550);
	_textFinalScore.setFillColor(Color::Yellow);

}

void Game::Loop() // Funci�n principal del bucle del juego
{

	_inst_Screen->Show(_wnd); // Muestra la pantalla de instrucciones

	while (_wnd->isOpen()) // Entra en el bucle principal del juego
	{
		DrawGame(); // Dibuja los elementos del juego
		Events(); // Maneja los eventos del juego
		GameOverConditions(); // Verifica las condiciones de fin de juego
	}
}

void Game::Events() // Funci�n para manejar los eventos del juego
{
	
	// Procesa los eventos de la ventana
	Event evt;
	while (_wnd->pollEvent(evt)) 
	{
		switch (evt.type) 
		{
		case Event::Closed:
			_wnd->close(); // Cierra la ventana
			break;
			
		case Event::MouseMoved:
			crosshair->SetPosition(evt.mouseMove.x, evt.mouseMove.y); // Actualiza la posici�n de la mira
			break;
			
		case Event::MouseButtonPressed:
			if (evt.mouseButton.button == Mouse::Button::Left) 
			{
				CheckCollision(); // Verifica las colisiones al hacer clic
			}
			break;
			
		case Event::KeyPressed:
			if (evt.key.code == Keyboard::Escape) 
			{
				_wnd->close(); // Cierra la ventana al presionar Esc
			}
			if (evt.key.code == Keyboard::Enter && _YouWin)
			{
				RestartGame(); // Reinicia el juego al presionar Enter cuando se gana
			}
			break;
		default:
			break;
		}
	}
}

void Game::InitEnemies() // Funci�n para inicializar los enemigos
{

	// Crea y agrega los enemigos al vector
	enemies.push_back(new Enemy("Assets/imagenes/Innocent.png", windowSaloonPos[0], true));
	enemies.push_back(new Enemy("Assets/imagenes/Enemy1.png", windowSaloonPos[1], false));
	enemies.push_back(new Enemy("Assets/imagenes/Enemy2.png", windowSaloonPos[2], false));
	enemies.push_back(new Enemy("Assets/imagenes/Enemy3.png", windowSaloonPos[3], false));
}

void Game::GameOverConditions() // Funci�n para verificar las condiciones de fin de juego
{
	
	// Si el juego ha terminado, no se hace nada m�s
	if (_GameOver || _YouWin) 
	{
		return; 
		
		// Verifica si el jugador ha ganado o perdido
		if (_score == 10) 
		{
			_YouWin = true;
			FinalScore();
		}
		if (_lifes == 0) 
		{
			_GameOver = true;
			FinalScore();
		}
	}
}

void Game::LifeUpdate() // Funci�n para actualizar las vidas
{
	_textLifes.setString("Lifes: " + to_string(_lifes));
}

void Game::ScoreUpdate() // Funci�n para actualizar el puntaje
{
	_textScore.setString("Score: " + to_string(_score));
}

void Game::FinalScore() // Funci�n para mostrar el puntaje final
{
	_textFinalScore.setString("Final Score: " + to_string ((_score - (3 - _lifes)) * 10));
}

void Game::CheckCollision() // Funci�n para verificar las colisiones
{
	Vector2f playerPos = crosshair->Getpos();

	// Actualiza el puntaje y las vidas
	ScoreUpdate();
	LifeUpdate();
}

void Game::ShotAtPlayer() // Funci�n para manejar los disparos al jugador
{
    _ShowBang = true;
	_lifes-- && _score--;
	LifeUpdate();
	ScoreUpdate();
}

void Game::DrawGame() // Funci�n para dibujar los elementos del juego
{
	_wnd->clear();

	// Dibuja los enemigos
	for (Enemy* _enemies : enemies)
	{
		_enemies->Draw(_wnd);
	}
	
	_wnd->draw(*saloon); // Dibuja el saloon
	crosshair->Draw(_wnd); // Dibuja la mira del jugador
	
	// Dibuja los textos de GameOver o You Win
	if (_GameOver) 
	{
		_wnd->draw(_textGameOver);
		_wnd->draw(_textFinalScore);
		_wnd->setMouseCursorVisible(true);
	}

	else if (_YouWin) 
	{
		_wnd->draw(_textWin);
		_wnd->draw(_textFinalScore);
	}

	// Dibuja el puntaje y las vidas
	_wnd->draw(_textScore);
	_wnd->draw(_textLifes);
	
	_wnd->display();
}

void Game::RestartGame() // Funci�n para reiniciar el juego
{
	
	// Restablece las variables del juego
	_wnd->setMouseCursorVisible(false);
	_score = 0;
	_lifes = 3;
	_GameOver = false;
	_YouWin = false;
	_ShowBang = false;
	
	// Actualiza para reiniciar el puntaje, las vidas y el puntaje final 
	ScoreUpdate();
	LifeUpdate();
	FinalScore();
}

Game::~Game() // Destructor de la clase Game
{

	// Libera la memoria ocupada por los objetos
	delete crosshair;
	delete saloon;
	delete saloonTexture;
	delete _wnd;
}
