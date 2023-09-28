#pragma once
#include"stdafh.h"
#include"GameBoard.h"


class MainLoop {
public:
	sf::RenderWindow* window;
	GameBoard board;

	MainLoop();

	void updateGame();
	void render();


	~MainLoop();
};