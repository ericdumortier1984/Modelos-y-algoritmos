#include "PlayerCrosshair.h"

PlayerCrosshair::PlayerCrosshair() {
    playerTexture.loadFromFile("crosshair.png");
    playerSprite.setTexture(playerTexture);
    playerSprite.setScale(0.25f, 0.25f);
    Vector2u size = playerTexture.getSize();
    playerSprite.setOrigin(size.x / 2.0f, playerTexture.getSize().y / 2.0f);
}

void PlayerCrosshair::Dibujar(RenderWindow* _wnd) {
    _wnd->draw(playerSprite);
}

void PlayerCrosshair::Posicionar(float x, float y) {
    playerSprite.setPosition(x, y);
}

Vector2f PlayerCrosshair::ObtenerPosicion() {
    return playerSprite.getPosition();
}
