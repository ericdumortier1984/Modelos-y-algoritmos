#include "Key.h"

Key::Key()
{

	_keyTx.loadFromFile("Asset/Images/Key.png");
	_keySp.setTexture(_keyTx);
	_keySp.setOrigin(_keyTx.getSize().x / 2, 0);

	_position.x = 0.0f;
	_position.y = 0.0f;
}

Key::~Key()
{

}

void Key::Update(float deltaTime)
{

	_keySp.setPosition(_position);
}

void Key::Draw(RenderWindow* _wnd)
{

	_wnd->draw(_keySp);
}

void Key::SetKeyVisible(bool key_visible)
{

	_isKeyVisible = key_visible;
}

void Key::SetPosition(Vector2f keyPos)
{

	_position = keyPos;
}

Vector2f Key::GetPosition()
{

	return _position;
}

bool Key::IsKeyActive()
{

	return _isKeyVisible;
}
