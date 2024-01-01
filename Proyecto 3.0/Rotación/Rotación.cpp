#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;
Texture texture;
Sprite sprite;
int main() {
	texture.loadFromFile("plataforma.jpg");
	sprite.setTexture(texture);
	sprite.setPosition(350, 250);
	sprite.setScale(0.5f, 0.5f);
	sf::RenderWindow App(sf::VideoMode(800, 600), "Cuidado que sale volando");
	while (App.isOpen()) {
		sprite.rotate(1.0f);
		App.clear();
		App.draw(sprite);
		App.display();
	}
	return 0;
}