#include"Backgrounds.h"

Backgrounds::Backgrounds() 
{

	_caveTx.loadFromFile("Asset/Images/Cave.png");
	_caveSp.setTexture(_caveTx);
	_caveSp.setPosition(0.0f, 30.0f);

	_landscapeTx.loadFromFile("Asset/Images/Landscape.png");
	_landscapeSp.setTexture(_landscapeTx);
	_landscapeSp.setPosition(0.0f, 110.0f);

	_pathTx.loadFromFile("Asset/Images/RockPath.png");
	_pathSp.setTexture(_pathTx);
	_pathSp.setPosition(0.0f, 190.0f);
}

Backgrounds::~Backgrounds() 
{

}

void Backgrounds::Draw(RenderWindow* _wnd) 
{

	_wnd->draw(_landscapeSp);
	_wnd->draw(_caveSp);
	_wnd->draw(_pathSp);
}