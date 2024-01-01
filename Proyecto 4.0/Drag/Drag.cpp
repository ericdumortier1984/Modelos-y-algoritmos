#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

Sprite _cursor;
Sprite _rojo1;
Sprite _rojo2;
Sprite _rojo3;
Sprite _rojo4;
Texture _mat_circulos_rojos;
Texture _mat_cursor;

bool _esta_arrastrando = false;
Sprite* _sprite_seleccionado = nullptr;
Vector2f offset;

int main() {

	RenderWindow App(VideoMode(800, 600, 32), "2- Drag");

	App.setMouseCursorVisible(false);

	_mat_cursor.loadFromFile("crosshair.png");
	_cursor.setTexture(_mat_cursor);
	_cursor.setPosition(300, 300);
	_cursor.setScale(0.5f, 0.5f);

	_mat_circulos_rojos.loadFromFile("rcircle.png");
	_rojo1.setTexture(_mat_circulos_rojos);
	_rojo2.setTexture(_mat_circulos_rojos);
	_rojo3.setTexture(_mat_circulos_rojos);
	_rojo4.setTexture(_mat_circulos_rojos);
	
	_rojo1.setPosition(0, 0);
	_rojo2.setPosition(670, 0);
	_rojo3.setPosition(670, 470);
	_rojo4.setPosition(0, 470);
	
	while (App.isOpen()) {
		Event evt;
		while (App.pollEvent(evt)) {
			switch (evt.type) {
			case Event::KeyPressed:
				if (evt.key.code == Keyboard::Escape)
					App.close();
				break;
			case Event::MouseMoved:
				_cursor.setPosition(evt.mouseMove.x, evt.mouseMove.y);
				if (_esta_arrastrando) {
					_sprite_seleccionado->setPosition(evt.mouseMove.x - offset.x, evt.mouseMove.y - offset.y);
				}
				break;
			case Event::MouseButtonPressed:
				if (evt.mouseButton.button == Mouse::Left) {
					if (_rojo1.getGlobalBounds().contains(evt.mouseButton.x, evt.mouseButton.y)) {
						_esta_arrastrando = true;
						_sprite_seleccionado = &_rojo1;
						offset = Vector2f(evt.mouseButton.x - _rojo1.getPosition().x, evt.mouseButton.y - _rojo1.getPosition().y);
					}
					else if (_rojo2.getGlobalBounds().contains(evt.mouseButton.x, evt.mouseButton.y)) {
						_esta_arrastrando = true;
						_sprite_seleccionado = &_rojo2;
						offset = Vector2f(evt.mouseButton.x - _rojo2.getPosition().x, evt.mouseButton.y - _rojo2.getPosition().y);
					}
					else if (_rojo3.getGlobalBounds().contains(evt.mouseButton.x, evt.mouseButton.y)) {
						_esta_arrastrando = true;
						_sprite_seleccionado = &_rojo3;
						offset = Vector2f(evt.mouseButton.x - _rojo3.getPosition().x, evt.mouseButton.y - _rojo3.getPosition().y);
					}
					else if (_rojo4.getGlobalBounds().contains(evt.mouseButton.x, evt.mouseButton.y)) {
						_esta_arrastrando = true;
						_sprite_seleccionado = &_rojo4;
						offset = Vector2f(evt.mouseButton.x - _rojo4.getPosition().x, evt.mouseButton.y - _rojo4.getPosition().y);
					}
				}
				break;
			case Event::MouseButtonReleased:
				if (evt.mouseButton.button == Mouse::Left) {
					_esta_arrastrando = false;
					_sprite_seleccionado = nullptr;
				}
				break;
			}
		}
		App.clear();
		App.draw(_cursor);
		App.draw(_rojo1);
		App.draw(_rojo2);
		App.draw(_rojo3);
		App.draw(_rojo4);
		App.display();
	}

	return 0;
}
