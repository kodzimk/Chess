#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;

class Bishop {
public:
	Texture blackT;
	Sprite blackS;
	Texture whiteT;
	Sprite whiteS;

	Bishop()
	{
		blackT.loadFromFile("NebunNegru.png");
		blackS.setTexture(blackT);

		whiteT.loadFromFile("NebunAlb.png");
		whiteS.setTexture(whiteT);
	}
};
