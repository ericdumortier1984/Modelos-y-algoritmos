#include "Stadx.h"
#include "Backgrounds.h"
#include "Obstacles.h"
#include "Mike.h"
#include "PointUp.h"

class Game {
private:

	RenderWindow* _wnd;
	Backgrounds* _cave;
	Obstacles* _estala;
	Mike* _mike;
	PointUp* _chicken;

	Font _font;
	Text _lifesText;
	Text _pointsText;

	void ProcessEvents();
	void Update(float deltaTime);
	void Draw();
	int UpdateLifes();
	int UpdatePoints();
public:

	Game();
	~Game();

	void CheckCollision();
	void Go();
	void RestartGame();

};