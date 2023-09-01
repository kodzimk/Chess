#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;

class Knight {
public:
	Texture white;
	Sprite whiteS;
	Texture black;
	Sprite blackS;

	Knight()
	{
		white.loadFromFile("CalAlb.png");
		whiteS.setTexture(white);
		black.loadFromFile("CalNegru.png");
		blackS.setTexture(black);
	}
};