#include "Game.h"

void Game::initStates()
{
	this->mainMenuState = new MainMenuState();
	this->gameState = nullptr;
}

Game::Game()
{
	this->initStates();
}

Game::~Game()
{
	delete this->mainMenuState;
	delete this->gameState;
}



void Game::update()
{

		if (this->mainMenuState)
		{
			this->mainMenuState->update();
			if (this->mainMenuState->updateText() && this->mainMenuState->isPressed)
			{
				this->gameState = new GameState();
				mainMenuState = nullptr;
			}

		}
		if (this->gameState)
			this->gameState->updateGame();
}


