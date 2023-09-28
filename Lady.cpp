#include "Lady.h"

Lady::Lady(const bool white)
{
	if (white)
		this->texture.loadFromFile("Resources/Images/TurnAlb.png");
	else
		this->texture.loadFromFile("Resources/Images/TurnNegru.png");

	this->lady.setTexture(texture);
}

Lady::Lady()
{

}

Lady::~Lady()
{
}

const sf::Vector2f Lady::getPositon()
{
	return this->lady.getPosition();
}


void Lady::setPosition(sf::Vector2f pos)
{
	this->lady.setPosition(pos.x, pos.y);
}

void Lady::render(sf::RenderWindow* window)
{
	window->draw(this->lady);
}

const bool Lady::getGlobalBounds(sf::Vector2f pos)
{
	if (this->lady.getGlobalBounds().contains(pos))
		return true;

	return false;
}