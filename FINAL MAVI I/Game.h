#include "stdafx.h"
#include "Menu.h"
#include "Backgrounds.h"
#include "Mike.h"
#include "Obstacles.h"

class Game {
private:
	//Ventana principal
	RenderWindow* MENU;
	//Opciones de Menu
	MainMenu* mainMenu;
	//Personaje
	Mike* mike;
	//Obstaculos
	Obstacles* wheel;
	Obstacles* pinche;
	//Fondos
	Backgrounds* fondoPlay;
	Backgrounds* moon;
	Backgrounds* camino;
	Backgrounds* pasto;
	Backgrounds* paisaje;
	Backgrounds* cavermanOne;
	//Musica y Sonidos
	Music music;

	void ProcessEvents();
	void Update(float deltaTime);
public:
	Game();
	~Game();

	void Go();
};
