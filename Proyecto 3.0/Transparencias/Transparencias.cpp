#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;
Texture texture_red;
Texture texture_blue;
Sprite sprite_red;
Sprite sprite1_red;
Sprite sprite2_red;
Sprite sprite3_red;
Sprite sprite_blue;
int main() {
	sprite_red.setPosition(0, 0);
	sprite1_red.setPosition(670, 0);
	sprite2_red.setPosition(670, 470);
	sprite3_red.setPosition(0, 470);
	sprite_blue.setPosition(320, 200);
	sprite_blue.setScale(0.5f, 0.5f);
	texture_red.loadFromFile("rcircle.png");
	texture_blue.loadFromFile("bcircle.png");
	sprite_red.setTexture(texture_red);
	sprite1_red.setTexture(texture_red);
	sprite2_red.setTexture(texture_red);
	sprite3_red.setTexture(texture_red);
	sprite_blue.setTexture(texture_blue);
	sf::RenderWindow App(sf::VideoMode(800, 600), "ventana con puntos rojos y azul");
	while (App.isOpen()) {
		App.clear();
		App.draw(sprite_red);
		App.draw(sprite1_red);
		App.draw(sprite2_red);
		App.draw(sprite3_red);
		App.draw(sprite_blue);
		App.display();
	}
	return 0;
}