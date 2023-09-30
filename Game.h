#pragma once
#include"stdafh.h"
#include"mainLoop.h"
#include"MainMenuState.h"

class Game
{
public:

	//Variables
	GameState* gameState;
	MainMenuState* mainMenuState;


	//Initalizee functions
	void initStates();

	Game();
	~Game();

	//Functions
	void render();
	void update();
	void updateGame();
};

