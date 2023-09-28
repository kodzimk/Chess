#include "Pawn.h"

Pawn::Pawn(const bool white)
{
	if(white)
	this->texture.loadFromFile("Resources/Images/PionAlb.png");
	else
	this->texture.loadFromFile("Resources/Images/PionNegru.png");

	this->pawn.setTexture(texture);
}

Pawn::Pawn()
{

}

Pawn::~Pawn()
{
}

const sf::Vector2f Pawn::getPositon()
{
	return this->pawn.getPosition();
}


void Pawn::setPosition(sf::Vector2f pos)
{
	this->pawn.setPosition(pos.x,pos.y);
}

void Pawn::render(sf::RenderWindow* window)
{
	window->draw(this->pawn);
}

const bool Pawn::getGlobalBounds(sf::Vector2f pos)
{
	if (this->pawn.getGlobalBounds().contains(pos))
		return true;
	
	return false;
}
