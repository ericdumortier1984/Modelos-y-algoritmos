#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;
Texture texture;
Sprite sprite;
Sprite sprite1;
Sprite sprite2;
Sprite sprite3;
int main() {
	sprite.setPosition(0, 0);
	sprite1.setPosition(670, 0);
	sprite2.setPosition(670, 470);
	sprite3.setPosition(0, 470);
	texture.loadFromFile("rcircle.png");
	sprite.setTexture(texture);
	sprite1.setTexture(texture);
	sprite2.setTexture(texture);
	sprite3.setTexture(texture);
	sf::RenderWindow App(sf::VideoMode(800, 600), "ventana con puntos rojos");
	while (App.isOpen()) {
		App.clear();
		App.draw(sprite);
		App.draw(sprite1);
		App.draw(sprite2);
		App.draw(sprite3);
		App.display();
	}
	return 0;
}