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
	int x =  floor(pos.x) / 100;
	int y =  floor(pos.y) / 100;
	int x1 = floor(this->bishop.getPosition().x) / 100;
	int y1 = floor(this->bishop.getPosition().y) / 100;

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

const std::vector<Cor*> Bishop::getNextMove()
{
	std::vector<Cor*> coordinates;
	int x1 = floor(this->bishop.getPosition().x) / 100;
	int y1 = floor(this->bishop.getPosition().y) / 100;

	for (int i = 1; i < 8; i++)
	{
		if (x1 + i <8 && y1 + i <8) {
			coordinates.push_back(new Cor(y1 + i, x1 + i));
		}
		if (x1 - i >=0  && y1 - i >=0) {
			coordinates.push_back(new Cor(y1 - i, x1 - i));
		}
	}

	for (int i = 1; i < 8; i++)
	{
		if (x1  + i<8 && y1 - i >=0) {
			coordinates.push_back(new Cor(y1 - i, x1+ i));
		}
		if (x1 - i >= 0 && y1 + i < 8) {
			coordinates.push_back(new Cor(y1 + i, x1 - i));
		}
	}

	return coordinates;
}

const bool Bishop::ISOpen(sf::Vector2f pos, std::vector<Knight*> knight, std::vector<Pawn*> white, std::vector<Pawn*> black, std::vector<Lady*> ladies, std::vector<Bishop*> bishops, Queen* blackQueen)
{
	int x = floor(pos.x) / 100;
	int y = floor(pos.y) / 100;
	int x1 = floor(this->bishop.getPosition().x) / 100;
	int y1 = floor(this->bishop.getPosition().y) / 100;

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


				for (int j = 0; j < 8; j++)
				{
					if (x1 + j == x2 && y1 + j == y2) {
						return false;
					}
				}
			
		}
		for (size_t i = 0; i < bishops.size(); i++)
		{
			int x2 = floor(bishops[i]->getPositon().x) / 100;
			int y2 = floor(bishops[i]->getPositon().y) / 100;

			if (x2 < x&&y2<y&&this != bishops[i])
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

			if (x2 > x && y > y2)
			{
				for (int j = 0; j < 8; j++)
				{

					if (x1 - j == x2 && y1 + j == y2) {
						return false;
					}

				}
			}
		}
		for (size_t i = 0; i < white.size(); i++)
		{
			int x2 = floor(white[i]->getPositon().x) / 100;
			int y2 = floor(white[i]->getPositon().y) / 100;


			if (x2 > x && y > y2)
			{
				for (int j = 0; j < 8; j++)
				{

					if (x1 - j == x2 && y1 + j == y2) {
						return false;
					}

				}
			}

		}
		for (size_t i = 0; i < black.size(); i++)
		{
			int x2 = floor(black[i]->getPositon().x) / 100;
			int y2 = floor(black[i]->getPositon().y) / 100;


			if (x2 > x && y > y2)
			{
				for (int j = 0; j < 8; j++)
				{

					if (x1 - j == x2 && y1 + j == y2) {
						return false;
					}

				}
			}
		}
		for (size_t i = 0; i < ladies.size(); i++)
		{
			int x2 = floor(ladies[i]->getPositon().x) / 100;
			int y2 = floor(ladies[i]->getPositon().y) / 100;


			if (x2 > x && y > y2)
			{
				for (int j = 0; j < 8; j++)
				{
					if (x1 - j == x2 && y1 + j == y2) {
						return false;
					}

				}
			}

		}
		for (size_t i = 0; i < bishops.size(); i++)
		{
			int x2 = floor(bishops[i]->getPositon().x) / 100;
			int y2 = floor(bishops[i]->getPositon().y) / 100;


			if (x2 > x && y > y2&&this != bishops[i])
			{
				for (int j = 0; j < 8; j++)
				{

					if (x1 - j == x2 && y1 + j == y2) {
						return false;
					}


				}
			}
		}
		int x2 = floor(blackQueen->getPositon().x) / 100;
		int y2 = floor(blackQueen->getPositon().y) / 100;
		for (int j = 0; j < 8; j++)
		{

			if (x2 > x && y > y2)
			{
				if (x1 - j == x2 && y1 + j == y2) {
					return false;
				}
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

			if (x2< x && y2 > y&&this != bishops[i])
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
		for (size_t i = 0; i < bishops.size(); i++)
		{
			int x2 = floor(bishops[i]->getPositon().x) / 100;
			int y2 = floor(bishops[i]->getPositon().y) / 100;

			if (x2 > x && y2 > y&&this != bishops[i])
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
	
}
