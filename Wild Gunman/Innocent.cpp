#include "Innocent.h"

Innocent::Innocent() {
	innocent_Tx.loadFromFile("Assets/imagenes/innocent.png");
	innocent_Sp.setTexture(innocent_Tx);
	innocent_Sp.setScale(1.4f, 1.2f);
	_isAlive = true;
	_isVisible = false;

	// Posiciones donde se colocará el inocente //
	innocentPositions[0] = Vector2f(590, 230);
	innocentPositions[1] = Vector2f(565, 40);
	innocentPositions[2] = Vector2f(100, 230);
	innocentPositions[3] = Vector2f(120, 40);
	innocentPositions[4] = Vector2f(345, 230);
}

void Innocent::Draw(RenderWindow* _wnd) {
	_wnd->draw(innocent_Sp);
}

void Innocent::InnocentUpdate(RenderWindow* _wnd) {
	if (!_isAlive) {
		return;
	}
	if (!_isVisible) {
		if (_clock.getElapsedTime().asSeconds() > timeNotVisible) {
			_clock.restart();

			if (rand() % 100 < 5) {
				int randomIndex = rand() % 5; // Generar un índice aleatorio entre 0 y 4 //

				// Cambiar posiciones y tiempos de inocente //
				innocent_Sp.setPosition(innocentPositions[randomIndex]);
				if (randomIndex == 0) {
					timeVisible = 1.0f;
					timeNotVisible = 4.0f;
				}
				else if (randomIndex == 1) {
					timeVisible = 1.0f;
					timeNotVisible = 6.0f;
				}
				else if (randomIndex == 2) {
					timeVisible = 1.0f;
					timeNotVisible = 8.0f;
				}
				else if (randomIndex == 3) {
					timeVisible = 1.0f;
					timeNotVisible = 10.0f;
				}
				_isVisible = true;
			}
		}
	}
	else {
		if (_clock.getElapsedTime().asSeconds() > timeVisible) {
			_isVisible = false;
			_clock.restart();
		}
	}
}

bool Innocent::ShootAtInnocent() {
	_isAlive = false;
	return _isAlive;
}
bool Innocent::IsAbove(float x, float y) {
	FloatRect bounds_innocent = innocent_Sp.getGlobalBounds();
	return bounds_innocent.contains(x, y);
}