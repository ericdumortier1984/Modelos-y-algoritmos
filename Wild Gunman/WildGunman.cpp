#include "include&using.h" // Incluye los archivos de encabezado necesarios
#include "Game.h" // Incluye el archivo de encabezado de la clase Game

int main() // Función principal del programa
{

	srand(time(NULL));
	Game* myGame; // Crea una instancia de la clase Game
	myGame = new Game;
	myGame->Loop(); // Llama a la función Loop() de la clase Game para iniciar el juego

	return 0; // Retorna 0 para indicar que el programa finalizó correctamente
}