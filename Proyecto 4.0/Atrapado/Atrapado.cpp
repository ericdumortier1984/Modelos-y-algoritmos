#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

Sprite _cuadrado_amarillo;
Sprite _circulo_rojo;
Texture _mat_cuadrado_amarillo;
Texture _mat_circulo_rojo;

float _escala_x;
float _escala_y;
float height_cuadrado_amarillo;
float width_cuadrado_amarillo;
float height_circulo_rojo;
float width_circulo_rojo;

bool _barra_espaciadora = false;
bool _es_circulo;

int main() {
    RenderWindow App(VideoMode(800, 600, 32), "4- Atrapado");
    App.setMouseCursorVisible(false);

    _mat_cuadrado_amarillo.loadFromFile("cuad_yellow.png");
    _cuadrado_amarillo.setTexture(_mat_cuadrado_amarillo);
    _cuadrado_amarillo.setPosition(350, 0);

    _mat_circulo_rojo.loadFromFile("rcircle.png");
    _circulo_rojo.setTexture(_mat_circulo_rojo);

    height_cuadrado_amarillo = (float)_mat_cuadrado_amarillo.getSize().y;
    height_circulo_rojo = (float)_mat_circulo_rojo.getSize().y;
    width_cuadrado_amarillo = (float)_mat_cuadrado_amarillo.getSize().x;
    width_circulo_rojo = (float)_mat_circulo_rojo.getSize().x;
    _escala_y = height_circulo_rojo / height_cuadrado_amarillo;
    _escala_x = width_circulo_rojo / width_cuadrado_amarillo;
    _cuadrado_amarillo.setScale(_escala_x, _escala_y);

    Event evt;
    while (App.isOpen()) {
        while (App.pollEvent(evt)) {
            switch (evt.type) {
            case Event::KeyPressed:
                if (evt.key.code == Keyboard::Escape) {
                    App.close();
                    break;
                }
                if (evt.key.code == Keyboard::Space) {
                    _barra_espaciadora = true;
                    break;
                }
                if (evt.key.code == Keyboard::Left) {
                    // Obtener la posición actual del cuadrado//
                    Vector2f pos = _cuadrado_amarillo.getPosition();
                    // Calcular la nueva posición//
                    Vector2f newPos = pos + Vector2f(-10.0f, 0.0f);
                    // Verificar si la nueva posición está dentro de los límites de la ventana//
                    if (newPos.x >= 0) {
                        _cuadrado_amarillo.setPosition(newPos);
                    }
                }
                else if (evt.key.code == Keyboard::Right) {
                    Vector2f pos = _cuadrado_amarillo.getPosition();
                    Vector2f newPos = pos + Vector2f(10.0f, 0.0f);
                    if (newPos.x <= 672) {
                        _cuadrado_amarillo.setPosition(newPos);
                    }
                }
                else if (evt.key.code == Keyboard::Up) {
                    Vector2f pos = _cuadrado_amarillo.getPosition();
                    Vector2f newPos = pos + Vector2f(0.0f, -10.0f);
                    if (newPos.y >= 0) {
                        _cuadrado_amarillo.setPosition(newPos);
                    }
                }
                else if (evt.key.code == Keyboard::Down) {
                    Vector2f pos = _cuadrado_amarillo.getPosition();
                    Vector2f newPos = pos + Vector2f(0.0f, 10.0f);
                    if (newPos.y <= 472) {
                        _cuadrado_amarillo.setPosition(newPos);
                    }
                }
                break;
            }
        }
        if (_barra_espaciadora) {
            if (_es_circulo) {
                _cuadrado_amarillo.setTexture(_mat_circulo_rojo);
                _barra_espaciadora = false;
                _cuadrado_amarillo.setScale(_escala_x, _escala_y);
                _es_circulo = false;
        }
            else {
                _circulo_rojo.setScale(_escala_x, _escala_y);
                _es_circulo = true;
            }
        }

        App.clear();
        App.draw(_cuadrado_amarillo);
        App.draw(_circulo_rojo);
        App.display();
    }

    return 0;
}
