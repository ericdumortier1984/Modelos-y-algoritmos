#include "InstructionScreen.h" // Incluye el archivo de encabezado de la clase InstructionScreen

InstructionScreen::InstructionScreen() // Constructor de la clase InstructionScreen
{
	
	_font.loadFromFile("Assets/font/RioGrande.ttf"); // Carga la fuente desde un archivo
	// Configura el texto del nombre del juego
	_gameNameText.setFont(_font);
	_gameNameText.setString("Wild Gunman");
	_gameNameText.setFillColor(Color::Yellow);
	_gameNameText.setPosition(270, 40);
	_gameNameText.setCharacterSize(42);

	// Configura el texto de la instrucción 1
	_font.loadFromFile("Assets/font/RioGrande.ttf");
	_instructionText1.setFont(_font);
	_instructionText1.setString("Instrucciones");
	_instructionText1.setFillColor(Color::Magenta);
	_instructionText1.setCharacterSize(30);
	_instructionText1.setPosition(40, 150);

	// Configura el texto de la instrucción 2
	_font.loadFromFile("Assets/font/RioGrande.ttf");
	_instructionText2.setFont(_font);
	_instructionText2.setString("- Ganas si llegas a score 10");
	_instructionText2.setFillColor(Color::Magenta);
	_instructionText2.setCharacterSize(24);
	_instructionText2.setPosition(40, 200);

	// Configura el texto de la instrucción 3
	_font.loadFromFile("Assets/font/RioGrande.ttf");
	_instructionText3.setFont(_font);
	_instructionText3.setString("- No dispares a inocentes");
	_instructionText3.setFillColor(Color::Magenta);
	_instructionText3.setCharacterSize(24);
	_instructionText3.setPosition(40, 250);

	// Configura el texto de la instrucción 4
	_font.loadFromFile("Assets/font/RioGrande.ttf");
	_instructionText4.setFont(_font);
	_instructionText4.setString("- Apunta con el mouse ");
	_instructionText4.setFillColor(Color::Magenta);
	_instructionText4.setCharacterSize(24);
	_instructionText4.setPosition(40, 300);

	// Configura el texto para iniciar el juego
	_font.loadFromFile("Assets/font/RioGrande.ttf");
	_startGameText.setFont(_font);
	_startGameText.setString("Dispara para comenzar...");
	_startGameText.setFillColor(Color::Green);
	_startGameText.setCharacterSize(20);
	_startGameText.setPosition(500, 400);
}

void InstructionScreen::Show(RenderWindow* _wnd) // Función para mostrar la pantalla de instrucciones
{

	_startGame = false; // Inicializa la bandera de inicio de juego en false
	Event evt; // Objeto para manejar eventos
	while (_wnd->isOpen()) // Mientras la ventana esté abierta
	{
		while (_wnd->pollEvent(evt)) // Procesa los eventos
		{
			switch (evt.type) // Maneja los diferentes tipos de eventos
			{
			case Event::Closed: // Si se cierra la ventana
				_wnd->close(); // Cierra la ventana
			case Event::MouseMoved: // Si se mueve el mouse
				sprite->setPosition(evt.mouseMove.x, evt.mouseMove.y); // Actualiza la posición del sprite
			case Event::MouseButtonPressed: // Si se presiona un botón del mouse
				if (evt.mouseButton.button == Mouse::Button::Left) // Si se presiona el botón izquierdo
				{
					_startGame = true; // Establece la bandera de inicio de juego en true
				}
			}
			// Dibuja los elementos de la pantalla de instrucciones
			_wnd->clear();
			_wnd->draw(*sprite);
			_wnd->draw(_gameNameText);
			_wnd->draw(_instructionText1);
			_wnd->draw(_instructionText2);
			_wnd->draw(_instructionText3);
			_wnd->draw(_instructionText4);
			_wnd->draw(_startGameText);
			_wnd->display();
		}
		if (_startGame) // Si se ha presionado el botón izquierdo del mouse
		{
			break; // Sale del bucle principal
		}
	}
	
}

