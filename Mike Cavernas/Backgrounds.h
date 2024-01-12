#include "Stadx.h"

class Backgrounds {
private:

	Sprite _caveSp, _landscapeSp, _pathSp;
	Texture _caveTx, _landscapeTx, _pathTx;

public:

	Backgrounds();
	~Backgrounds();

	void Draw(RenderWindow* _wnd);
};
