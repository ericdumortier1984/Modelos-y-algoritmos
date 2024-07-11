#include "Enemy.h"

Enemy::Enemy(const string& texturePath, const Vector2f& pos, bool innocent)
{

	sprite = new Sprite;
	texture = new Texture;
	texture->loadFromFile(texturePath);
	sprite->setTexture(*texture);
	sprite->setPosition(position);
	isInnocent = innocent;
}

Enemy::~Enemy()
{

	delete sprite;
	delete texture;
}

void Enemy::Draw(RenderWindow* _wnd)
{

	_wnd->draw(*sprite);
}
