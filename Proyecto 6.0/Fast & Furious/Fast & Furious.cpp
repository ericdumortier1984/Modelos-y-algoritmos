#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

int main() {
	//creamos ventana
	RenderWindow _wnd(VideoMode(800, 600), "1- Fast & Furious");
	CircleShape object(50.0f);//tamaño objeto
	object.setFillColor(Color::Red);//color objeto
	Vector2f position(0.0f, 100.0f);//posicion inicial
	float velocity = 50.0f;//velocidad inicial
	float finalVelocity = 300.0f;//velocidad final

	//loop
	while (_wnd.isOpen()) {
		Event evt;
		while (_wnd.pollEvent(evt)) {
			if (evt.type == Event::Closed) {
				_wnd.close();
			}
		}

		float deltaTime = 0.1f / 60.0f;
		position.x += velocity * deltaTime;

		if (position.x > _wnd.getSize().x) {
			velocity += 50.0f;//incrementa velocidad al volver por el lado izquierdo
			if (velocity > finalVelocity) {
				_wnd.close();//sale del programa cuando llega a la velocidad final
			}
			position.x = -50.0f;//posicion del objeto al volver a ingresar a la pantalla por lado izquierdo
		}

		_wnd.clear();
		//dibujamos el objeto en la posicion actual
		object.setPosition(position);
		_wnd.draw(object);
		//mostrar
		_wnd.display();

	}

	return 0;
}