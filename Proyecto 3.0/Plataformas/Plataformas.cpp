#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;
Texture texture;
Sprite sprite1, sprite2, sprite3, sprite4, sprite5, sprite6, sprite7, sprite8;
int main() {
	texture.loadFromFile("plataforma.jpg");
	sprite1.setTexture(texture);
	sprite2.setTexture(texture);
	sprite3.setTexture(texture);
	sprite4.setTexture(texture);
	sprite5.setTexture(texture);
	sprite6.setTexture(texture);
	sprite7.setTexture(texture);
	sprite8.setTexture(texture);
	sprite1.setPosition(50, 600);
	sprite2.setPosition(125, 550);
	sprite3.setPosition(200, 500);
	sprite4.setPosition(275, 450);
	sprite5.setPosition(350, 400);
	sprite6.setPosition(425, 350);
	sprite7.setPosition(500, 300);
	sprite8.setPosition(1010, 300);
	sprite1.setScale(0.15f, 0.5f);
	sprite2.setScale(0.15f, 1.0f);
	sprite3.setScale(0.15f, 1.5f);
	sprite4.setScale(0.15f, 2.0f);
	sprite5.setScale(0.15f, 2.5f);
	sprite6.setScale(0.15f, 3.0f);
	sprite7.setScale(0.15f, 3.5f);
	sprite8.setScale(0.15f, 1.80f);
	sprite8.rotate(90);
	sf::RenderWindow App(sf::VideoMode(1024, 640), "Juego de plataforma");
	while (App.isOpen()) {
		App.clear();
		App.draw(sprite1);
		App.draw(sprite2);
		App.draw(sprite3);
		App.draw(sprite4);
		App.draw(sprite5);
		App.draw(sprite6);
		App.draw(sprite7);
		App.draw(sprite8);
		App.display();
	}
	return 0;
}