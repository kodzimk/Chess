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

	Queen(bool isBlack)
	{
		queen.loadFromFile("piece.png");
		queenS.setTexture(queen);
		queenS.setTextureRect(IntRect(100,0,90,100));
		queenS.setScale(0.7, 0.64);

		if (isBlack == false)
		{
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (map.map[i][j] == "5")
					{
						queenS.setPosition(j * 64, i * 64);
						break;
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (map.map[i][j] == "")
					{
						queenS.setPosition(j * 64, i * 64);
						break;
					}
				}
			}
		}
	}

	Queen()
	{

	}

	void whiteMove()
	{
       
	}

};
