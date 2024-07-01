#include "InstructionScreen.h"

InstructionScreen::InstructionScreen() 
{
	
	_font.loadFromFile("Assets/font/RioGrande.ttf");
	_gameNameText.setFont(_font);
	_gameNameText.setString("Wild Gunman");
	_gameNameText.setFillColor(Color::Yellow);
	_gameNameText.setPosition(270, 40);
	_gameNameText.setCharacterSize(42);

	_font.loadFromFile("Assets/font/RioGrande.ttf");
	_instructionText1.setFont(_font);
	_instructionText1.setString("Instrucciones");
	_instructionText1.setFillColor(Color::Magenta);
	_instructionText1.setCharacterSize(30);
	_instructionText1.setPosition(40, 150);

	_font.loadFromFile("Assets/font/RioGrande.ttf");
	_instructionText2.setFont(_font);
	_instructionText2.setString("- Ganas si llegas a score 10");
	_instructionText2.setFillColor(Color::Magenta);
	_instructionText2.setCharacterSize(24);
	_instructionText2.setPosition(40, 200);

	_font.loadFromFile("Assets/font/RioGrande.ttf");
	_instructionText3.setFont(_font);
	_instructionText3.setString("- No dispares a inocentes");
	_instructionText3.setFillColor(Color::Magenta);
	_instructionText3.setCharacterSize(24);
	_instructionText3.setPosition(40, 250);

	_font.loadFromFile("Assets/font/RioGrande.ttf");
	_instructionText4.setFont(_font);
	_instructionText4.setString("- Apunta con el mouse ");
	_instructionText4.setFillColor(Color::Magenta);
	_instructionText4.setCharacterSize(24);
	_instructionText4.setPosition(40, 300);

	_font.loadFromFile("Assets/font/RioGrande.ttf");
	_startGameText.setFont(_font);
	_startGameText.setString("Dispara para comenzar...");
	_startGameText.setFillColor(Color::Green);
	_startGameText.setCharacterSize(20);
	_startGameText.setPosition(500, 400);
}

void InstructionScreen::Show(RenderWindow &wnd) 
{
	_startGame = false;
	Event e;
	while (wnd.isOpen())
	{
		while (wnd.pollEvent(e))
		{
			switch (e.type)
			{
			case Event::Closed:
				wnd.close();
			case Event::MouseMoved:
				playerSprite.setPosition(e.mouseMove.x, e.mouseMove.y);
			case Event::MouseButtonPressed:
				if (e.mouseButton.button == Mouse::Button::Left)
				{
					_startGame = true;
				}
			}
			
			wnd.clear();
			wnd.draw(playerSprite);
			wnd.draw(_gameNameText);
			wnd.draw(_instructionText1);
			wnd.draw(_instructionText2);
			wnd.draw(_instructionText3);
			wnd.draw(_instructionText4);
			wnd.draw(_startGameText);
			wnd.display();
		}
		if (_startGame) 
		{
			break;
		}
	}
	
}