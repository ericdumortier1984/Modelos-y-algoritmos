#include "Menu.h"

MainMenu::MainMenu() {
	font.loadFromFile("Asset/Font/junegull.ttf");

	//Play
	mainMenu[0].setFont(font);
	mainMenu[0].setCharacterSize(50);
	mainMenu[0].setFillColor(Color::White);
	mainMenu[0].setString("PLAY");
	mainMenu[0].setPosition(400, 300);
	//Exit
	mainMenu[1].setFont(font);
	mainMenu[1].setCharacterSize(50);
	mainMenu[1].setFillColor(Color::White);
	mainMenu[1].setString("EXIT");
	mainMenu[1].setPosition(400, 400);

	MainMenuSelected = -1;
}

MainMenu::~MainMenu() {

}

void MainMenu::Draw(RenderWindow* _wnd) {
	for (int i = 0; i < Max_main_menu; i++) {
		_wnd->draw(mainMenu[i]);
	}
}

void MainMenu::MoveUp() {
	if (MainMenuSelected - 1 >= 0) {
		mainMenu[MainMenuSelected].setFillColor(Color::White);
		MainMenuSelected--;
		if (MainMenuSelected == -1) {
			MainMenuSelected == 2;
		}
		mainMenu[MainMenuSelected].setFillColor(Color::Black);
	}
}

void MainMenu::MoveDown() {
	if (MainMenuSelected + 1 <= Max_main_menu) {
		mainMenu[MainMenuSelected].setFillColor(Color::White);
		MainMenuSelected++;
		if (MainMenuSelected == 2) {
			MainMenuSelected == 0;
		}
		mainMenu[MainMenuSelected].setFillColor(Color::Black);
	}
}