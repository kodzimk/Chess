#pragma once
#include"stdafh.h"


class Knight
{
public:
	sf::Texture texture;
	sf::Sprite knight;
	bool isWhite;

	Knight(const bool white);
	Knight();
	~Knight();

	const sf::Vector2f getPositon();
	void setPosition(sf::Vector2f pos);
	void render(sf::RenderWindow* window);

	const bool isCanMove(sf::Vector2f pos);
	const bool getGlobalBounds(sf::Vector2f pos);
	  std::vector<Cor*> getNextCanMove();
};

