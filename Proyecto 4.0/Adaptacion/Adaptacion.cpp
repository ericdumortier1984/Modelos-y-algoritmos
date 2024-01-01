#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

Sprite _fondo;
Texture _mat_fondo;

int main() {

	RenderWindow App(VideoMode(800, 600, 32), "5- Adaptacion");

	_mat_fondo.loadFromFile("fondo.jpg");
	_fondo.setTexture(_mat_fondo);

	while (App.isOpen()) {
		Event evt;
		while (App.pollEvent(evt)) {
			switch (evt.type) {
			case Event::KeyPressed:
				if (evt.key.code == Keyboard::Escape)
					App.close();
				break;
			case Event::Resized:
				if (evt.type = Event::Resized) {
					Vector2u size = App.getSize();
					//Operador ternario para obtener el valor maximo o minimo entre dos numeros//
					size.x = (size.x < 100) ? 100 : ((size.x > 1000) ? 1000 : size.x);
					size.y = (size.y < 100) ? 100 : ((size.y > 1000) ? 1000 : size.y);
					App.setSize(size);
				}
			}
		}
		App.clear();
		App.draw(_fondo);
		App.display();
	}

	return 0;
}

