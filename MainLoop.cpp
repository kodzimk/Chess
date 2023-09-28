#include"stdafh.h"
#include"mainLoop.h"

void MainLoop::initPieces()
{
	this->whiteKing = new King(true);
	this->whiteKing->setPosition(sf::Vector2f(4*100,0));
	this->blackKing = new King(false);
	this->blackKing->setPosition(sf::Vector2f(4 * 100, 700));
	this->whiteQueen = new Queen(true);
	this->whiteQueen->setPosition(sf::Vector2f(3 * 100, 0));
	this->blackQueen = new Queen(false);
	this->blackQueen->setPosition(sf::Vector2f(3 * 100, 700));


	int count = 0;
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	int count4 = 0;

	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
		{
			this->bishops.push_back(new Bishop(true));
			this->knights.push_back(new Knight(true));
			this->ladies.push_back(new Lady(true));
		}
		else
		{
			this->ladies.push_back(new Lady(false));
			this->bishops.push_back(new Bishop(false));
			this->knights.push_back(new Knight(false));
		}
	}

	for (int i = 0; i < 8; i++)
	{
		this->whitePawns.push_back(new Pawn(true));
		this->blackPawns.push_back(new Pawn(false));
	}

	

		for (int j = 0; j < 8; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				
				if (board.board[j][k] == 7) {
					this->board.board[j][k] = -1;
					this->whitePawns[count]->pawn.setPosition(k * 100, j * 100);
					count++;
	                
				}
				if (board.board[j][k] == -7)
				{
					this->board.board[j][k] = -1;
					this->blackPawns[count1]->pawn.setPosition(k * 100, j * 100);
					count1++;
				}


				if (board.board[j][k] == 3)
				{
					this->board.board[j][k] = -1;
					this->bishops[count2]->bishop.setPosition(k * 100, j * 100);
					count2++;
				}
				if (board.board[j][k] == -3 && count2 >=2)
				{
					this->board.board[j][k] = -1;
					this->bishops[count2]->bishop.setPosition(k * 100, j * 100);
					count2++;
				}

				if (board.board[j][k] == -2 && count3 >= 2)
				{
					this->board.board[j][k] = -1;
					this->knights[count3]->knight.setPosition(k * 100, j * 100);
					count3++;
				}
				if (board.board[j][k] == 2 && count3 < 2)
				{
					this->board.board[j][k] = -1;
					this->knights[count3]->knight.setPosition(k * 100, j * 100);
					count3++;
				}

				if (board.board[j][k] == -6 && count4 >= 2)
				{
					this->board.board[j][k] = -1;
					this->ladies[count4]->lady.setPosition(k * 100, j * 100);
					count4++;
				}
				if (board.board[j][k] == 6)
				{
					this->board.board[j][k] = -1;
					this->ladies[count4]->lady.setPosition(k * 100, j * 100);
					count4++;
				}
			}
	    }
	
}

void MainLoop::initShapes()
{
	int count = 0;

	for (int j = 0; j < 8; j++)
	{
		for (int k = 0; k < 8; k++)
		{

				this->shapes.push_back(sf::RectangleShape());
				this->shapes[count].setFillColor(sf::Color::Transparent);
				this->shapes[count].setPosition(k * 100, j * 100);
				this->shapes[count].setSize(sf::Vector2f(90, 90));
				count++;
			
		}
	}
}

void MainLoop::initVariables()
{
	this->count = 0;
	this->isClicked = false;
	this->mousePosView = sf::Vector2f();
	this->gridSize = 100;
}

MainLoop::MainLoop()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 800), "Chess");

	this->initVariables();
	this->initPieces();
	this->initShapes();
	
}

MainLoop::~MainLoop()
{
	for (int i = 0; i < this->whitePawns.size(); i++)
	{
		delete this->whitePawns[i];
	}
	for (int i = 0; i < this->blackPawns.size(); i++)
	{
		delete this->blackPawns[i];
	}
	for (int i = 0; i < this->bishops.size(); i++)
	{
		delete this->bishops[i];
	}
	for (int i = 0; i < this->knights.size(); i++)
	{
		delete this->knights[i];
	}
	for (int i = 0; i < this->ladies.size(); i++)
	{
		delete this->ladies[i];
	}

	delete this->window;
	delete this->blackKing;
	delete this->whiteKing;
	delete this->blackQueen;
	delete this->whiteQueen;
	delete this->pawn;
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
		std::cout << this->pawn << std::endl;

		this->mousePosView = sf::Vector2f(sf::Mouse::getPosition(*window));

		this->updateInput();

		this->render();
		
	}
}

void MainLoop::render()
{
	this->window->clear();

	this->board.render(window);

	for (int i = 0; i < 64; i++)
	{
		window->draw(this->shapes[i]);
	}
	for (int i = 0; i < this->whitePawns.size(); i++)
	{
		this->whitePawns.at(i)->render(window);
	}

	for (int i = 0; i < this->blackPawns.size(); i++)
	{
		this->blackPawns.at(i)->render(window);
	}
	for (int i = 0; i < this->bishops.size(); i++)
	{
		this->bishops[i]->render(window);
	}
	for (int i = 0; i < this->knights.size(); i++)
	{
		this->knights[i]->render(window);
	}
	for (int i = 0; i < this->ladies.size(); i++)
	{
		this->ladies[i]->render(window);
	}

	this->blackKing->render(window);
	this->whiteKing->render(window);
	this->whiteQueen->render(window);
	this->blackQueen->render(window);

	this->window->display();
}

void MainLoop::checkForClicked()
{
		for (int i = 0; i < this->shapes.size(); i++)
		{
			if (this->shapes[i].getGlobalBounds().contains(this->mousePosView))
			{
					this->pawn->setPosition(this->shapes[i].getPosition());
					this->pawn = nullptr;
					break;
			}
		}	
}

void MainLoop::updateInput()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		for (int i = 0; i < this->whitePawns.size(); i++)
		{
			if (this->whitePawns[i]->getGlobalBounds(this->mousePosView))
				this->pawn = this->whitePawns[i];
		}

	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		if (this->pawn)
		{
			this->checkForClicked();
		}
	}
}
