#include "collisionable.h"
using namespace sf;

bool collisionable::isCollision(collisionable& obj) const {
	return getBounds().intersects(obj.getBounds()); //Esto lo que hace es implementarle ya la funcion de colision, ya con esto se podria colisionar con cualquier cosa
}
//Para poder colisionar se necesita obtener el getBounds de lo que quiero colisionar.
//Eso lo va a heredar cada objeto que es colisionable, es decir, cada uno va a implementar su manera de obtener los bounds 
