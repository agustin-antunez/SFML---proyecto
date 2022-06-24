#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class collisionable
{
//metodo polimorfico
public:
	virtual FloatRect getBounds() const = 0; //Cuando alguien lo herede implmente su propio metodo getBounds porque su constante es 0.
	bool isCollision(collisionable& colision) const;
};
