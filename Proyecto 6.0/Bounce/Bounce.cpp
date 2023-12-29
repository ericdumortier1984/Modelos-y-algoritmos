#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;

int main() {
	RenderWindow _wnd(VideoMode(800, 600), "3- Bounce");
	CircleShape ball(50.0f);
	ball.setFillColor(Color::Green);

	Vector2f position(_wnd.getSize().x/2 -50.0f, 0.0f);
	Vector2f velocity(0.0f, 0.0f);
	const float gravity = 0.00098f;
	const float reduccion = 0.8f;

	while (_wnd.isOpen()) {
		Event evt;
		while (_wnd.pollEvent(evt)) {
			if (evt.type == Event::Closed) {
				_wnd.close();
			}
		}

		velocity.y += gravity;
		position += velocity;

		if (position.y > 500.0f) {
			position.y = 500.0f;
			velocity.y = -velocity.y * reduccion;
		}

		_wnd.clear();
		ball.setPosition(position);
		_wnd.draw(ball);
		_wnd.display();
	}
	return 0;
}