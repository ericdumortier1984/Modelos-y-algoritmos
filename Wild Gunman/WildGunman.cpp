#include "include&using.h" // Incluye los archivos de encabezado necesarios
#include "Game.h" // Incluye el archivo de encabezado de la clase Game

int main() // Funci�n principal del programa
{

	srand(time(NULL));
	Game* myGame; // Crea una instancia de la clase Game
	myGame = new Game;
	myGame->Loop(); // Llama a la funci�n Loop() de la clase Game para iniciar el juego

	return 0; // Retorna 0 para indicar que el programa finaliz� correctamente
}