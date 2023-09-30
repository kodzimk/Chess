#pragma once
#include"stdafh.h"
#include"Queen.h"
#include"Bishop.h"
#include"King.h"
#include"Knight.h"
#include"Lady.h"

class Lady;
class Queen;
class Bishop;
class King;
class Bishop;

class Pawn
{
public:
	sf::Texture texture;
	sf::Sprite pawn;
	bool isWhite;

	Pawn(const bool white);
	Pawn();
	~Pawn();

	const sf::Vector2f getPositon();
	void setPosition(sf::Vector2f pos);
	void render(sf::RenderWindow* window);
	const bool IsCanMove(sf::Vector2f pos);

	const bool getGlobalBounds(sf::Vector2f pos );
	const std::vector<Cor*> getNextMove();
	const bool isOpen(sf::Vector2f pos, std::vector<Knight*> knight, std::vector<Pawn*> white, std::vector<Pawn*> black, std::vector<Lady*> ladies, std::vector<Bishop*> bishops, Queen* blackQueen);
};

