#include "Enemy.h" // Incluye el archivo de encabezado de la clase Enemy

Enemy::Enemy(const string& texturePath, const Vector2f& pos, bool innocent) // Constructor de la clase Enemy
{

	// Crea el sprite y la textura del enemigo
	sprite = new Sprite;
	texture = new Texture;
	texture->loadFromFile(texturePath); // Carga la textura del enemigo desde el archivo
	sprite->setTexture(*texture); // Asigna la textura al sprite
	sprite->setPosition(position); // Establece la posición inicial del enemigo
	isInnocent = innocent; // Establece si el enemigo es inocente o no
}

Enemy::~Enemy() // Destructor de la clase Enemy
{

	// Libera la memoria ocupada por el sprite y la textura
	delete sprite;
	delete texture;
}

void Enemy::Draw(RenderWindow* _wnd) // Función para dibujar el enemigo en la ventana de renderizado
{

	_wnd->draw(*sprite); // Dibuja el sprite del enemigo en la ventana
}
