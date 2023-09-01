#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;

//K = knight
//R = ROOK
//W = CLONE
//F = King
//Q = QUEEN

class Map {
public:
	int map[8][8] = {
		6,2,3,4,5,3,2,6,
		1,1,1,1,1,1,1,1,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		-1,-1,-1,-1,-1,-1,-1,-1,
		-6,-2,-3,-4,-5,-3,-2,-6
	};
public:
	Texture board;
	Sprite boardS;

	Map()
	{
		board.loadFromFile("board.png");
		boardS.setTexture(board);
	}
};
