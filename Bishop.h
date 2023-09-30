#pragma once

#include"stdafh.h"
#include"Pawn.h"
#include"Queen.h"
#include"King.h"
#include"Knight.h"
#include"Lady.h"

class Lady;
class Knight;
class Queen;
class Pawn;
class King;

class Bishop
{
public:
	sf::Texture texture;
	sf::Sprite bishop;
	bool isWhite;

	Bishop(const bool white);
	Bishop();
	~Bishop();

	const sf::Vector2f getPositon();
	void setPosition(sf::Vector2f pos);
	void render(sf::RenderWindow* window);

	const bool getGlobalBounds(sf::Vector2f pos);

	const bool isCanMove(sf::Vector2f pos);
	const std::vector<Cor*> getNextMove();
	const bool ISOpen(sf::Vector2f pos, std::vector<Knight*> knight, std::vector<Pawn*> white, std::vector<Pawn*> black, std::vector<Lady*> ladies, std::vector<Bishop*> bishops, Queen* blackQueen);
};

