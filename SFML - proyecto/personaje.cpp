#include "personaje.h"
#include <iostream>
using namespace std;
using namespace sf;


personaje::personaje()
{
	txt_char.loadFromFile("recursos/2.png");
	_character.setTexture(txt_char);
	_character.setScale(1.5f,1.5f);
}

void personaje::update() 
{
	//ejecucucion de comandos / joystick
	float _velocidad = 3;

	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		_character.move(0, -_velocidad);
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		_character.move(0, _velocidad);
	}
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		_character.move(-_velocidad, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		_character.move(_velocidad, 0);
	}

	//evitar que el personaje se vaya de la pantalla
	if (_character.getPosition().x < 25) {
		_character.setPosition(25, _character.getPosition().y);
	//getGlobalBounds te devuelve los bordes del objeto
	}
	if (_character.getPosition().y < 65) {
		_character.setPosition(_character.getPosition().x, 65);
	}
	if (_character.getPosition().x + _character.getGlobalBounds().width > 800) {
		_character.setPosition(800 - _character.getGlobalBounds().width, _character.getPosition().y);
	}
	if (_character.getPosition().y + _character.getGlobalBounds().width > 530) {
		_character.setPosition(_character.getPosition().x, 530 - _character.getGlobalBounds().width);
	}
}



//De esta manera estoy haciendo que mi personaje pueda ser dibujado 

void personaje::draw(RenderTarget& target, RenderStates states) const 
{
	target.draw(_character, states);
}



FloatRect personaje::getBounds() const
{
	return _character.getGlobalBounds();
}


void personaje::muerte()
{
}


