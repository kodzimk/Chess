#pragma once
#include"stdafh.h"

class MainMenuState
{
public:
	
	//Variables
	sf::Texture backTexture;
	sf::Sprite background;
	sf::RenderWindow* window;
	sf::Font font;
	sf::Text playText;
	sf::Text quitText;
	bool isPressed;
	sf::Vector2f mousePosView;
	sf::SoundBuffer sound;
	sf::Sound buffer;

	//Initializer functions
	void initBackGround();
	void initGui();
	

	MainMenuState();
	~MainMenuState();

	//Functions
	bool updateText();
	void update();
	void render();

};

