#pragma once
#include<SFML/Graphics.hpp>
#include"board.h"

using namespace sf;
using namespace std;

class King {
public:
	Texture queen;
	Sprite queenS;
	Texture blackQu;
	Sprite blackQuS;


	King()
	{
		blackQu.loadFromFile("RegeNegru.png");
		blackQuS.setTexture(blackQu);

		queen.loadFromFile("RegeAlb.png");
		queenS.setTexture(queen);
	}

	void whiteMove()
	{
       
	}
	void blackMove()
	{

	}

};
