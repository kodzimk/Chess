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
	int x = floor(pos.x) / 100;
	int y = floor(pos.y) / 100;
	int x1 = floor(this->queen.getPosition().x) / 100;
	int y1 = floor(this->queen.getPosition().y) / 100;

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

const bool Queen::isOpen(sf::Vector2f pos,std::vector<Knight*> knight, std::vector<Pawn*> white, std::vector<Pawn*> black, std::vector<Lady*> ladies, std::vector<Bishop*> bishops, Queen* blackQueen)
{
	int x = floor(pos.x) / 100;
	int y = floor(pos.y) / 100;
	int x1 = floor(this->queen.getPosition().x) / 100;
	int y1 = floor(this->queen.getPosition().y) / 100;

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
			if (y2 == y && x2 <x1 && x < x2)
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
			if (y2 == y && x2 < x && x1 < x2)
				return false;
		}
		for (size_t i = 0; i < black.size(); i++)
		{
			int x2 = floor(black[i]->getPositon().x) / 100;
			int y2 = floor(black[i]->getPositon().y) / 100;
			if (y2 == y && x2 < x && x1 < x2)
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
			if (x + i == x1)
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


	if (y1 < y && x1 < x)
	{
		for (size_t i = 0; i < knight.size(); i++)
		{
			int x2 = floor(knight[i]->getPositon().x) / 100;
			int y2 = floor(knight[i]->getPositon().y) / 100;
			if (x2 < x && y2 < y)
			{
				for (int j = 0; j < 8; j++)
				{
					if (x1 + j == x2 && y1 + j == y2) {
						return false;
					}
				}
			}
			
		}
		for (size_t i = 0; i < white.size(); i++)
		{
			int x2 = floor(white[i]->getPositon().x) / 100;
			int y2 = floor(white[i]->getPositon().y) / 100;
			if (x2 < x && y2 < y)
			{
				for (int j = 0; j < 8; j++)
				{
					if (x1 + j == x2 && y1 + j == y2) {
						return false;
					}
				}
			}
		}
		for (size_t i = 0; i < black.size(); i++)
		{
			int x2 = floor(black[i]->getPositon().x) / 100;
			int y2 = floor(black[i]->getPositon().y) / 100;

			if (x2 < x && y2 < y)
			{
				for (int j = 0; j < 8; j++)
				{
					if (x1 + j == x2 && y1 + j == y2) {
						return false;
					}
				}
			}
		}
		for (size_t i = 0; i < ladies.size(); i++)
		{
			int x2 = floor(ladies[i]->getPositon().x) / 100;
			int y2 = floor(ladies[i]->getPositon().y) / 100;

			if (x2 < x && y2 < y)
			{
				for (int j = 0; j < 8; j++)
				{
					if (x1 + j == x2 && y1 + j == y2) {
						return false;
					}
				}
			}
		}
		for (size_t i = 0; i < bishops.size(); i++)
		{
			int x2 = floor(bishops[i]->getPositon().x) / 100;
			int y2 = floor(bishops[i]->getPositon().y) / 100;

			if (x2 < x && y2 < y)
			{
				for (int j = 0; j < 8; j++)
				{
					if (x1 + j == x2 && y1 + j == y2) {
						return false;
					}
				}
			}
		}
		int x2 = floor(blackQueen->getPositon().x) / 100;
		int y2 = floor(blackQueen->getPositon().y) / 100;
		if (x2 < x && y2 < y)
		{
			for (int j = 0; j < 8; j++)
			{
				if (x1 + j == x2 && y1 + j == y2) {
					return false;
				}
			}
		}


		for (int i = 0; i < 8; i++)
		{
			if (x1 + i == x && y1 + i == y) {
				return true;
			}
		}
	}
	if (y1 < y && x1 > x)
	{
		for (size_t i = 0; i < knight.size(); i++)
		{
			int x2 = floor(knight[i]->getPositon().x) / 100;
			int y2 = floor(knight[i]->getPositon().y) / 100;
			for (int j = 0; j < 8; j++)
			{

				if (x1 - j == x2 && y1 + j == y2) {
					return false;
				}

			}
		}
		for (size_t i = 0; i < white.size(); i++)
		{
			int x2 = floor(white[i]->getPositon().x) / 100;
			int y2 = floor(white[i]->getPositon().y) / 100;

				for (int j = 0; j < 8; j++)
				{

					if (x1 - j == x2 && y1 + j == y2) {
						return false;
					}

				}
			
		}
		for (size_t i = 0; i < black.size(); i++)
		{
			int x2 = floor(black[i]->getPositon().x) / 100;
			int y2 = floor(black[i]->getPositon().y) / 100;

				for (int j = 0; j < 8; j++)
				{

					if (x1 - j == x2 && y1 + j == y2) {
						return false;
					}

				}		
		}
		for (size_t i = 0; i < ladies.size(); i++)
		{
			int x2 = floor(ladies[i]->getPositon().x) / 100;
			int y2 = floor(ladies[i]->getPositon().y) / 100;

				for (int j = 0; j < 8; j++)
				{

					if (x1 - j == x2 && y1 + j == y2) {
						return false;
					}

				}
			
		}
		for (size_t i = 0; i < bishops.size(); i++)
		{
			int x2 = floor(bishops[i]->getPositon().x) / 100;
			int y2 = floor(bishops[i]->getPositon().y) / 100;


				for (int j = 0; j < 8; j++)
				{

					if (x1 - j == x2 && y1 + j == y2) {
						return false;
					}

			
			    }
		}
		int x2 = floor(blackQueen->getPositon().x) / 100;
		int y2 = floor(blackQueen->getPositon().y) / 100;
			for (int j = 0; j < 8; j++)
			{

				if (x1 - j == x2 && y1 + j == y2) {
					return false;
				}

			}
		


		for (int i = 0; i < 8; i++)
		{
			if (x1 - i == x && y1 + i == y) {
				return true;
			}
		}
	}
	if (y1 > y && x1 < x)
	{
		for (size_t i = 0; i < knight.size(); i++)
		{
			int x2 = floor(knight[i]->getPositon().x) / 100;
			int y2 = floor(knight[i]->getPositon().y) / 100;
			if (x2< x && y2 > y)
			{
				for (int j = 0; j < 8; j++)
				{
					if (x1 + j == x2 && y1 - j == y2) {
						return false;
					}

				}
			}
		}
		for (size_t i = 0; i < white.size(); i++)
		{
			int x2 = floor(white[i]->getPositon().x) / 100;
			int y2 = floor(white[i]->getPositon().y) / 100;
			if (x2< x && y2 > y)
			{
				for (int j = 0; j < 8; j++)
				{
					if (x1 + j == x2 && y1 - j == y2) {
						return false;
					}

				}
			}

		}
		for (size_t i = 0; i < black.size(); i++)
		{
			int x2 = floor(black[i]->getPositon().x) / 100;
			int y2 = floor(black[i]->getPositon().y) / 100;

			if (x2< x && y2 > y)
			{
				for (int j = 0; j < 8; j++)
				{
					if (x1 + j == x2 && y1 - j == y2) {
						return false;
					}

				}
			}
		}
		for (size_t i = 0; i < ladies.size(); i++)
		{
			int x2 = floor(ladies[i]->getPositon().x) / 100;
			int y2 = floor(ladies[i]->getPositon().y) / 100;

			if (x2< x && y2 > y)
			{
				for (int j = 0; j < 8; j++)
				{
					if (x1 + j == x2 && y1 - j == y2) {
						return false;
					}
				}
			}

		}
		for (size_t i = 0; i < bishops.size(); i++)
		{
			int x2 = floor(bishops[i]->getPositon().x) / 100;
			int y2 = floor(bishops[i]->getPositon().y) / 100;

			if (x2< x && y2 > y)
			{
				for (int j = 0; j < 8; j++)
				{
					if (x1 + j == x2 && y1 - j == y2) {
						return false;
					}
				}
			}
		}
		int x2 = floor(blackQueen->getPositon().x) / 100;
		int y2 = floor(blackQueen->getPositon().y) / 100;
		for (int j = 0; j < 8; j++)
		{
			if (x2< x && y2 > y)
			{
				if (x1 + j == x2 && y1 - j == y2) {
					return false;
				}
			}
		}



		for (int i = 0; i < 8; i++)
		{
			if (x1 + i == x && y1 - i == y) {
				return true;
			}
		}
	}
	if (y1 > y && x1 > x)
	{
		for (size_t i = 0; i < knight.size(); i++)
		{
			int x2 = floor(knight[i]->getPositon().x) / 100;
			int y2 = floor(knight[i]->getPositon().y) / 100;
			if (x2 > x && y2 > y)
			{
				for (int j = 0; j < 8; j++)
				{
					if (x1 - j == x2 && y1 - j == y2) {
						return false;
					}

				}
			}
		}
		for (size_t i = 0; i < white.size(); i++)
		{
			int x2 = floor(white[i]->getPositon().x) / 100;
			int y2 = floor(white[i]->getPositon().y) / 100;

			if (x2 > x && y2 > y)
			{
				for (int j = 0; j < 8; j++)
				{
					if (x1 - j == x2 && y1 - j == y2) {
						return false;
					}

				}
			}

		}
		for (size_t i = 0; i < black.size(); i++)
		{
			int x2 = floor(black[i]->getPositon().x) / 100;
			int y2 = floor(black[i]->getPositon().y) / 100;

			if (x2 > x && y2 > y)
			{
				for (int j = 0; j < 8; j++)
				{
					if (x1 - j == x2 && y1 - j == y2) {
						return false;
					}

				}
			}
		}
		for (size_t i = 0; i < ladies.size(); i++)
		{
			int x2 = floor(ladies[i]->getPositon().x) / 100;
			int y2 = floor(ladies[i]->getPositon().y) / 100;

			if (x2 > x && y2 >y)
			{
				for (int j = 0; j < 8; j++)
				{
					if (x1 - j == x2 && y1 - j == y2) {
						return false;
					}
				}
			}

		}
		for (size_t i = 0; i < bishops.size(); i++)
		{
			int x2 = floor(bishops[i]->getPositon().x) / 100;
			int y2 = floor(bishops[i]->getPositon().y) / 100;

			if (x2 > x && y2 > y)
			{
				for (int j = 0; j < 8; j++)
				{
					if (x1 - j == x2 && y1 - j == y2) {
						return false;
					}
				}
			}
		}
		int x2 = floor(blackQueen->getPositon().x) / 100;
		int y2 = floor(blackQueen->getPositon().y) / 100;
		for (int j = 0; j < 8; j++)
		{
			if (x2 > x && y2 > y)
			{
				if (x1 - j == x2 && y1 - j == y2) {
					return false;
				}
			}
		}



		for (int i = 0; i < 8; i++)
		{
			if (x1 - i == x && y1 - i == y) {
				return true;
			}
		}
	}
	

	return false;
}

