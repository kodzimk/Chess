#pragma once
#include"stdafh.h"

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

	const bool getGlobalBounds(sf::Vector2f pos);
};

