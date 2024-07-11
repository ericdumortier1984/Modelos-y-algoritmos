#pragma once // Asegura que este archivo de encabezado solo se incluya una vez en el proyecto
#include "Include&using.h" // Incluye los archivos de encabezado necesarios
#include "Player.h" // Incluye el archivo de encabezado de la clase Player
#include "InstructionScreen.h" // Incluye el archivo de encabezado de la clase InstructionScreen
#include "Enemy.h" // Incluye el archivo de encabezado de la clase Enemy

class Game // Definici�n de la clase Game
{
private: // Miembros privados, accesibles solo dentro de la clase

	// Arreglo de posiciones de las ventanas y la puerta del saloon
	const Vector2f windowSaloonPos[5] =
	{
	Vector2f(140.0, 150.0), // Ventana 1
	Vector2f(600.0, 150.0), // Ventana 2
	Vector2f(120.0, 350.0), // Ventana 3
	Vector2f(620.0, 350.0), // Ventana 4
	Vector2f(370.0, 350.0), // Puerta
	};
	RenderWindow* _wnd; // Puntero a la ventana de renderizado
	Player* crosshair; // Puntero al objeto Player (mira del jugador)
	vector<Enemy*> enemies; // Vector de punteros a objetos Enemy (enemigos)
	InstructionScreen* _inst_Screen; // Puntero al objeto InstructionScreen
	Sprite* saloon; // Sprite del saloon
	Texture* saloonTexture; // Textura del saloon

	Text _textScore, _textLifes, _textGameOver, _textWin, _textFinalScore; // Objetos Text para mostrar informaci�n en pantalla
	Font _font; // Fuente utilizada para los textos

	int _score, _lifes, _fps; // Variables para almacenar el puntaje, vidas y FPS

	bool _GameOver; // Bandera para indicar si el juego ha terminado
	bool _YouWin; // Bandera para indicar si el jugador ha ganado
	bool _ShowBang; // Bandera para indicar si se debe mostrar el efecto de disparo
	
public: // Miembros p�blicos, accesibles desde cualquier parte del programa

	Game(); // Constructor de la clase Game
	~Game(); // Destructor de la clase Game

	void Loop(); // Funci�n principal del bucle del juego
	void Events(); // Funci�n para manejar los eventos del juego
	void GameOverConditions(); // Funci�n para verificar las condiciones de fin de juego
	void CheckCollision(); // Funci�n para verificar las colisiones
	void ShotAtPlayer(); // Funci�n para manejar los disparos al jugador
	void InitEnemies(); // Funci�n para inicializar los enemigos
	void DrawGame(); // Funci�n para dibujar los elementos del juego
	void RestartGame(); // Funci�n para reiniciar el juego
	void ScoreUpdate(); // Funci�n para actualizar el puntaje
	void LifeUpdate(); // Funci�n para actualizar las vidas
	void FinalScore(); // Funci�n para mostrar el puntaje final
};

