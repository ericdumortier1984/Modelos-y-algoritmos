#pragma once // Asegura que este archivo de encabezado solo se incluya una vez en el proyecto
#include "Include&using.h" // Incluye los archivos de encabezado necesarios

class Enemy // Definición de la clase Enemy
{
private: // Miembros privados, accesibles solo dentro de la clase

	Sprite* sprite; // Sprite del enemigo
	Texture* texture; // Textura del enemigo
	Vector2f position; // Posición del enemigo
	bool isInnocent; // Bandera que indica si el enemigo es inocente o no

public: // Miembros públicos, accesibles desde cualquier parte del programa

	Enemy(const string& texturePath, const Vector2f& pos, bool innocent); // Constructor de la clase Enemy
	~Enemy(); // Destructor de la clase Enemy

	void Draw(RenderWindow* _wnd); // Función para dibujar el enemigo en la ventana de renderizado
	const Vector2f& GetPosition() const // Obtiene la posición del enemigo
	{
		return sprite->getPosition();
	}
	bool IsInnocent() const // Obtiene si el enemigo es inocente o no
	{
		return isInnocent;
	}
};
