#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;
Texture texture_blue;
Texture texture_yellow;
Texture texture_red;
Texture texture_grey;
Sprite sprite_blue;
Sprite sprite_yellow;
Sprite sprite_red;
Sprite sprite_grey;
float escala_x; float escala_y;
float height_blue, width_blue;
float height_yellow, width_yellow;
float height_red, width_red;
float height_grey, width_grey;
int main() {
	texture_blue.loadFromFile("cuad_blue.png");
	texture_yellow.loadFromFile("cuad_yellow.png");
	texture_red.loadFromFile("cuad_red.png");
	texture_grey.loadFromFile("cuad_grey.png");
	sprite_blue.setTexture(texture_blue);
	sprite_yellow.setTexture(texture_yellow);
	sprite_red.setTexture(texture_red);
	sprite_grey.setTexture(texture_grey);
	sprite_blue.setPosition(250, 228);
	sprite_yellow.setPosition(378, 100);
	sprite_red.setPosition(250, 100);
	sprite_grey.setPosition(378, 228);
	height_blue = (float)texture_blue.getSize().y;
	height_yellow = (float)texture_yellow.getSize().y;
	width_blue = (float)texture_blue.getSize().x;
	width_yellow = (float)texture_yellow.getSize().x;
	escala_y = height_blue / height_yellow;
	escala_x = width_blue / width_yellow;
	sprite_yellow.setScale(escala_x, escala_y);
	height_red = (float)texture_red.getSize().y;
	height_grey = (float)texture_grey.getSize().y;
	width_red = (float)texture_red.getSize().x;
	width_grey = (float)texture_grey.getSize().x;
	escala_y = height_blue / height_red;
	escala_x = width_blue / width_red;
	sprite_red.setScale(escala_x, escala_y);
	escala_x = width_blue / width_grey;
	escala_y = height_blue / height_grey;
	sprite_grey.setScale(escala_x, escala_y);
	sf::RenderWindow App(sf::VideoMode(800, 600), "Cuadrados de colores");
	while (App.isOpen()) {
		App.clear();
		App.draw(sprite_blue);
		App.draw(sprite_yellow);
		App.draw(sprite_red);
		App.draw(sprite_grey);
		App.display();
	}
	return 0;
}