#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

int main() {
    //creamos ventana y objeto
    RenderWindow _wnd(VideoMode(800, 600), "2- Space");
    _wnd.setFramerateLimit(60);
    CircleShape ball(50.0f);
    ball.setFillColor(Color::Yellow);

    Vector2f position(0.0f, 0.0f);
    Vector2f velocity(0.0f, 0.0f);
    const float acceleration = 10.0f;

    //loop
    while (_wnd.isOpen()) {
        Event evt;
        while (_wnd.pollEvent(evt)) {
            if (evt.type == Event::Closed) {
                _wnd.close();
            }   
        }
        float deltaTime = 1.0f / 60.0f;

        if (evt.type == Event::KeyPressed) {
            if (evt.key.code == Keyboard::Right) {
                velocity.x += acceleration;
            }
            if (evt.key.code == Keyboard::Left) {
                velocity.x -= acceleration;
            }
        }

        position += velocity * deltaTime;

        _wnd.clear();
        ball.setPosition(position);
        _wnd.draw(ball);
        _wnd.display();
    }

    return 0;
}
