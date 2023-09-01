#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;

class Queen {
public:
	Texture blackT;
	Texture whiteT;
	Sprite blackS;
	Sprite whiteS;

	Queen()
	{
		blackT.loadFromFile("ReginaNegru.png");
		blackS.setTexture(blackT);
		whiteT.loadFromFile("ReginaAlb.png");
		whiteS.setTexture(whiteT);
	}
};