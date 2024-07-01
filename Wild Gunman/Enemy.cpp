#include "Enemy.h"

Enemy::Enemy() 
{
	_isAlive = true;
	_isVisible = false;
	timeVisible = 1.5f;
	timeNotVisible = 2.0f;

	InitEnemies();
}

Enemy::~Enemy()
{
	delete _sprite;
	delete _texture;
}

void Enemy::Draw(RenderWindow& wnd) 
{
	wnd.draw(*_sprite);
}

void Enemy::InitEnemies()
{
	_texture = new Texture;
	switch (_typeEnemy)
	{
	case 0:
		_texture->loadFromFile("Assets/imagenes/enemy1.png");
		break;
	case 1:
		_texture->loadFromFile("Assets/imagenes/enemy2.png");
		break;
	case 2:
		_texture->loadFromFile("Assets/imagenes/enemy3.png");
		break;
		// Agrega más casos según el número de tipos de enemigos que tengas
	default:
		_texture->loadFromFile("Assets/imagenes/Innocent.png");
		break;
	}
	_sprite = new Sprite(*_texture);
	_sprite->setTexture(*_texture);
	_sprite->setOrigin(_sprite->getOrigin().x / 2, _sprite->getOrigin().y / 2);
	_sprite->setPosition(_position);
}

//Esta función establece una nueva textura para el sprite enemy
void Enemy::SetTexture(const string& texturePath)
{
	_texture->loadFromFile(texturePath);
}

float Enemy::GetVisibleTime() 
{
	return timeVisible;
}

void Enemy::Reset(RenderWindow& wnd) 
{
	_isAlive = true;
	_isVisible = false;
}

bool Enemy::IsAlive() 
{
	return _isAlive;
}

bool Enemy::Die()
{
	_isAlive = false;
	return _isAlive;
}

bool Enemy::IsInGame() 
{
	return _isAlive && _isVisible;
}

bool Enemy::Shoot() 
{
	bool Shoot = false;
	if (_isAlive && _isVisible)
	{
		Shoot = rand() % 100 == 20;
	}
	return Shoot;
}

bool Enemy::IsAbove(float x, float y) 
{
	FloatRect bounds_sprite = _sprite->getGlobalBounds();
	return bounds_sprite.contains(x, y);
}
