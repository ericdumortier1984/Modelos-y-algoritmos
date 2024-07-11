#pragma once
#include "Include&using.h"
#include "Player.h"

class InstructionScreen : public Player 
{
protected:

	Text _gameNameText, _instructionText1, _instructionText2, _instructionText3, _instructionText4, _startGameText;
	Font _font;
	bool _startGame;

public:

	InstructionScreen();
	void Show(RenderWindow* _wnd);
};