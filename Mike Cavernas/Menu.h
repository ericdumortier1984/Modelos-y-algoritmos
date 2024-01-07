#include "stdafx.h"

#define Max_main_menu 2

class MainMenu {
private:
	int MainMenuSelected;
	Font font;
	Text mainMenu[Max_main_menu];
public:
	MainMenu();

	void Draw(RenderWindow* window);
	void MoveUp();
	void MoveDown();

	int MainMenuPressed() {
		return MainMenuSelected;
	}
	~MainMenu();

};
