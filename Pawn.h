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

	void whiteMove(Vector2i mousPos,bool &clicked)
	{
		if (sprite.getGlobalBounds().contains(mousPos.x, mousPos.y))
		{
			clicked = true;
		}
	}

	void blackMove(Vector2i mousPos, bool& clicked)
	{
		if (blackPawnS.getGlobalBounds().contains(mousPos.x, mousPos.y))
		{
			clicked = true;
		}
	}
};