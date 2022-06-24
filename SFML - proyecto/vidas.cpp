#include "vidas.h"

vidas::vidas()
{
	txt_vidas.loadFromFile("recursos/proyectil.png");
	_vidas.setTexture(txt_vidas);
	_vidas.setOrigin(_vidas.getGlobalBounds().width / 2, _vidas.getGlobalBounds().height / 2);
}

void vidas::update()
{
	int x;
	x = -4;
	_vidas.move(x, 0);
	if (_vidas.getPosition().x < 25) {
		respawn();
	}
}

void vidas::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(_vidas, states);
}

void vidas::respawn()
{
	_vidas.setPosition(1000, rand() % 450 + 55);
}

FloatRect vidas::getBounds() const
{
	return _vidas.getGlobalBounds();
}
