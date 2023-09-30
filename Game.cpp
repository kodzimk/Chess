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
		if (this->gameState)
			this->gameState->updateGame();
		if (this->mainMenuState)
			this->mainMenuState->update();
}

void Game::updateGame()
{
		this->update();
	
}

