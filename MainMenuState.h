#pragma once
#include"stdafh.h"

class MainMenuState
{
public:
	
	//Variables
	sf::Texture backTexture;
	sf::Sprite background;


	//Initializer functions
	void initBackGround();

	MainMenuState();
	~MainMenuState();

	//Functions
	void update();
	void render(sf::RenderWindow* window);

};

