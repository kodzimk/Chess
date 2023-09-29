#include "Pawn.h"

Pawn::Pawn(const bool white)
{

	if(white)
	this->texture.loadFromFile("Resources/Images/PionAlb.png");
	else
	this->texture.loadFromFile("Resources/Images/PionNegru.png");

	this->pawn.setTexture(texture);

	this->isWhite = white;
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

const bool Pawn::IsCanMove(sf::Vector2f pos)
{
	int x = static_cast<int>(pos.x / 100);
	int y = static_cast<int>(pos.y / 100);
	int x1 = static_cast<int>(this->pawn.getPosition().x / 100);
	int y1 = static_cast<int>(this->pawn.getPosition().y / 100);

	if (x == x1 && (y1 + 2 == y || y1+ 1==y)&& this->isWhite)
	{
		return true;
	}
	else if (x == x1 && (y1 - 2 == y || y1 - 1 == y) && !this->isWhite)
	{
		return true;
	}

	return false;
}

