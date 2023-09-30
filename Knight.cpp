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
  std::vector<Cor*> Knight::getNextCanMove()
{
	std::vector<Cor*> coordinates;
	int x1 = floor(this->knight.getPosition().x)  / 100;
	int y1 = floor(this->knight.getPosition().y)  / 100;

	if (y1 + 2 < 8 && x1 + 1 < 8)
	{
		coordinates.push_back(new Cor(y1 + 2,x1 +1));
	}
	 if (y1 + 2 <8 && x1 - 1 >= 0)
	{
		 coordinates.push_back(new Cor(y1 + 2, x1 - 1));
	}
	 if (y1 - 1 >= 0 && x1 + 2 < 8)
	{
		 coordinates.push_back(new Cor(y1 - 1, x1 + 2));
	
	}
	 if (y1 + 1 < 8 && x1 + 2 < 8)
	{
		 coordinates.push_back(new Cor(y1 + 1, x1 +2 ));
	}

	if (y1 + 1 < 8 && x1 - 2 >= 0)
	{
		coordinates.push_back(new Cor(y1 + 1, x1 - 2));
	}
	 if (y1 - 1 >= 0 && x1 - 2 >=0)
	{
		 coordinates.push_back(new Cor(y1 - 1, x1 - 2));
	}
	 if (y1 - 2 >=0 && x1 - 1 >=0)
	{
		 coordinates.push_back(new Cor(y1 - 2, x1 - 1));
	}
	 if (y1 - 2 >=0 && x1 + 1 < 8)
	{
		 coordinates.push_back(new Cor(y1 - 2, x1 + 1));
	}


	 return coordinates;
}

const bool Knight::isCanMove(sf::Vector2f pos)
{
	int x = floor(pos.x) / 100;
	int y =  floor(pos.y) / 100;
	int x1 = floor(this->knight.getPosition().x) / 100;
	int y1 = floor(this->knight.getPosition().y) / 100;


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
