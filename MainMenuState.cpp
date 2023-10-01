#include "MainMenuState.h"

void MainMenuState::initBackGround()
{
	backTexture.loadFromFile("Resources/Images/BackGround.png");
	background.setTexture(backTexture);
}

void MainMenuState::initGui()
{
	this->font.loadFromFile("Resources/Fonts/comic.ttf");

	this->playText.setFont(font);
	this->playText.setString("Play");
	this->playText.setCharacterSize(100);
	this->playText.setStyle(sf::Text::Bold);
	this->playText.setFillColor(sf::Color::Black);
	this->playText.setPosition(200, 400);

	this->quitText.setFont(font);
	this->quitText.setString("Quit");
	this->quitText.setCharacterSize(100);
	this->quitText.setStyle(sf::Text::Bold);
	this->quitText.setFillColor(sf::Color::Black);
	this->quitText.setPosition(200, 700);
}

MainMenuState::MainMenuState()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "chess");
	this->initBackGround();
	this->initGui();
	this->isPressed = false;
}

MainMenuState::~MainMenuState()
{
	delete this->window;
}

bool MainMenuState::updateText()
{
	if (this->playText.getGlobalBounds().contains(this->mousePosView))
	{
		this->isPressed = true;
		return true;
	}
	if (this->quitText.getGlobalBounds().contains(this->mousePosView))
	{
		this->isPressed = false;
		return true;
	}

	return false;
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
		this->mousePosView = sf::Vector2f(sf::Mouse::getPosition(*window));

		if (updateText() && isPressed &&sf::Mouse::isButtonPressed(sf::Mouse::Left))
			window->close();
		else if (updateText() && !isPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			window->close();
		}

		this->render();
	}
}

void MainMenuState::render()
{
	this->window->clear();
	this->window->draw(background);
	this->window->draw(this->playText);
	this->window->draw(this->quitText);
	this->window->display();
}
