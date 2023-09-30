#include "King.h"
King::King(const bool white)
{
	if (white)
		this->texture.loadFromFile("Resources/Images/RegeAlb.png");
	else
		this->texture.loadFromFile("Resources/Images/RegeNegru.png");

	this->king.setTexture(texture);

	this->isWhite = white;
}

King::King()
{

}

King::~King()
{
}

const sf::Vector2f King::getPositon()
{
	return this->king.getPosition();
}


void King::setPosition(sf::Vector2f pos)
{
	this->king.setPosition(pos.x, pos.y);
}

void King::render(sf::RenderWindow* window)
{
	window->draw(this->king);
}

const bool King::getGlobalBounds(sf::Vector2f pos)
{
	if (this->king.getGlobalBounds().contains(pos))
		return true;

	return false;
}
const bool King::IsCanMove(sf::Vector2f pos)
{
	int x =  pos.x / 100;
	int y =  pos.y / 100;
	int x1 = this->king.getPosition().x / 100;
	int y1 = this->king.getPosition().y / 100;
	
	if (x1 + 1 == x && y1 + 1 == y)
	{
		return true;
	}
	else if (x1 == x && y1 + 1 == y)
	{
		return true;
	}
	else if (x1 - 1 == x && y1 + 1 == y)
	{
		return true;
	}
	else if (x1 - 1 == x && y1 == y)
	{
		return true;
	}
	else if (x1 + 1 == x && y1 == y)
	{
		return true;
	}
	else if (x1 - 1 == x && y1 - 1 == y)
	{
		return true;
	}
	else if (x1 == x && y1 - 1 == y)
	{
		return true;
	}
	else if (x1 + 1 == x && y1 - 1 == y)
	{
		return true;
	}

	return false;
}

