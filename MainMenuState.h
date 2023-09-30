#pragma once
#include"stdafh.h"

class MainMenuState
{
public:
	
	//Variables
	sf::Texture backTexture;
	sf::Sprite background;
	sf::RenderWindow* window;

	//Initializer functions
	void initBackGround();

	MainMenuState();
	~MainMenuState();

	//Functions
	void update();
	void render();

};

