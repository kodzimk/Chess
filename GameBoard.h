#pragma once
#include"stdafh.h"

class GameBoard {
public:
	sf::Texture texture;
	sf::Sprite sprite;

	int board[8][8] = {
		{6,2,3,4,5,3,2,6},
		{7,7,7,7,7,7,7,7},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{-7,-7,-7,-7,-7,-7,-7,-7},
		{-6,-2,-3,-4,-5,-3,-2,-6},
	};

	GameBoard()
	{
		texture.loadFromFile("Resources/Images/Board.png");
		sprite.setTexture(texture);
	}

	void render(sf::RenderWindow* window)
	{
		window->draw(sprite);
	}

	
};

