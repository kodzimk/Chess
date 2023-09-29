#pragma once
#include"stdafh.h"

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
};

