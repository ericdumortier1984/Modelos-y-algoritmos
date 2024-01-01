#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

using namespace sf;

Sprite _crosshair;
Texture _mat_crosshair;

int main() {
	
	_mat_crosshair.loadFromFile("crosshair.png");
	_crosshair.setTexture(_mat_crosshair);
	_mat_crosshair.setSmooth(true);
	_crosshair.setPosition(400, 300);
	_crosshair.setOrigin(_crosshair.getTexture()->getSize().x/2, _crosshair.getTexture()->getSize().y/2);

	RenderWindow App(VideoMode(800, 600, 32), "1- Crosshair");

	while (App.isOpen()) {
		Event evt;
		while (App.pollEvent(evt)) {
			switch (evt.type) {
			case Event::Closed:
				App.close();
				break;
			}
		}
		App.clear();
		App.draw(_crosshair);
		App.display();
	}

	return 0;
}