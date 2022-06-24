#include "enemigo.h"
using namespace std;
using namespace sf;

enemigo::enemigo()
{
	txt_enemigo.loadFromFile("recursos/4.png");
	_enemigo.setTexture(txt_enemigo);
	_enemigo.setOrigin(_enemigo.getGlobalBounds().width / 2, _enemigo.getGlobalBounds().height / 2);
	_enemigo.setScale(0.5f, 0.5f);

}

void enemigo::update()
{
	_enemigo.move(-6, 0);
	if (_enemigo.getPosition().x < 25) 
	{
		respawn();
	}
}

void enemigo::golpe()
{
	respawn();
}


void enemigo::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(_enemigo, states);
}


void enemigo::respawn()

{
	_enemigo.setPosition(1000, rand() % 450 + 55);
}


FloatRect enemigo::getBounds() const
{
	return _enemigo.getGlobalBounds();
}