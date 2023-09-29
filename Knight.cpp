#include "Knight.h"
Knight::Knight(const bool white)
{
	if (white)
		this->texture.loadFromFile("Resources/Images/CalAlb.png");
	else
		this->texture.loadFromFile("Resources/Images/CalNegru.png");

	this->knight.setTexture(texture);

	this->isWhite = white;
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
const bool Knight::isCanMove(sf::Vector2f pos)
{
	int x = static_cast<int>(pos.x / 100);
	int y = static_cast<int>(pos.y / 100);
	int x1 = static_cast<int>(this->knight.getPosition().x / 100);
	int y1 = static_cast<int>(this->knight.getPosition().y / 100);

	if (y1 + 2 == y && x1 + 1 == x)
	{
		return true;
	}
	else if (y1 + 2 == y && x1 - 1 == x)
	{
		return true;
	}
	else if (y1 - 1 == y && x1 + 2 == x)
	{
		return true;
	}
	else if (y1 + 1 == y && x1 + 2 == x)
	{
		return true;
	}

	if (y1 + 1 == y && x1 - 2 == x)
	{
		return true;
	}
	else if (y1 - 1  == y && x1 - 2 == x)
	{
		return true;
	}
	else if (y1 - 2  == y && x1  - 1 == x)
	{
		return true;
	}
	else if (y1 - 2 == y && x1 + 1 == x)
	{
		return true;
	}

	return false;
}
