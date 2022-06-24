#pragma once
#include <SFML/Graphics.hpp>
#include "collisionable.h"
using namespace sf;
using namespace std;
class vidas : public::Drawable, public collisionable
{
public:
	vidas();
	void update();
	void draw(RenderTarget& target, RenderStates states) const override;
	void respawn();
	FloatRect getBounds() const override;


private:

	Sprite _vidas;
	Texture txt_vidas;

};

