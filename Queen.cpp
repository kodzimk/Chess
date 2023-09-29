#include "Queen.h"
Queen::Queen(const bool white)
{
	if (white)
		this->texture.loadFromFile("Resources/Images/ReginaAlb.png");
	else
		this->texture.loadFromFile("Resources/Images/ReginaNegru.png");

	this->queen.setTexture(texture);
	this->isWhite = white;
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
const bool Queen::isCanMove(sf::Vector2f pos)
{
	int x = static_cast<int>(pos.x / 100);
	int y = static_cast<int>(pos.y / 100);
	int x1 = static_cast<int>(this->queen.getPosition().x / 100);
	int y1 = static_cast<int>(this->queen.getPosition().y / 100);

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
	for (int i = 0; i < 8; i++)
	{
		if (x1 + i == x && y1 + i == y) {
			return true;
		}
	}
	for (int i = 0; i < 8; i++)
	{
		if (x1 - i == x && y1 + i == y) {
			return true;
		}
	}
	for (int i = 0; i < 8; i++)
	{
		if (x1 + i == x && y1 - i == y) {
			return true;
		}
	}
	for (int i = 0; i < 8; i++)
	{
		if (x1 - i == x && y1 - i == y) {
			return true;
		}
	}


	return false;
}