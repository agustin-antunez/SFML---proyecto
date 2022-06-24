#include "powerUps.h"
#include <iostream>
using namespace std;

powerUps::powerUps()
{
	txt_item.loadFromFile("recursos/manzana.png");
	_item.setTexture(txt_item);
	_item.setOrigin(_item.getGlobalBounds().width / 2, _item.getGlobalBounds().height / 2);
}

void powerUps::update()
{
	int x;
	x = -4;
	_item.move(x, 0);
	if (_item.getPosition().x < 25) {
		respawn();
	}
}


void powerUps::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(_item, states);
}

void powerUps::respawn()
{
	_item.setPosition(1000, rand() % 450 + 55);
}

FloatRect powerUps::getBounds() const
{
	return _item.getGlobalBounds();
}
