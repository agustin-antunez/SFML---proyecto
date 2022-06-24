#pragma once
#include <SFML/Graphics.hpp>
#include "collisionable.h"
using namespace sf;

class powerUps : public::Drawable, public collisionable
{
public:
	powerUps();
	void update();
	void draw(RenderTarget& target, RenderStates states) const override;
	void respawn();
	FloatRect getBounds() const override;

private:
	Sprite _item;
	Texture txt_item;

};

