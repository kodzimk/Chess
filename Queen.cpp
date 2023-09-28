#include "Queen.h"
Queen::Queen(const bool white)
{
	if (white)
		this->texture.loadFromFile("Resources/Images/ReginaAlb.png");
	else
		this->texture.loadFromFile("Resources/Images/ReginaNegru.png");

	this->queen.setTexture(texture);
}

Queen::Queen()
{

}

Queen::~Queen()
{
}

const sf::Vector2f Queen::getPositon()
{
	return this->queen.getPosition();
}


void Queen::setPosition(sf::Vector2f pos)
{
	this->queen.setPosition(pos.x, pos.y);
}

void Queen::render(sf::RenderWindow* window)
{
	window->draw(this->queen);
}

const bool Queen::getGlobalBounds(sf::Vector2f pos)
{
	if (this->queen.getGlobalBounds().contains(pos))
		return true;

	return false;
}