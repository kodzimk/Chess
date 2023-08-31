#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"board.h"
#include"Queen.h"

using namespace sf;
using namespace std;

class MainLoop {
public:
	Map board;
	Queen whiteQueen;
	Queen blackQueen;
	RenderWindow window;

	MainLoop()
	{
		window.create(VideoMode(512, 512), "Chess Game");
		blackQueen = new Queen(true);
		whiteQueen = new Queen(false);
		Loop();
	}

	void Loop()
	{
		while (window.isOpen())
		{
			sf::Event event;

			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}
			window.close();
			window.draw(blackQueen.queenS);
			window.draw(whiteQueen.queenS);
			window.display();
		}
	}
};