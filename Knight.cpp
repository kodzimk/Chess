#include "Knight.h"
Knight::Knight(const bool white)
{
	if (white)
		this->texture.loadFromFile("Resources/Images/CalAlb.png");
	else
		this->texture.loadFromFile("Resources/Images/CalNegru.png");

	this->knight.setTexture(texture);
}

Knight::Knight()
{

}

Knight::~Knight()
{
}

const sf::Vector2f Knight::getPositon()
{
	return this->knight.getPosition();
}


void Knight::setPosition(sf::Vector2f pos)
{
	this->knight.setPosition(pos.x, pos.y);
}

void Knight::render(sf::RenderWindow* window)
{
	window->draw(this->knight);
}

const bool Knight::getGlobalBounds(sf::Vector2f pos)
{
	if (this->knight.getGlobalBounds().contains(pos))
		return true;

	return false;
}
