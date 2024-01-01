#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "PlayerCrosshair.h"
#include "Enemy.h"

using namespace std;
using namespace sf;

class Game {
private:
	RenderWindow* _wnd;
	PlayerCrosshair* _player;
	Enemy* _enemy;
	Text puntaje;
	Font font;
	Sprite fondoSprite;
	Texture fondoTexture;
	Sprite moonSprite;
	Texture moonTexture;
	int puntos;

	void ActualizarPuntaje();

public:
	Game();
	void Loop();
	void ProcesarEventos();
	void Disparar();
	void Actualizar();
	void Dibujar();
	~Game();
};
