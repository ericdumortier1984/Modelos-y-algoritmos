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
			if (evt.key.code == Keyboard::Enter && _YouWin || _GameOver)
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

	bool posNOT[5] = { false, false, false, false, false };
	int randomPos;
	string texturePath;
	bool innocent;

	// Selecciona una textura y posición aleatoria
	do
	{
		randomPos = rand() % 5;
		int randomTexture = rand() % 4;
		if (randomTexture == 0)
		{
			texturePath = "Assets/imagenes/Innocent.png";
			innocent = true;
		}
		else if (randomTexture == 1)
		{
			texturePath = "Assets/imagenes/Enemy1.png";
			innocent = false;
		}
		else if (randomTexture == 2)
		{
			texturePath = "Assets/imagenes/Enemy2.png";
			innocent = false;
		}
		else
		{
			texturePath = "Assets/imagenes/Enemy3.png";
			innocent = false;
		}
	} while (posNOT[randomPos]);
	{
		enemies.push_back(new Enemy(texturePath, windowSaloonPos[randomPos], innocent));
		posNOT[randomPos] = true;
	}
}

void Game::GameOverConditions() // Función para verificar las condiciones de fin de juego
{
	
	// Verifica si el jugador ha ganado
	if (_score >= 10)
	{
		_YouWin = true;
		_GameOver = true;
	}
	// Verifica si el jugador ha perdido
	else if (_lifes <= 0)
	{
		_GameOver = true;
	}

	// Actualiza el estado del juego
	if (_GameOver)
	{
		if (_YouWin)
		{
			_wnd->draw(_textWin);
		}
		else
		{
			_wnd->draw(_textGameOver);
		}
		FinalScore();
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

	for (int i = 0; i < enemies.size(); i++) // Recorre el vector de enemigos
	{
		if (enemies[i]->IsAbove(playerPos.x, playerPos.y)) // Verifica si el jugador hizo clic sobre un enemigo
		{
			if (enemies[i]->IsInnocent())
			{
				// Si el enemigo es inocente, resta un punto y una vida
				_score--;
				_lifes--;
				LifeUpdate();
				ScoreUpdate();
			}
			else
			{
			    // Si el enemigo no es inocente, suma un punto
				_score++;
				ScoreUpdate();
			}

			enemies.erase(enemies.begin() + i); // Elimina al enemigo del vector
			audioManager.PlayGunShot(); // Reproduce el sonido de disparo

			break; // Salimos del bucle, ya que solo puede haber un enemigo por clic
		}
	}
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

	// Dibuja el enemigo actual
	if (enemiesCounter < enemies.size() && enemies[enemiesCounter]->UpdateEnemy(clock.restart()))
	{
		enemies[enemiesCounter]->Draw(_wnd);
	}
	else
	{
		InitEnemies(); // Crea más enemigos
		enemiesCounter++;
		if (enemiesCounter >= enemies.size())
		{
			enemiesCounter = 0;
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
