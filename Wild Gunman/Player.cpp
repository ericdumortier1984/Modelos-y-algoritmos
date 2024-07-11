#include "Player.h" // Incluye el archivo de encabezado de la clase Player

Player::Player() // Constructor de la clase Player
{

	// Crea un nuevo objeto Sprite y Texture
	sprite = new Sprite;
	texture = new Texture;
	texture->loadFromFile("Assets/imagenes/puntoDeMira.png"); // Carga la textura desde un archivo
	sprite->setTexture(*texture); // Asigna la textura al sprite
	texture->setSmooth(true); // Habilita el suavizado de la textura
	Vector2u size = texture->getSize(); // Obtiene el tama�o de la textura
	sprite->setOrigin(size.x / 2.0f, size.y / 2.0f); // Establece el origen del sprite en el centro
}

Player::~Player() // Destructor de la clase Player
{

	// Libera la memoria ocupada por el sprite y la textura
	delete sprite;
	delete texture;
}

void Player::Draw(RenderWindow* _wnd) // Funci�n para dibujar el sprite del jugador
{

	_wnd->draw(*sprite); // Dibuja el sprite en la ventana de renderizado
}

void Player::SetPosition(float x, float y) // Funci�n para establecer la posici�n del jugador
{

	sprite->setPosition(x, y); // Establece la posici�n del sprite
}

Vector2f Player::Getpos() // Funci�n para obtener la posici�n del jugador
{

	return sprite->getPosition(); // Devuelve la posici�n actual del sprite
}

