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
	int x = floor(pos.x) / 100;
	int y = floor(pos.y) / 100;
	int x1 = this->pawn.getPosition().x / 100;
	int y1 = this->pawn.getPosition().y / 100;

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

const std::vector<Cor*> Pawn::getNextMove()
{
	std::vector<Cor*> coordinates;
	int x1 = floor(this->pawn.getPosition().x) / 100;
	int y1 = floor(this->pawn.getPosition().y) / 100;

	if (y1+1 <8&&x1+1 <8 && this->isWhite)
	{
		coordinates.push_back(new Cor(y1 + 1, x1 + 1));
	}
	 if (y1 + 1 <8&&x1-1>0 && this->isWhite)
	{
		 coordinates.push_back(new Cor(y1 + 1, x1 - 1));
	}
	 if (y1 - 1 > 0 && x1 + 1 < 8 && !this->isWhite)
	 {
		 coordinates.push_back(new Cor(y1 - 1, x1 + 1));
	 }
	 if (y1 - 1 > 0 && x1 - 1 > 0 && !this->isWhite)
	 {
		 coordinates.push_back(new Cor(y1 - 1, x1 - 1));
	 }

	return coordinates;
}

const bool Pawn::isOpen(sf::Vector2f pos, std::vector<Knight*> knight, std::vector<Pawn*> white, std::vector<Pawn*> black, std::vector<Lady*> ladies, std::vector<Bishop*> bishops, Queen* blackQueen)
{
	return false;
}

