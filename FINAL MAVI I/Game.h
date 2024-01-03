#include "stdafx.h"
#include "Menu.h"

class Game {
private:
	//Ventana principal
	RenderWindow* MENU;
	//Opciones de Menu
	MainMenu* mainMenu;
	//Personaje
	Sprite mikeSp;
	Texture mikeTx;
	int lifes;
	//Obstaculos
	Sprite wheelSp;
	Texture wheelTx;
	//Fondos
	Sprite fondoPlaySp;
	Texture fondoPlayTx;
	Sprite moonSp;
	Texture moonTx;
	Sprite caminoSp;
	Texture caminoTx;
	Sprite pastoSp;
	Texture pastoTx;
	Sprite paisajeSp;
	Texture paisajeTx;
	Sprite cavermanOneSp;
	Texture cavermanOneTx;
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
