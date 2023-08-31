#pragma once
#include<SFML/Graphics.hpp>
#include"board.h"

using namespace sf;

class Rook {
public:
	Texture rook;
	Sprite rookS;
	Map map;

	Rook()
	{
		rook.loadFromFile("piece.png");
		rookS.setTexture(rook);
		rookS.setTextureRect(IntRect(350, 0, 60, 100));
		rookS.setScale(1, 0.64);


		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (map.map[i][j] == '1')
				{
					rookS.setPosition(j * 64, i * 64);
				}
			}
		}
	}
};
