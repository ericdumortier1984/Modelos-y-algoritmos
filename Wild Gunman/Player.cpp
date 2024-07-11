#include "Player.h"

Player::Player() 
{

	sprite = new Sprite;
	texture = new Texture;
	texture->loadFromFile("Assets/imagenes/puntoDeMira.png");
	sprite->setTexture(*texture);
	texture->setSmooth(true);
	Vector2u size = texture->getSize();
	sprite->setOrigin(size.x / 2.0f, size.y / 2.0f);
}

Player::~Player()
{

	delete sprite;
	delete texture;
}

void Player::Draw(RenderWindow* _wnd)
{

	_wnd->draw(*sprite);
}

void Player::SetPosition(float x, float y)
{

	sprite->setPosition(x, y);
}

Vector2f Player::Getpos()
{

	return sprite->getPosition();
}

