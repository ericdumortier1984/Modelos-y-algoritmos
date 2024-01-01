#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

class PlayerCrosshair {
private:
    Sprite playerSprite;
    Texture playerTexture;
public:
    PlayerCrosshair();
    void Dibujar(RenderWindow* _wnd);
    void Posicionar(float x, float y);
    Vector2f ObtenerPosicion();
};
