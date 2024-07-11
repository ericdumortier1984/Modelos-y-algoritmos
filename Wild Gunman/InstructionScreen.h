#pragma once // Asegura que este archivo de encabezado solo se incluya una vez en el proyecto
#include "Include&using.h" //Incluye los archivos de encabezado necesarios
#include "Player.h" // Incluye la definición de la clase Player

class InstructionScreen : public Player // La clase InstructionScreen hereda de la clase Player
{
protected: // Miembros protegidos, accesibles solo dentro de la clase y las clases derivadas

	Text _gameNameText, _instructionText1, _instructionText2, _instructionText3, _instructionText4, _startGameText; // Objetos de texto para mostrar la información
	Font _font; // Fuente utilizada para los textos
	bool _startGame; // Bandera para indicar si se debe iniciar el juego

public: // Miembros públicos, accesibles desde cualquier parte del programa

	InstructionScreen(); // Constructor de la clase
	void Show(RenderWindow* _wnd); // Función para mostrar la pantalla de instrucciones en la ventana de renderizado
};

