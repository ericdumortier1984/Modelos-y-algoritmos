#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;
Texture textureWhite;
Texture textureBlack;
Sprite spriteWhite;
Sprite spriteBlack;
int main() {
	spriteWhite.setScale(0.75f, 0.75f);
	spriteBlack.setScale(0.75f, 0.75f);
	textureWhite.loadFromFile("chessw.png");
	textureBlack.loadFromFile("chessb.png");
	spriteWhite.setTexture(textureWhite);
	spriteBlack.setTexture(textureBlack);
	sf::RenderWindow App(sf::VideoMode(800, 800), "Ventana de ajedrez");
	while (App.isOpen()) {
		App.clear();
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if ((i + j) % 2 == 0) {
					spriteWhite.setPosition(i * 100, j * 100);
					App.draw(spriteWhite);
				}
			}
		}
		App.display();
	}
	return 0;
}