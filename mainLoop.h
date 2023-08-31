#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"board.h"
#include"Queen.h"
#include"Rook.h"

using namespace sf;
using namespace std;

class MainLoop {
public:
	Map board;
	Queen blackQueen;
	RenderWindow window;
	Rook rook;

	MainLoop()
	{
		window.create(VideoMode(512, 512), "Chess Game");

		Loop();
	}

	void Loop()
	{
		while (window.isOpen())
		{
			Event event;

			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear();
			window.draw(board.boardS);
			window.draw(blackQueen.queenS);
			window.draw(rook.rookS);
			window.display();
		}
	}
};