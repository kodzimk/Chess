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
	string map[8] = {
		"12345321",
		"00000000",
		"        ",
		"        ",
		"        ",
		"        ",
		"PPPPPPPP",
		"RKWFQWKR"
	};
public:
	Texture board;
	Sprite boardS;

	Map()
	{
		board.loadFromFile("board.png");
		boardS.setTexture(board);
		boardS.setScale(0.25, 0.25);
	}
};
