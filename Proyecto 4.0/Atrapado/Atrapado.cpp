#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(800, 600), "Cuadrado y Círculo");
    // Limitamos el número de frames por segundos de nuestra aplicación
    window.setFramerateLimit(30);
    // Texturas del círculo y del cuadrado
    Texture squareTexture, circleTexture;
    squareTexture.loadFromFile("cuad_yellow.png");
    circleTexture.loadFromFile("rcircleg.png");
    // Seteamos suvizado de bordes a las texturas
    squareTexture.setSmooth(true);
    circleTexture.setSmooth(true);
    // Escalas elegidas para unificar el tamaño de los sprites, en este caso lo fijamos en 64px.
    float circleScale = 0.5f;
    float squareScale = 0.125f;
    float shapeSize = 64.f;

    // Declaramos un único sprite que alternará las texturas del círculo y del cuadrado según corresponda
    Sprite shapeOnScreen;
    shapeOnScreen.setTexture(squareTexture);
    shapeOnScreen.setScale(squareScale, squareScale);
    shapeOnScreen.setOrigin(squareTexture.getSize().x / 2, squareTexture.getSize().y / 2);
    shapeOnScreen.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    const float speed = 12.f;
    bool isCircle = false;
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::closed)
                window.close();
            if (event.type == Event::KeyPressed)
            {
                switch (event.key.code)
                {
                case Keyboard::Space:
                    isCircle = !isCircle;
                    break;
                default:
                    break;
                }
            }
        }
        // Procesamiento de inputs de teclado
        if (sf::Keyboard::isKeyPressed(Keyboard::Left))
        {
            if (shapeOnScreen.getPosition().x - shapeSize / 2 > 5)
                shapeOnScreen.move(-speed, 0);
        }
        if (sf::Keyboard::isKeyPressed(Keyboard::Right))
        {
            if (shapeOnScreen.getPosition().x + shapeSize / 2 < window.getSize().x - 5)
                shapeOnScreen.move(speed, 0);
        }
        if (sf::Keyboard::isKeyPressed(Keyboard::Up))
        {
            if (shapeOnScreen.getPosition().y - shapeSize / 2 > 5)
                shapeOnScreen.move(0, -speed);
        }
        if (sf::Keyboard::isKeyPressed(Keyboard::Down))
        {
            if (shapeOnScreen.getPosition().y + shapeSize / 2 < window.getSize().y - 5)
                shapeOnScreen.move(0, speed);
        }
        // Chequeamos si debe ser un círculo o un cuadrado y cambiamos solo la textura del mismo sprite
        if (isCircle) {
            shapeOnScreen.setTexture(circleTexture);
            shapeOnScreen.setScale(circleScale, circleScale);
            shapeOnScreen.setOrigin(circleTexture.getSize().x / 2, circleTexture.getSize().y / 2);
        }
        else {
            shapeOnScreen.setTexture(squareTexture);
            shapeOnScreen.setScale(squareScale, squareScale);
            shapeOnScreen.setOrigin(squareTexture.getSize().x / 2, squareTexture.getSize().y / 2);
        }
        window.clear();
        window.draw(shapeOnScreen);
        window.display();
    }
    return 0;
}