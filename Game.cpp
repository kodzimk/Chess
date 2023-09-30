#include "Game.h"

void Game::initStates()
{
	this->mainMenuState = nullptr;
	this->gameState = new GameState();
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

void Game::render()
{
	if(this->gameState)
	this->gameState->render();
}

void Game::update()
{
	if(this->gameState)
	this->gameState->updateGame();
}

void Game::updateGame()
{
	this->update();
	this->render();
}

