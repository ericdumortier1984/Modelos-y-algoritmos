#include "Stadx.h"

class Backgrounds {
private:

	Sprite _landscapeSp, _pathSp;
	Texture _landscapeTx, _pathTx;

public:

	Backgrounds();
	~Backgrounds();

	void Draw(RenderWindow* _wnd);
};
