#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

class Enemy {
private:
    Sprite enemySprite;
    Texture enemyTexture;
    Clock clock;
    float tiempoVisible;
    float tiempoApagado;
    bool estaVivo;
    bool estaVisible;
    Vector2f randomPos(Vector2u maxPos);
public:
    Enemy();
    void Dibujar(RenderWindow* _wnd);
    void Actualizar(RenderWindow* _wnd);
    bool EstaVivo();
    bool EstaActivo();
    bool EstaEncima(float x, float y);
    bool derrotado();
};
