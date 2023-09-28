#include"stdafh.h"
#include"mainLoop.h"

MainLoop::MainLoop()
{
	window = new sf::RenderWindow(sf::VideoMode(800, 800), "Chess");
}

MainLoop::~MainLoop()
{
	delete this->window;
}

void MainLoop::updateGame()
{
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}
		window->clear();
		render();
		window->display();
	}
}

void MainLoop::render()
{
	board.render(window);
}
