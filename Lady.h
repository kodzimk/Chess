#pragma once
#include"stdafh.h"
#include"Pawn.h"
#include"Bishop.h"
#include"King.h"
#include"Queen.h"
#include"Knight.h"

class Knight;
class King;
class Pawn;
class Bishop;
class Queen;


class Lady
{
public:
	sf::Texture texture;
	sf::Sprite lady;
	bool isWhite;

	Lady(const bool white);
	Lady();
	~Lady();

	const sf::Vector2f getPositon();
	void setPosition(sf::Vector2f pos);
	void render(sf::RenderWindow* window);
	const bool isCanMove(sf::Vector2f pos);

	const std::vector<Cor*> getNextMove();
	const bool getGlobalBounds(sf::Vector2f pos);
	const bool IsOpen(sf::Vector2f pos, std::vector<Knight*> knight, std::vector<Pawn*> white, std::vector<Pawn*> black, std::vector<Lady*> ladies, std::vector<Bishop*> bishops, Queen* blackQueen);
};

