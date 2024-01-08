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

	Font _font;
	Text _lifesText;

	void ProcessEvents();
	void Update(float deltaTime);
	void Draw();
	int UpdateLifes();
public:

	Game();
	~Game();

	void CheckCollision();
	void Go();

};