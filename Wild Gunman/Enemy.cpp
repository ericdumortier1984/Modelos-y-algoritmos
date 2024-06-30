#include "Enemy.h"

Enemy::Enemy() {
	_tx.loadFromFile("Assets/imagenes/enemy1.png");
	_tx2.loadFromFile("Assets/imagenes/enemy2.png");
	_tx3.loadFromFile("Assets/imagenes/enemy3.png");
	_sprite.setTexture(_tx);
	_sprite.setScale(1.4f, 1.2f);
	_isAlive = true;
	_isVisible = false;
	timeVisible = 1.5f;
	timeNotVisible = 2.0f;

	// Posiciones donde se colocarán los enemigos //
	enemyPositions[0] = Vector2f(590, 230);
	enemyPositions[1] = Vector2f(560, 40);
	enemyPositions[2] = Vector2f(100, 230);
	enemyPositions[3] = Vector2f(120, 40);
	enemyPositions[4] = Vector2f(345, 230);
}

void Enemy::Draw(RenderWindow* _wnd) {
	_wnd->draw(_sprite);
}

void Enemy::EnemyUpdate(RenderWindow* _wnd) {
	if (!_isAlive) {
		return;
	}
	if (!_isVisible) {
		if (_clock.getElapsedTime().asSeconds() > timeNotVisible) {
			_clock.restart();

			if (rand() % 100 < 10) {
				int randomIndex = rand() % 5; // Generar un índice aleatorio entre 0 y 4 //

				// Cambiar la textura según el tipo de enemigo //
				if (randomIndex == 0) {
					_sprite.setTexture(_tx);
				}
				else if (randomIndex == 1) {
					_sprite.setTexture(_tx2);
				}
				else if (randomIndex == 2) {
					_sprite.setTexture(_tx3);
				}
			
				// Cambiar posiciones y tiempos de enemigos //
				_sprite.setPosition(enemyPositions[randomIndex]);
				if (randomIndex == 0) {
					timeVisible = 1.5f;
					timeNotVisible = 2.0f;
				}
				else if (randomIndex == 1) {
					timeVisible = 1.5f;
					timeNotVisible = 2.3f;
				}
				else if (randomIndex == 2) {
					timeVisible = 1.8f;
					timeNotVisible = 2.3f;
				}
				else if (randomIndex == 3) {
					timeVisible = 2.1f;
					timeNotVisible = 2.6f;
				}
				else if (randomIndex == 4) {
					timeVisible = 2.7f;
					timeNotVisible = 3.2f;
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

float Enemy::GetVisibleTime() {
	return timeVisible;
}

void Enemy::Reset(RenderWindow* _wnd) {
	_isAlive = true;
	_isVisible = false;
}

bool Enemy::IsAlive() {
	return _isAlive;
}

bool Enemy::Die() {
	_isAlive = false;
	return _isAlive;
}

bool Enemy::IsInGame() {
	return _isAlive && _isVisible;
}

bool Enemy::Shoot() {
	bool Shoot = false;
	if (_isAlive && _isVisible) {
		Shoot = rand() % 100 == 20;
	}
	return Shoot;
}

bool Enemy::IsAbove(float x, float y) {
	FloatRect bounds_sprite = _sprite.getGlobalBounds();
	return bounds_sprite.contains(x, y);
}
