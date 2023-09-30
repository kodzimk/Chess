#pragma once
#include"stdafh.h"
#include"Pawn.h"
#include"Bishop.h"
#include"King.h"
#include"Knight.h"
#include"Lady.h"


class Pawn;
class Knight;
class King;

class Queen
{
public:
	sf::Texture texture;
	sf::Sprite queen;
	bool isWhite;

	Queen(const bool white);
	Queen();
	~Queen();

	const sf::Vector2f getPositon();
	void setPosition(sf::Vector2f pos);
	void render(sf::RenderWindow* window);

	const bool getGlobalBounds(sf::Vector2f pos);
	const bool isCanMove(sf::Vector2f pos);
	const bool isOpen(sf::Vector2f pos, std::vector<Knight*> knight, std::vector<Pawn*> white, std::vector<Pawn*> black, std::vector<Lady*> ladies, std::vector<Bishop*> bishops, Queen* blackQueen);
};

