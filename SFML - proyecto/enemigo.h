#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "collisionable.h"
using namespace sf;

class enemigo : public::Drawable, public collisionable
{
public:
	enemigo();
	void update();
	void draw(RenderTarget& target, RenderStates states) const override;
	void respawn();
	void golpe();
	FloatRect getBounds() const override;

private:
	Sprite _enemigo;
	Texture txt_enemigo;
};

