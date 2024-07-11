#pragma once // Asegura que este archivo de encabezado solo se incluya una vez en el proyecto
#include "Include&using.h" // Incluye los archivos de encabezado necesarios

class Player // Definici�n de la clase Player
{
protected: // Miembros protegidos, accesibles solo dentro de la clase y las clases derivadas

	Sprite* sprite; // Puntero a un objeto Sprite
	Texture* texture; // Puntero a un objeto Texture

public: // Miembros p�blicos, accesibles desde cualquier parte del programa

	Player(); // Constructor de la clase
	~Player(); // Destructor de la clase

	void Draw(RenderWindow* _wnd); // Funci�n para dibujar el sprite en la ventana de renderizado
	void SetPosition(float x, float y); // Funci�n para establecer la posici�n del sprite
	Vector2f Getpos(); // Funci�n para obtener la posici�n actual del sprite
};

