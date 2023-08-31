#pragma once
#include<SFML/Graphics.hpp>
#include"board.h"


using namespace sf;
using namespace std;


class Queen {
public:
	Texture queen;
	Map map;
	Sprite queenS;

	Queen()
	{
		queen.loadFromFile("piece.png");
		queenS.setTexture(queen);
		queenS.setTextureRect(IntRect(90,0,60,100));
		queenS.setScale(1.5, 0.64);

	
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (map.map[i][j] == '5')
					{
						queenS.setPosition(j * 64, i * 64);
						
					}
				}
			}
	}

	void whiteMove()
	{
       
	}

};
