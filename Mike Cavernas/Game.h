#include "Stadx.h"

class Game {
private:

	RenderWindow* _wnd;

	void ProcessEvents();
	void Update();
	void Draw();
public:

	Game();
	~Game();

	void Go();

};