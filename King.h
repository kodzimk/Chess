#pragma once
#include"stdafh.h"

class King
{
public:
	sf::Texture texture;
	sf::Sprite king;

	King(const bool white);
	King();
	~King();

	const sf::Vector2f getPositon();
	void setPosition(sf::Vector2f pos);
	void render(sf::RenderWindow* window);

	const bool getGlobalBounds(sf::Vector2f pos);
};

