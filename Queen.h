#pragma once
#include"stdafh.h"
class Queen
{
public:
	sf::Texture texture;
	sf::Sprite queen;

	Queen(const bool white);
	Queen();
	~Queen();

	const sf::Vector2f getPositon();
	void setPosition(sf::Vector2f pos);
	void render(sf::RenderWindow* window);

	const bool getGlobalBounds(sf::Vector2f pos);
};

