#include "Enemy.h"

Vector2f Enemy::randomPos(Vector2u maxPos) {
    Vector2f random((float)(rand() % maxPos.x), (float)(rand() % maxPos.y));
    return random;
}

Enemy::Enemy() {
    enemyTexture.loadFromFile("et.png");
    enemySprite.setTexture(enemyTexture);
    enemySprite.setScale(0.050f, 0.050f);
    estaVivo = true;
    estaVisible = false;
    tiempoVisible = 0.5f;
    tiempoApagado = 0.5f;
}

void Enemy::Dibujar(RenderWindow* _wnd) {
    _wnd->draw(enemySprite);
}

void Enemy::Actualizar(RenderWindow* _wnd) {
    if (!estaVivo)
        return;

    if (!estaVisible) {
        if (clock.getElapsedTime().asSeconds() > tiempoApagado) {
            clock.restart();
            if (rand() % 100 < 25)
                estaVisible = true;
            enemySprite.setPosition(randomPos(_wnd->getSize()));
        }
    }
    else {
        if (clock.getElapsedTime().asSeconds() > tiempoVisible) {
            estaVisible = false;
            clock.restart();
        }
    }
}

bool Enemy::EstaVivo() {
    return estaVivo;
}

bool Enemy::EstaActivo() {
    return estaVivo && estaVisible;
}

bool Enemy::EstaEncima(float x, float y) {
    FloatRect bounds = enemySprite.getGlobalBounds();
    return bounds.contains(x, y);
}

bool Enemy::derrotado() {
    return estaVivo = false;
}


