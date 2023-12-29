#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

int main() {
    //creamos ventana y objeto
    RenderWindow _wnd(VideoMode(800, 600), "2- Space");
    CircleShape ball(50.0f);
    ball.setFillColor(Color::Yellow);

    Vector2f position(0.0f, 100.0f);
    Vector2f velocity(100.f, 0.0f);
    const float acceleration = 25.0f;

    //loop
    while (_wnd.isOpen()) {
        Event evt;
        while (_wnd.pollEvent(evt)) {
            if (evt.type == Event::Closed) {
                _wnd.close();
            }   
        }
        float deltaTime = 0.1f / 60.0f;
        velocity.x += acceleration * deltaTime;
        position += velocity * deltaTime;

        if (evt.type == Event::KeyPressed) {
            if (evt.key.code == Keyboard::Right) {
                velocity.x++;
            }
            if (evt.key.code == Keyboard::Left) {
                velocity.x--;
            }
        }

        _wnd.clear();
        ball.setPosition(position);
        _wnd.draw(ball);
        _wnd.display();
    }

    return 0;
}
