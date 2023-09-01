#pragma once
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Pawn
{
public:
	Texture pawn;
	Sprite sprite;
	Texture blackPawn;
	Sprite blackPawnS;

	Pawn()
	{
			pawn.loadFromFile("PionAlb.png");
			sprite.setTexture(pawn);
		
			blackPawn.loadFromFile("PionNegru.png");
			blackPawnS.setTexture(blackPawn);
		
	}


};