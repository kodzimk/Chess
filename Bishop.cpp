#include "Bishop.h"
Bishop::Bishop(const bool white)
{
	if (white)
		this->texture.loadFromFile("Resources/Images/NebunAlb.png");
	else
		this->texture.loadFromFile("Resources/Images/NebunNegru.png");

	this->bishop.setTexture(texture);
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
