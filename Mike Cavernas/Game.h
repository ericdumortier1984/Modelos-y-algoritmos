#include "Stadx.h"
#include "Backgrounds.h"
#include "Obstacles.h"

class Game {
private:

	RenderWindow* _wnd;
	Backgrounds* _cave;
	Obstacles* _estala;

	void ProcessEvents();
	void Update();
	void Draw();
public:

	Game();
	~Game();

	void Go();

};