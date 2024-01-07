#include "Stadx.h"
#include "Backgrounds.h"
#include "Obstacles.h"
#include "Mike.h"

class Game {
private:

	RenderWindow* _wnd;
	Backgrounds* _cave;
	Obstacles* _estala;
	Mike* _mike;

	void ProcessEvents();
	void Update(float deltaTime);
	void Draw();
public:

	Game();
	~Game();

	void Go();

};