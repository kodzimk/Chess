#pragma once
#include<SFML/Graphics.hpp>
#include"board.h"

using namespace sf;

class Rook {
public:
	Texture whiterookS;
	Sprite rookS;
	Texture blackRook;
	Sprite blackRookS;

	Rook()
	{
			whiterookS.loadFromFile("TurnAlb.png");
			rookS.setTexture(whiterookS);

			blackRook.loadFromFile("TurnNegru.png");
			blackRookS.setTexture(blackRook);
		
	}

};
