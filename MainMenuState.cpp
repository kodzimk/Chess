#include "MainMenuState.h"

void MainMenuState::initBackGround()
{
	backTexture.loadFromFile("");
	background.setTexture(backTexture);
}

MainMenuState::MainMenuState()
{
	this->initBackGround();
}

MainMenuState::~MainMenuState()
{

}

void MainMenuState::update()
{

}

void MainMenuState::render(sf::RenderWindow* window)
{
	window->draw(background);
}
