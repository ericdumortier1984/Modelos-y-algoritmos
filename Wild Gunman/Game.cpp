#include "Game.h" // Incluye el archivo de encabezado de la clase Game

Game::Game() // Constructor de la clase Game
{

	// Crea la ventana de renderizado
	_wnd = new RenderWindow(VideoMode(800, 600), "Wild Gunman");
	_fps = 60;
	_wnd->setFramerateLimit(_fps);
	_wnd->setMouseCursorVisible(false);

	audioManager.InitAudio();

	// Crea los objetos pantalla de inicio y el crosshair
	_inst_Screen = new InstructionScreen;
	crosshair = new Player;
	
	// Inicializa las variables de juego
	_score = 0, _lifes = 3;
	_GameOver = false;
	_YouWin = false;
	_ShowBang = false;
	
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

	InitEnemies();
}

void Game::Loop() // Función principal del bucle del juego
{

	_inst_Screen->Show(_wnd); // Muestra la pantalla de instrucciones

	while (_wnd->isOpen() && !_GameOver) // Entra en el bucle principal del juego
	{
		DrawGame(); // Dibuja los elementos del juego
		Events(); // Maneja los eventos del juego
		GameOverConditions(); // Verifica las condiciones de fin de juego
	}
}

void Game::Events() // Función para manejar los eventos del juego
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
			crosshair->SetPosition(evt.mouseMove.x, evt.mouseMove.y); // Actualiza la posición de la mira
			break;
			
		case Event::MouseButtonPressed:
			if (evt.mouseButton.button == Mouse::Button::Left) 
			{
				audioManager.PlayGunShot();
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

void Game::InitEnemies() // Función para inicializar los enemigos
{

	bool posNOT[5] = {false, false, false, false, false}; // Arreglo para indicar si una posición está ocupada
	// Crea y agrega los enemigos al vector
	for (int i = 0; i < 4; i++)
	{
		int randomPos;
		do 
		{
			randomPos = rand() % 5; // Selecciona una posición aleatoria
		} while (posNOT[randomPos]); // Verifica que la posición no esté ocupada
		{
			if (randomPos == 0)
			{
				enemies.push_back(new Enemy("Assets/imagenes/Innocent.png", windowSaloonPos[0], true));
			}
			else if (randomPos == 1)
			{
				enemies.push_back(new Enemy("Assets/imagenes/Enemy1.png", windowSaloonPos[1], false));
			}
			else if (randomPos == 2)
			{
				enemies.push_back(new Enemy("Assets/imagenes/Enemy2.png", windowSaloonPos[2], false));
			}
			else if (randomPos == 3)
			{
				enemies.push_back(new Enemy("Assets/imagenes/Enemy3.png", windowSaloonPos[3], false));
			}
			else
				posNOT[randomPos] = true; // Marca la posición como ocupada
		}
	}
}

void Game::GameOverConditions() // Función para verificar las condiciones de fin de juego
{
	
	// Si el juego ha terminado, no se hace nada más
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

void Game::LifeUpdate() // Función para actualizar las vidas
{
	_textLifes.setString("Lifes: " + to_string(_lifes));
}

void Game::ScoreUpdate() // Función para actualizar el puntaje
{
	_textScore.setString("Score: " + to_string(_score));
}

void Game::FinalScore() // Función para mostrar el puntaje final
{
	_textFinalScore.setString("Final Score: " + to_string ((_score - (3 - _lifes)) * 10));
}

void Game::CheckCollision() // Función para verificar las colisiones
{
	Vector2f playerPos = crosshair->Getpos();

	// Actualiza el puntaje y las vidas
	ScoreUpdate();
	LifeUpdate();
}

void Game::ShotAtPlayer() // Función para manejar los disparos al jugador
{
    _ShowBang = true;
	_lifes-- && _score--;
	LifeUpdate();
	ScoreUpdate();
}

void Game::DrawGame() // Función para dibujar los elementos del juego
{
	_wnd->clear();

	// Dibuja los enemigos
	for (Enemy* enemy : enemies)
	{
		if (enemy->UpdateEnemy(clock.restart()))
		{
			enemy->setVisible(true);
			enemy->Draw(_wnd);
		}
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

void Game::RestartGame() // Función para reiniciar el juego
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
