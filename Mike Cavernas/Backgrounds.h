#include "Stadx.h"

class Backgrounds {
private:

	Sprite _caveSp;
	Texture _caveTx;

public:

	Backgrounds();
	~Backgrounds();

	void Draw(RenderWindow* _wnd);
};
