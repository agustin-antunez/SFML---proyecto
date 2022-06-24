#pragma once
#include <SFML/Graphics.hpp>
#include "collisionable.h"
using namespace sf;
using namespace std;
class personaje : public::Drawable, public collisionable
{
public://metodos
	personaje();
	void update();
	void draw(RenderTarget& target, RenderStates states) const override;
	FloatRect getBounds() const override; //el metodo override significa que este esta sobreescribiendo el metodo de alguno de los padres
	void muerte();

private: //atributos
	Sprite _character;
	Texture txt_char;
	
};
