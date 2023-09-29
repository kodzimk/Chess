#include "Lady.h"

Lady::Lady(const bool white)
{
	if (white)
		this->texture.loadFromFile("Resources/Images/TurnAlb.png");
	else
		this->texture.loadFromFile("Resources/Images/TurnNegru.png");

	this->lady.setTexture(texture);

	this->isWhite = white;
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

const bool Lady::isCanMove(sf::Vector2f pos)
{
	int x = static_cast<int>(pos.x / 100);
	int y = static_cast<int>(pos.y / 100);
	int x1 = static_cast<int>(this->lady.getPosition().x / 100);
	int y1 = static_cast<int>(this->lady.getPosition().y / 100);

	if (y > y1 && x1 == x)
	{
		for (int i = 0; i < 8; i++)
		{
			if (y1 + i == y)
			{
				return true;
			}
		}
	}
	else if (y < y1 && x1 == x)
	{
		for (int i = 0; i < 8; i++)
		{
			if (y + i == y1)
			{
				return true;
			}
		}
	}
	else if (y == y1 && x1 > x)
	{
		for (int i = 0; i < 8; i++)
		{
			if (x + i == x1)
			{
				return true;
			}
		}
	}
	else if (y == y1 && x1 < x)
	{
		for (int i = 0; i < 8; i++)
		{
			if (x1 + i == x)
			{
				return true;
			}
		}
	}

	return false;
}

const bool Lady::getGlobalBounds(sf::Vector2f pos)
{
	if (this->lady.getGlobalBounds().contains(pos))
		return true;

	return false;
}