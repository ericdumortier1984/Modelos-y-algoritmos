#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

using namespace sf;

Sprite _circulo;
Texture _mat_circulo_rojo;
Texture _mat_circulo_azul;

int main() {

    RenderWindow App(VideoMode(800, 600, 32), "3- Splats");

    _mat_circulo_rojo.loadFromFile("rcircle.png");
    _mat_circulo_azul.loadFromFile("bcircle.png");


    std::vector<Sprite> _circulos;

     while (App.isOpen()) {
        Event evt;
        while (App.pollEvent(evt)) {
            if (evt.type == Event::Closed) {
                App.close();
            }
            else if (evt.type == Event::MouseButtonPressed) {
               if (evt.mouseButton.button == Mouse::Left) {
                _circulo.setTexture(_mat_circulo_rojo);
                _circulo.setPosition(evt.mouseButton.x, evt.mouseButton.y);
                _circulos.push_back(_circulo);
                }
                 else if (evt.mouseButton.button == Mouse::Right) {
                  _circulo.setTexture(_mat_circulo_azul);
                  _circulo.setPosition(evt.mouseButton.x, evt.mouseButton.y);
                  _circulos.push_back(_circulo);
                 }
            }
        }
        App.clear();
        for (const auto& _circulo : _circulos) {
            App.draw(_circulo);
        }
        App.display();
    }

	return 0;
}

