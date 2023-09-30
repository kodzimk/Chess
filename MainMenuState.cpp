#include "MainMenuState.h"

void MainMenuState::initBackGround()
{
	backTexture.loadFromFile("Resources/Images/BackGround.png");
	background.setTexture(backTexture);
}

MainMenuState::MainMenuState()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "chess");
	this->initBackGround();
}

MainMenuState::~MainMenuState()
{
	delete this->window;
}

void MainMenuState::update()
{
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}
		this->render();
	}
}

void MainMenuState::render()
{
	window->clear();
	this->window->draw(background);
	window->display();
}
