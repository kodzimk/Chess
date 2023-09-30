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
	int x = floor(pos.x) / 100;
	int y = floor(pos.y) / 100;
	int x1 =floor(this->lady.getPosition().x) / 100;
	int y1 =floor(this->lady.getPosition().y) / 100;
	
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

const std::vector<Cor*> Lady::getNextMove()
{
	std::vector<Cor*> coordinates;
	int x1 = floor(this->lady.getPosition().x)  / 100;
	int y1 = floor(this->lady.getPosition().y)  / 100;

	 if (y1 >= 0 || 8 > y1)
	{
		for (int i = 0; i < 8; i++)
		{
			if (y1 + i < 8)
			{
				coordinates.push_back(new Cor(y1 + i, x1));
			}
			if (y1 - i >= 0)
			{
				coordinates.push_back(new Cor(y1 - i, x1));
			}
		}
	}

	 if (x1 >= 0|| x1 < 8)
	{
		for (int i = 0; i < 8; i++)
		{
			if (x1 + i < 8)
			{
				coordinates.push_back(new Cor(y1, x1 + i));
			}
			if (x1 - i >= 0)
			{
				coordinates.push_back(new Cor(y1, x1 - i));
			}
		}
	}

	return coordinates;
}

const bool Lady::getGlobalBounds(sf::Vector2f pos)
{
	if (this->lady.getGlobalBounds().contains(pos))
		return true;

	return false;
}

const bool Lady::IsOpen(sf::Vector2f pos, std::vector<Knight*> knight, std::vector<Pawn*> white, std::vector<Pawn*> black, std::vector<Lady*> ladies, std::vector<Bishop*> bishops, Queen* blackQueen)
{
	int x = floor(pos.x) / 100;
	int y = floor(pos.y) / 100;
	int x1 = floor(this->lady.getPosition().x) / 100;
	int y1 = floor(this->lady.getPosition().y) / 100;

	if (y1 == y && x < x1)
	{
		for (size_t i = 0; i < knight.size(); i++)
		{
			int x2 = floor(knight[i]->getPositon().x) / 100;
			int y2 = floor(knight[i]->getPositon().y) / 100;
			if (y2 == y && x2 < x1 && x < x2)
				return false;
		}
		for (size_t i = 0; i < white.size(); i++)
		{
			int x2 = floor(white[i]->getPositon().x) / 100;
			int y2 = floor(white[i]->getPositon().y) / 100;
			if (y2 == y && x2 < x1 && x < x2)
				return false;
		}
		for (size_t i = 0; i < black.size(); i++)
		{
			int x2 = floor(black[i]->getPositon().x) / 100;
			int y2 = floor(black[i]->getPositon().y) / 100;
			if (y2 == y && x2 < x1 && x < x2)
				return false;
		}
		for (size_t i = 0; i < ladies.size(); i++)
		{
			int x2 = floor(ladies[i]->getPositon().x) / 100;
			int y2 = floor(ladies[i]->getPositon().y) / 100;
			if (y2 == y && x2 < x1 && x < x2)
				return false;
		}
		for (size_t i = 0; i < bishops.size(); i++)
		{
			int x2 = floor(bishops[i]->getPositon().x) / 100;
			int y2 = floor(bishops[i]->getPositon().y) / 100;
			if (y2 == y && x2 < x1 && x < x2)
				return false;
		}
		int x2 = floor(blackQueen->getPositon().x) / 100;
		int y2 = floor(blackQueen->getPositon().y) / 100;
		if (y2 == y && x2 < x1 && x < x2)
			return false;


		for (int i = 0; i < 8; i++)
		{
			if (x1 + i == x)
			{
				return true;
			}
		}
	}
	if (y1 == y && x > x1)
	{
		for (size_t i = 0; i < knight.size(); i++)
		{
			int x2 = floor(knight[i]->getPositon().x) / 100;
			int y2 = floor(knight[i]->getPositon().y) / 100;

			if (y2 == y && x2 < x && x1 < x2)
				return false;
		}
		for (size_t i = 0; i < white.size(); i++)
		{
			int x2 = floor(white[i]->getPositon().x) / 100;
			int y2 = floor(white[i]->getPositon().y) / 100;
			if (y2 == y1 && x2 < x && x1 < x2)
				return false;
		}
		for (size_t i = 0; i < black.size(); i++)
		{
			int x2 = floor(black[i]->getPositon().x) / 100;
			int y2 = floor(black[i]->getPositon().y) / 100;
			if (y2 == y1 && x2 < x && x1 < x2)
				return false;
		}
		for (size_t i = 0; i < ladies.size(); i++)
		{
			int x2 = floor(ladies[i]->getPositon().x) / 100;
			int y2 = floor(ladies[i]->getPositon().y) / 100;
			if (y2 == y && x2 < x && x1 < x2)
				return false;
		}
		for (size_t i = 0; i < bishops.size(); i++)
		{
			int x2 = floor(bishops[i]->getPositon().x) / 100;
			int y2 = floor(bishops[i]->getPositon().y) / 100;
			if (y2 == y && x2 < x && x1 < x2)
				return false;
		}
		int x2 = floor(blackQueen->getPositon().x) / 100;
		int y2 = floor(blackQueen->getPositon().y) / 100;
		if (y2 == y && x2 < x && x1 < x2)
			return false;


		for (int i = 0; i < 8; i++)
		{
			if (x1 + i == x)
			{
				return true;
			}
		}
	}
	if (y1 > y && x == x1)
	{
		for (size_t i = 0; i < knight.size(); i++)
		{
			int x2 = floor(knight[i]->getPositon().x) / 100;
			int y2 = floor(knight[i]->getPositon().y) / 100;
			if (y2 < y1 && y2 > y && x == x2)
				return false;
		}
		for (size_t i = 0; i < white.size(); i++)
		{
			int x2 = floor(white[i]->getPositon().x) / 100;
			int y2 = floor(white[i]->getPositon().y) / 100;
			if (y2 < y1 && y2 > y && x == x2)
				return false;
		}
		for (size_t i = 0; i < black.size(); i++)
		{
			int x2 = floor(black[i]->getPositon().x) / 100;
			int y2 = floor(black[i]->getPositon().y) / 100;
			if (y2 < y1 && y2 > y && x == x2)
				return false;
		}
		for (size_t i = 0; i < ladies.size(); i++)
		{
			int x2 = floor(ladies[i]->getPositon().x) / 100;
			int y2 = floor(ladies[i]->getPositon().y) / 100;
			if (y2 < y1 && y2 > y && x == x2)
				return false;
		}
		for (size_t i = 0; i < bishops.size(); i++)
		{
			int x2 = floor(bishops[i]->getPositon().x) / 100;
			int y2 = floor(bishops[i]->getPositon().y) / 100;
			if (y2 < y1 && y2 > y && x == x2)
				return false;
		}
		int x2 = floor(blackQueen->getPositon().x) / 100;
		int y2 = floor(blackQueen->getPositon().y) / 100;
		if (y2 < y1 && y2 > y && x == x2)
			return false;


		for (int i = 0; i < 8; i++)
		{
			if (y + i == y1)
			{
				return true;
			}
		}
	}
	if (y1 < y && x == x1)
	{
		for (size_t i = 0; i < knight.size(); i++)
		{
			int x2 = floor(knight[i]->getPositon().x) / 100;
			int y2 = floor(knight[i]->getPositon().y) / 100;
			if (y2 > y1 && y2 < y && x == x2)
				return false;
		}
		for (size_t i = 0; i < white.size(); i++)
		{
			int x2 = floor(white[i]->getPositon().x) / 100;
			int y2 = floor(white[i]->getPositon().y) / 100;
			if (y2 > y1 && y2 < y && x == x2)
				return false;
		}
		for (size_t i = 0; i < black.size(); i++)
		{
			int x2 = floor(black[i]->getPositon().x) / 100;
			int y2 = floor(black[i]->getPositon().y) / 100;
			if (y2 > y1 && y2 < y && x == x2)
				return false;
		}
		for (size_t i = 0; i < ladies.size(); i++)
		{
			int x2 = floor(ladies[i]->getPositon().x) / 100;
			int y2 = floor(ladies[i]->getPositon().y) / 100;
			if (y2 > y1 && y2 < y && x == x2)
				return false;
		}
		for (size_t i = 0; i < bishops.size(); i++)
		{
			int x2 = floor(bishops[i]->getPositon().x) / 100;
			int y2 = floor(bishops[i]->getPositon().y) / 100;
			if (y2 > y1 && y2 < y && x == x2)
				return false;
		}
		int x2 = floor(blackQueen->getPositon().x) / 100;
		int y2 = floor(blackQueen->getPositon().y) / 100;
		if (y2 > y1 && y2 < y && x == x2)
			return false;


		for (int i = 0; i < 8; i++)
		{
			if (y1 + i == y)
			{
				return true;
			}
		}
	}

	return false;
}
