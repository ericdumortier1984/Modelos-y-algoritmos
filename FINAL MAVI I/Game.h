#include "stdafx.h"
#include "Menu.h"
#include "Backgrounds.h"
#include "Mike.h"

class Game {
private:
	//Ventana principal
	RenderWindow* MENU;
	//Opciones de Menu
	MainMenu* mainMenu;
	//Personaje
	Mike* mike;
	//Obstaculos
	Sprite wheelSp;
	Texture wheelTx;
	//Fondos
	Backgrounds* fondoPlay;
	Backgrounds* moon;
	Backgrounds* camino;
	Backgrounds* pasto;
	Backgrounds* paisaje;
	Backgrounds* cavermanOne;
	//Musica y Sonidos
	Music music;

	Vector2f position;
	Vector2f velocity;
	const float acceleration = 10.0f;

	void ProcessEvents();
public:
	Game();
	~Game();

	void SetPosition(Vector2f pos) { position = pos; };
	void SetVelocity(Vector2f vel) { velocity = vel; }
	Vector2f GetPosition() { return position; };
	Vector2f GetVelocity() { return velocity; };
	void Go();
};
