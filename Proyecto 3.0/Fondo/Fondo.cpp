#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;
Texture texture;
Sprite sprite;
int main() {
	texture.loadFromFile("fondo.jpg");
	sprite.setScale(800.0f / 1024.0f, 600.0f / 768.0f);
	sprite.setTexture(texture);
	texture.setSmooth(true);
	sf::RenderWindow App(sf::VideoMode(800, 600), "Ventana de fondo");
	while (App.isOpen()) {
		App.clear();
		App.draw(sprite);
		App.display();
	}
	return 0;
}