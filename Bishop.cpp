#include "Bishop.h"
Bishop::Bishop(const bool white)
{
	if (white)
		this->texture.loadFromFile("Resources/Images/NebunAlb.png");
	else
		this->texture.loadFromFile("Resources/Images/NebunNegru.png");

	this->bishop.setTexture(texture);

	this->isWhite = white;
}

Bishop::Bishop()
{

}

Bishop::~Bishop()
{
}

const sf::Vector2f Bishop::getPositon()
{
	return this->bishop.getPosition();
}


void Bishop::setPosition(sf::Vector2f pos)
{
	this->bishop.setPosition(pos.x, pos.y);
}

void Bishop::render(sf::RenderWindow* window)
{
	window->draw(this->bishop);
}

const bool Bishop::getGlobalBounds(sf::Vector2f pos)
{
	if (this->bishop.getGlobalBounds().contains(pos))
		return true;

	return false;
}

const bool Bishop::isCanMove(sf::Vector2f pos)
{
	int x = static_cast<int>(pos.x / 100);
	int y = static_cast<int>(pos.y / 100);
	int x1 = static_cast<int>(this->bishop.getPosition().x / 100);
	int y1 = static_cast<int>(this->bishop.getPosition().y / 100);

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
