#include"stdafh.h"
#include"mainLoop.h"

void GameState::initPieces()
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

void GameState::initShapes()
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

void GameState::initVariables()
{
	this->count = 0;
	this->isClicked = false;
	this->mousePosView = sf::Vector2f();
	this->gridSize = 100;
	this->isWhite = false;
	this->isInChah = false;
}

GameState::GameState()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 800), "Chess");

	this->initVariables();
	this->initPieces();
	this->initShapes();
	
}

GameState::~GameState()
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

	if(this->pawn)
	delete this->pawn;
	if (this->lady)
		delete this->lady;
	if (this->knight)
		delete this->knight;
	if (this->bishop)
		delete this->bishop;
	if (this->queen)
		delete this->queen;
	if (this->king)
		delete this->king;
	if (this->blackking)
		delete this->blackking;
}

void GameState::updateGame()
{
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
		
			if (event.type == sf::Event::Closed)
				window->close();
		}

		this->mousePosView = sf::Vector2f(sf::Mouse::getPosition(*window));
		
		this->updateInput();

		this->render();
		
	}
}

void GameState::render()
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

void GameState::checkForClicked()
{
	if (!this->isInChah)
	{
		if (this->pawn && this->pawn->IsCanMove(this->mousePosView))
		{
			for (int i = 0; i < this->shapes.size(); i++)
			{
				if (this->shapes[i].getGlobalBounds().contains(this->mousePosView))
				{
					this->pawn->setPosition(this->shapes[i].getPosition());
					this->pawn = nullptr;
					this->isClicked = false;
					this->isKingInChah();

					break;
				}

			}
		}
		else if (this->lady && this->lady->IsOpen(this->mousePosView, this->knights, this->whitePawns, this->blackPawns, this->ladies, this->bishops, this->blackQueen) && this->lady->isCanMove(this->mousePosView))
		{
			for (int i = 0; i < this->shapes.size(); i++)
			{

				if (this->shapes[i].getGlobalBounds().contains(this->mousePosView))
				{
					this->lady->setPosition(this->shapes[i].getPosition());
					this->lady = nullptr;
					this->isClicked = false;
						this->isKingInChah();
					break;
				}

			}
		}
		else if (this->knight && this->knight->isCanMove(this->mousePosView))
		{
			for (int i = 0; i < this->shapes.size(); i++)
			{

				if (this->shapes[i].getGlobalBounds().contains(this->mousePosView))
				{
					this->knight->setPosition(this->shapes[i].getPosition());
					this->knight = nullptr;
					this->isClicked = false;
					this->isKingInChah();
					break;
				}

			}
		}
		else if (this->bishop && this->bishop->ISOpen(this->mousePosView, this->knights, this->whitePawns, this->blackPawns, this->ladies, this->bishops, this->whiteQueen)
			&& this->bishop->isCanMove(this->mousePosView))
		{
			for (int i = 0; i < this->shapes.size(); i++)
			{

				if (this->shapes[i].getGlobalBounds().contains(this->mousePosView))
				{
					this->bishop->setPosition(this->shapes[i].getPosition());
					this->bishop = nullptr;
					this->isClicked = false;
					this->isKingInChah();
					break;
				}

			}
		}
		else if (this->queen && this->queen->isOpen(this->mousePosView, this->knights, this->whitePawns, this->blackPawns, this->ladies, this->bishops, this->blackQueen) 
			&& this->queen->isCanMove(this->mousePosView))
		{
			for (int i = 0; i < this->shapes.size(); i++)
			{

				if (this->shapes[i].getGlobalBounds().contains(this->mousePosView))
				{
					this->queen->setPosition(this->shapes[i].getPosition());
					this->queen = nullptr;
					this->isClicked = false;
					this->isKingInChah();
					break;
				}

			}
		}
		else if (this->king && this->king->IsCanMove(this->mousePosView))
		{
			int x = floor(this->mousePosView.x) / 100;
			int y = floor(this->mousePosView.y) / 100;

			for (int i = 0; i < this->shapes.size(); i++)
			{
				if (this->shapes[i].getGlobalBounds().contains(this->mousePosView))
				{
					for (size_t i = 0; i < this->knights.size(); i++)
					{
						for (size_t j = 0; j < this->knights[i]->getNextCanMove().size(); j++)
						{
							if (this->knights[i]->isWhite != true && this->knights[i]->getNextCanMove().at(j)->x == x && this->knights[i]->getNextCanMove().at(j)->y == y)
							{
								return;
							}
						}
					}
					for (int i = 0; i < this->blackPawns.size(); i++)
					{
						for (size_t j = 0; j < this->blackPawns[i]->getNextMove().size(); j++)
						{
							if (this->blackPawns[i]->getNextMove().at(j)->x == x && this->blackPawns[i]->getNextMove().at(j)->y == y)
							{
								return;
							}
						}
					}
					for (int i = 0; i < this->ladies.size(); i++)
					{
						for (size_t j = 0; j < this->ladies[i]->getNextMove().size(); j++)
						{
							if (this->ladies[i]->isWhite != true && this->ladies[i]->getNextMove().at(j)->x == x && this->ladies[i]->getNextMove().at(j)->y == y)
							{
								return;
							}
						}
					}
					this->king->setPosition(this->shapes[i].getPosition());
					this->king = nullptr;
					this->isClicked = false;
				}
			}
		}
		else if (this->blackking && this->blackking->IsCanMove(this->mousePosView))
		{
			int x = floor(this->mousePosView.x) / 100;
			int y = floor(this->mousePosView.y) / 100;
			for (int i = 0; i < this->shapes.size(); i++)
			{
				if (this->shapes[i].getGlobalBounds().contains(this->mousePosView))
				{
					for (size_t i = 0; i < this->knights.size(); i++)
					{
						for (size_t j = 0; j < this->knights[i]->getNextCanMove().size(); j++)
						{
							std::cout << "KKKKK: " << this->knights[i]->getNextCanMove().at(j)->x << "  " << this->knights[i]->getNextCanMove().at(j)->y << "\n";
							if (this->knights[i]->isWhite == true && this->knights[i]->getNextCanMove().at(j)->x == x && this->knights[i]->getNextCanMove().at(j)->y == y)
							{
								
								return;
							}
						}
					}
					for (int i = 0; i < this->whitePawns.size(); i++)
					{
						for (size_t j = 0; j < this->whitePawns[i]->getNextMove().size(); j++)
						{
							if (this->whitePawns[i]->getNextMove().at(j)->x == x && this->whitePawns[i]->getNextMove().at(j)->y == y)
							{
								return;
							}
						}
					}
					for (int i = 0; i < this->ladies.size(); i++)
					{
						for (size_t j = 0; j < this->ladies[i]->getNextMove().size(); j++)
						{
							if (this->ladies[i]->isWhite == true && this->ladies[i]->getNextMove().at(j)->x == x && this->ladies[i]->getNextMove().at(j)->y == y)
							{
								return;
							}
						}
					}

					this->blackking->setPosition(this->shapes[i].getPosition());
					this->blackking = nullptr;
					this->isClicked = false;
				}
			}
		}
	}
	else
	{
		if(this->isWhite)
	      if (this->king && this->king->IsCanMove(this->mousePosView))
		{
			int x = floor(this->mousePosView.x) / 100;
			int y = floor(this->mousePosView.y) / 100;
			std::cout << "X: " << x << " " << "Y: " << y << "\n";
			for (int i = 0; i < this->shapes.size(); i++)
			{
				if (this->shapes[i].getGlobalBounds().contains(this->mousePosView))
				{
					for (size_t i = 0; i < this->knights.size(); i++)
					{
						for (size_t j = 0; j < this->knights[i]->getNextCanMove().size(); j++)
						{
							if (this->knights[i]->isWhite != true && this->knights[i]->getNextCanMove().at(j)->x == x && this->knights[i]->getNextCanMove().at(j)->y == y)
							{
								return;
							}
						}
					}
					for (int i = 0; i < this->blackPawns.size(); i++)
					{
						for (size_t j = 0; j < this->blackPawns[i]->getNextMove().size(); j++)
						{
							if (this->blackPawns[i]->getNextMove().at(j)->x == x && this->blackPawns[i]->getNextMove().at(j)->y == y)
							{
								return;
							}
						}
					}
					for (int i = 0; i < this->ladies.size(); i++)
					{
						for (size_t j = 0; j < this->ladies[i]->getNextMove().size(); j++)
						{
							if (this->ladies[i]->isWhite != true && this->ladies[i]->getNextMove().at(j)->x == x && this->ladies[i]->getNextMove().at(j)->y == y)
							{
								return;
							}
						}
					}
					this->king->setPosition(this->shapes[i].getPosition());
					this->king = nullptr;
					this->isClicked = false;
				}
			}
		}
		else
		 if (this->blackking && this->blackking->IsCanMove(this->mousePosView))
		{
			int x = floor(this->mousePosView.x) / 100;
			int y = floor(this->mousePosView.y) / 100;
			std::cout << "X: " << x << " " << "Y: " << y << "\n";
			for (int i = 0; i < this->shapes.size(); i++)
			{
				if (this->shapes[i].getGlobalBounds().contains(this->mousePosView))
				{
					for (size_t i = 0; i < this->knights.size(); i++)
					{
						for (size_t j = 0; j < this->knights[i]->getNextCanMove().size(); j++)
						{
							if (this->knights[i]->isWhite == true && this->knights[i]->getNextCanMove().at(j)->x == x && this->knights[i]->getNextCanMove().at(j)->y == y)
							{
								return;
							}
						}
					}
					for (int i = 0; i < this->whitePawns.size(); i++)
					{
						for (size_t j = 0; j < this->whitePawns[i]->getNextMove().size(); j++)
						{
							if (this->whitePawns[i]->getNextMove().at(j)->x == x && this->whitePawns[i]->getNextMove().at(j)->y == y)
							{
								return;
							}
						}
					}
					for (int i = 0; i < this->ladies.size(); i++)
					{
						for (size_t j = 0; j < this->ladies[i]->getNextMove().size(); j++)
						{
							if (this->ladies[i]->isWhite == true && this->ladies[i]->getNextMove().at(j)->x == x && this->ladies[i]->getNextMove().at(j)->y == y)
							{
								return;
							}
						}
					}

					this->blackking->setPosition(this->shapes[i].getPosition());
					this->blackking = nullptr;
					this->isClicked = false;
				}
			}
		}
	}

	this->pawn = nullptr;
	this->knight = nullptr;
	this->bishop = nullptr;
	this->king = nullptr;
	this->blackking = nullptr;
	this->queen = nullptr;
	this->lady = nullptr;
}

void GameState::checkForEating()
{
		for (int i = 0; i < this->blackPawns.size(); i++)
		{
			if (this->blackPawns[i]->getGlobalBounds(this->mousePosView) &&
				((this->pawn && this->pawn->isWhite == true) || (this->lady && this->lady->isWhite == true) ||
					(this->bishop && this->bishop->isWhite == true) || (this->knight && this->knight->isWhite == true) || (this->queen && this->queen->isWhite == true)||(this->king )))
			{
		

				if (this->bishop && this->bishop->isCanMove(this->blackPawns[i]->getPositon()))
				{
				
					bishop->setPosition(this->blackPawns[i]->getPositon());
					this->blackPawns[i]->pawn.setScale(sf::Vector2f(0, 0));
					this->isKingInChah();
				}
				else if (this->king && this->king->IsCanMove(this->blackPawns[i]->getPositon()))
				{
					king->setPosition(this->blackPawns[i]->getPositon());
					this->blackPawns[i]->pawn.setScale(sf::Vector2f(0, 0));
					this->isInChah = false;
				}
				else if (this->pawn && this->pawn->IsCanMove(this->blackPawns[i]->getPositon()))
				{
					
					this->pawn->setPosition(this->blackPawns[i]->getPositon());
					this->blackPawns[i]->pawn.setScale(sf::Vector2f(0, 0));
					this->isKingInChah();
				}
				else if (this->knight && this->knight->isCanMove(this->blackPawns[i]->getPositon()))
				{
					
					this->knight->setPosition(this->blackPawns[i]->getPositon());
					this->blackPawns[i]->pawn.setScale(sf::Vector2f(0, 0));
					this->isKingInChah();
				}
				else if (this->lady && this->lady->isCanMove(this->blackPawns[i]->getPositon()))
				{
					
					this->lady->setPosition(this->blackPawns[i]->getPositon());
					this->blackPawns[i]->pawn.setScale(sf::Vector2f(0, 0));
					this->isKingInChah();
				}
				else if (this->queen && this->queen->isCanMove(this->blackPawns[i]->getPositon()))
				{
					
					this->queen->setPosition(this->blackPawns[i]->getPositon());
					this->blackPawns[i]->pawn.setScale(sf::Vector2f(0, 0));
					this->isKingInChah();
				}


				this->pawn = nullptr;
				this->lady = nullptr;
				this->bishop = nullptr;
				this->queen = nullptr;
				this->knight = nullptr;
			}

		}
		for (int i = 0; i < this->whitePawns.size(); i++)
		{
			if (this->whitePawns[i]->getGlobalBounds(this->mousePosView) &&
				((this->pawn && this->pawn->isWhite != true) || (this->lady && this->lady->isWhite != true) ||
					(this->bishop && this->bishop->isWhite != true) || (this->knight && this->knight->isWhite != true) || (this->queen && this->queen->isWhite != true)||(this->blackking)))
			{
				std::cout << "EATEN" << "\n";
				if (this->bishop && this->bishop->isCanMove(this->whitePawns[i]->getPositon()))
				{
				
					bishop->setPosition(this->whitePawns[i]->getPositon());
					this->whitePawns[i]->pawn.setScale(sf::Vector2f(0, 0));
					this->isKingInChah();
				}
				else if (this->blackking && this->blackking->IsCanMove(this->whitePawns[i]->getPositon()))
				{
					this->isInChah = false;
					this->blackking->setPosition(this->whitePawns[i]->getPositon());
					this->whitePawns[i]->pawn.setScale(sf::Vector2f(0, 0));
				}
				else if (this->pawn && this->pawn->IsCanMove(this->whitePawns[i]->getPositon()))
				{
				
					this->pawn->setPosition(this->whitePawns[i]->getPositon());
					this->whitePawns[i]->pawn.setScale(sf::Vector2f(0, 0));
					this->isKingInChah();
				}
				else if (this->knight && this->knight->isCanMove(this->whitePawns[i]->getPositon()))
				{
				
					this->knight->setPosition(this->whitePawns[i]->getPositon());
					this->whitePawns[i]->pawn.setScale(sf::Vector2f(0, 0));
					this->isKingInChah();
				}
				else if (this->lady && this->lady->isCanMove(this->whitePawns[i]->getPositon()))
				{
					
					this->lady->setPosition(this->whitePawns[i]->getPositon());
					this->whitePawns[i]->pawn.setScale(sf::Vector2f(0, 0));
					this->isKingInChah();
				}
				else if (this->queen && this->queen->isCanMove(this->whitePawns[i]->getPositon()))
				{
					
					this->queen->setPosition(this->whitePawns[i]->getPositon());
					this->whitePawns[i]->pawn.setScale(sf::Vector2f(0, 0));
					this->isKingInChah();
				}


				this->pawn = nullptr;
				this->lady = nullptr;
				this->bishop = nullptr;
				this->queen = nullptr;
				this->knight = nullptr;

			}

		}
		/*for (int i = 0; i < this->ladies.size(); i++)
		{
			if (this->lady->IsOpen(this->mousePosView, this->knights, this->whitePawns, this->blackPawns, this->ladies, this->bishops, this->blackQueen) && 
				this->ladies[i]->getGlobalBounds(this->mousePosView) && 
				((this->pawn && this->pawn->isWhite != true) || (this->lady->isWhite != true) ||
					(this->bishop && this->bishop->isWhite != true) || (this->knight && this->knight->isWhite != true) || (this->queen && this->queen->isWhite != true)||(this->blackking)))
			{
				std::cout << "EATEN" << "\n";
				if (this->bishop && this->bishop->isCanMove(this->ladies[i]->getPositon()))
				{
					bishop->setPosition(this->ladies[i]->getPositon());
					this->ladies[i]->lady.setScale(sf::Vector2f(0, 0));
				}
				else if (this->pawn && this->pawn->IsCanMove(this->ladies[i]->getPositon()))
				{
					this->pawn->setPosition(this->ladies[i]->getPositon());
					this->ladies[i]->lady.setScale(sf::Vector2f(0, 0));
				}
				else if (this->blackking && this->blackking->IsCanMove(this->ladies[i]->getPositon()))
				{
					this->isInChah = false;
					this->blackking->setPosition(this->ladies[i]->getPositon());
					this->ladies[i]->lady.setScale(sf::Vector2f(0, 0));
				}
				else if (this->knight && this->knight->isCanMove(this->ladies[i]->getPositon()))
				{
					this->knight->setPosition(this->ladies[i]->getPositon());
					this->ladies[i]->lady.setScale(sf::Vector2f(0, 0));
				}
				else if (this->lady && this->lady->isCanMove(this->ladies[i]->getPositon()))
				{
					this->lady->setPosition(this->ladies[i]->getPositon());
					this->ladies[i]->lady.setScale(sf::Vector2f(0, 0));
				}
				else if (this->queen && this->queen->isCanMove(this->ladies[i]->getPositon()))
				{
					this->queen->setPosition(this->ladies[i]->getPositon());
					this->ladies[i]->lady.setScale(sf::Vector2f(0, 0));
				}


				this->pawn = nullptr;
				this->lady = nullptr;
				this->bishop = nullptr;
				this->queen = nullptr;
				this->knight = nullptr;

			}

			else if (this->lady->IsOpen(this->mousePosView, this->knights, this->whitePawns, this->blackPawns, this->ladies, this->bishops, this->blackQueen) && this->ladies[i]->getGlobalBounds(this->mousePosView) &&
				((this->pawn && this->pawn->isWhite == true) || (this->lady && this->lady->isWhite == true) ||
					(this->bishop && this->bishop->isWhite == true) || (this->knight && this->knight->isWhite == true) || (this->queen && this->queen->isWhite == true)||(this->king)))
			{
				std::cout << "EATEN" << "\n";

				if (this->bishop && this->bishop->isCanMove(this->ladies[i]->getPositon()))
				{
					bishop->setPosition(this->ladies[i]->getPositon());
					this->ladies[i]->lady.setScale(sf::Vector2f(0, 0));
				}
				else if (this->king && this->king->IsCanMove(this->ladies[i]->getPositon()))
				{
					this->isInChah = false;
					this->king->setPosition(this->ladies[i]->getPositon());
					this->ladies[i]->lady.setScale(sf::Vector2f(0, 0));
				}
				else if (this->pawn && this->pawn->IsCanMove(this->ladies[i]->getPositon()))
				{
					this->pawn->setPosition(this->ladies[i]->getPositon());
					this->ladies[i]->lady.setScale(sf::Vector2f(0, 0));
				}
				else if (this->knight && this->knight->isCanMove(this->ladies[i]->getPositon()))
				{
					this->knight->setPosition(this->ladies[i]->getPositon());
					this->ladies[i]->lady.setScale(sf::Vector2f(0, 0));
				}
				else if (this->lady && this->lady->isCanMove(this->ladies[i]->getPositon()))
				{
					this->lady->setPosition(this->ladies[i]->getPositon());
					this->ladies[i]->lady.setScale(sf::Vector2f(0, 0));
				}
				else if (this->queen && this->queen->isCanMove(this->ladies[i]->getPositon()))
				{
					this->queen->setPosition(this->ladies[i]->getPositon());
					this->ladies[i]->lady.setScale(sf::Vector2f(0, 0));
				}


				this->pawn = nullptr;
				this->lady = nullptr;
				this->bishop = nullptr;
				this->queen = nullptr;
				this->knight = nullptr;
			}
		}*/
		for (int i = 0; i < this->knights.size(); i++)
		{
			if (this->knights[i]->getGlobalBounds(this->mousePosView) &&
				((this->pawn && this->pawn->isWhite != true) || (this->lady && this->lady->isWhite != true) ||
					(this->bishop && this->bishop->isWhite != true) || (this->knight && this->knight->isWhite != true) || (this->queen && this->queen->isWhite != true)||(this->blackking)))
			{
				std::cout << "EATEN" << "\n";
				if (this->bishop && this->bishop->isCanMove(this->knights[i]->getPositon()))
				{
					
					bishop->setPosition(this->knights[i]->getPositon());
					this->knights[i]->knight.setScale(sf::Vector2f(0, 0));
					this->isKingInChah();
				}
				else if (this->pawn && this->pawn->IsCanMove(this->knights[i]->getPositon()))
				{
				
					this->pawn->setPosition(this->knights[i]->getPositon());
					this->knights[i]->knight.setScale(sf::Vector2f(0, 0));
					this->isKingInChah();
				}
				else if (this->blackking && this->blackking->IsCanMove(this->knights[i]->getPositon()))
				{
					this->isInChah = false;
					this->blackking->setPosition(this->knights[i]->getPositon());
					this->knights[i]->knight.setScale(sf::Vector2f(0, 0));
				}
				else if (this->knight && this->knight->isCanMove(this->knights[i]->getPositon()))
				{
					this->knight->setPosition(this->knights[i]->getPositon());
					this->knights[i]->knight.setScale(sf::Vector2f(0, 0));
					this->isKingInChah();
				}
				else if (this->lady && this->lady->isCanMove(this->knights[i]->getPositon()))
				{
					
					this->lady->setPosition(this->knights[i]->getPositon());
					this->knights[i]->knight.setScale(sf::Vector2f(0, 0));
					this->isKingInChah();
				}
				else if (this->queen && this->queen->isCanMove(this->knights[i]->getPositon()))
				{
				
					this->queen->setPosition(this->knights[i]->getPositon());
					this->knights[i]->knight.setScale(sf::Vector2f(0, 0));
					this->isKingInChah();
				}


				this->pawn = nullptr;
				this->lady = nullptr;
				this->bishop = nullptr;
				this->queen = nullptr;
				this->knight = nullptr;

			}

			else if (this->knights[i]->getGlobalBounds(this->mousePosView) &&
				((this->pawn && this->pawn->isWhite == true) || (this->lady && this->lady->isWhite == true) ||
					(this->bishop && this->bishop->isWhite == true) || (this->knight && this->knight->isWhite == true) || (this->queen && this->queen->isWhite == true)||(this->king)))
			{
				std::cout << "EATEN" << "\n";

				if (this->bishop && this->bishop->isCanMove(this->knights[i]->getPositon()))
				{
					
					bishop->setPosition(this->knights[i]->getPositon());
					this->knights[i]->knight.setScale(sf::Vector2f(0, 0));
					this->isKingInChah();
				}
				else if (this->king && this->king->IsCanMove(this->knights[i]->getPositon()))
				{
					this->isInChah = false;
					this->king->setPosition(this->knights[i]->getPositon());
					this->knights[i]->knight.setScale(sf::Vector2f(0, 0));
				}
				else if (this->pawn && this->pawn->IsCanMove(this->knights[i]->getPositon()))
				{
					
					this->pawn->setPosition(this->knights[i]->getPositon());
					this->knights[i]->knight.setScale(sf::Vector2f(0, 0));
					this->isKingInChah();
				}
				else if (this->knight && this->knight->isCanMove(this->knights[i]->getPositon()))
				{
				
					this->knight->setPosition(this->knights[i]->getPositon());
					this->knights[i]->knight.setScale(sf::Vector2f(0, 0));
					this->isKingInChah();
				}
				else if (this->lady && this->lady->isCanMove(this->knights[i]->getPositon()))
				{
					this->lady->setPosition(this->knights[i]->getPositon());
					this->knights[i]->knight.setScale(sf::Vector2f(0, 0));
					this->isKingInChah();
				}
				else if (this->queen && this->queen->isCanMove(this->knights[i]->getPositon()))
				{
					
					this->queen->setPosition(this->knights[i]->getPositon());
					this->knights[i]->knight.setScale(sf::Vector2f(0, 0));
					this->isKingInChah();
				}



				this->pawn = nullptr;
				this->lady = nullptr;
				this->bishop = nullptr;
				this->queen = nullptr;
				this->knight = nullptr;
			}
		}
		for (int i = 0; i < this->bishops.size(); i++)
		{
			if (this->bishop && this->bishop->ISOpen(this->mousePosView, this->knights, this->whitePawns, this->blackPawns, this->ladies, this->bishops, this->whiteQueen) && this->bishops[i]->getGlobalBounds(this->mousePosView) &&
				((this->pawn && this->pawn->isWhite != true) || (this->lady && this->lady->isWhite != true) ||
					(this->bishop && this->bishop->isWhite != true) || (this->knight && this->knight->isWhite != true) || (this->queen && this->queen->isWhite != true)||(this->blackking)))
			{
				std::cout << "EATEN" << "\n";
				if (this->bishop && this->bishop->isCanMove(this->bishops[i]->getPositon()))
				{
					bishop->setPosition(this->bishops[i]->getPositon());
					this->bishops[i]->bishop.setScale(sf::Vector2f(0, 0));
				}
				else if (this->blackking && this->blackking->IsCanMove(this->bishops[i]->getPositon()))
				{
					
					this->blackking->setPosition(this->bishops[i]->getPositon());
					this->bishops[i]->bishop.setScale(sf::Vector2f(0, 0));
					this->isInChah = false;
				}
				else if (this->pawn && this->pawn->IsCanMove(this->bishops[i]->getPositon()))
				{
					
					this->pawn->setPosition(this->bishops[i]->getPositon());
					this->bishops[i]->bishop.setScale(sf::Vector2f(0, 0));
					this->isKingInChah();
				}
				else if (this->knight && this->knight->isCanMove(this->bishops[i]->getPositon()))
				{
					
					this->knight->setPosition(this->bishops[i]->getPositon());
					this->bishops[i]->bishop.setScale(sf::Vector2f(0, 0));
					this->isKingInChah();
				}
				else if (this->lady && this->lady->isCanMove(this->bishops[i]->getPositon()))
				{
				
					this->lady->setPosition(this->bishops[i]->getPositon());
					this->bishops[i]->bishop.setScale(sf::Vector2f(0, 0));
					this->isKingInChah();
				}
				else if (this->queen && this->queen->isCanMove(this->bishops[i]->getPositon()))
				{
					
					this->queen->setPosition(this->bishops[i]->getPositon());
					this->bishops[i]->bishop.setScale(sf::Vector2f(0, 0));
					this->isKingInChah();
				}
				


				this->pawn = nullptr;
				this->lady = nullptr;
				this->bishop = nullptr;
				this->queen = nullptr;
				this->knight = nullptr;

			}

			else if (this->bishop && this->bishop->ISOpen(this->mousePosView, this->knights, this->whitePawns, this->blackPawns, this->ladies, this->bishops, this->whiteQueen) && this->bishops[i]->getGlobalBounds(this->mousePosView) &&
				((this->pawn && this->pawn->isWhite == true) || (this->lady && this->lady->isWhite == true) ||
					(this->bishop && this->bishop->isWhite == true) || (this->knight && this->knight->isWhite == true) || (this->queen && this->queen->isWhite == true)||(this->king)))
			{
				std::cout << "EATEN" << "\n";
				if (this->bishop && this->bishop->isCanMove(this->bishops[i]->getPositon()))
				{
				
					bishop->setPosition(this->bishops[i]->getPositon());
					this->bishops[i]->bishop.setScale(sf::Vector2f(0, 0));
					this->isKingInChah();
				}
				else if (this->pawn && this->pawn->IsCanMove(this->bishops[i]->getPositon()))
				{
				
					this->pawn->setPosition(this->bishops[i]->getPositon());
					this->bishops[i]->bishop.setScale(sf::Vector2f(0, 0));
					this->isKingInChah();
				}
				else if (this->king && this->king->IsCanMove(this->bishops[i]->getPositon()))
				{
					
					this->king->setPosition(this->bishops[i]->getPositon());
					this->bishops[i]->bishop.setScale(sf::Vector2f(0, 0));
					this->isKingInChah();
				}
				else if (this->knight && this->knight->isCanMove(this->bishops[i]->getPositon()))
				{
				
					this->knight->setPosition(this->bishops[i]->getPositon());
					this->bishops[i]->bishop.setScale(sf::Vector2f(0, 0));
					this->isKingInChah();
				}
				else if (this->lady && this->lady->isCanMove(this->bishops[i]->getPositon()))
				{
					
					this->lady->setPosition(this->bishops[i]->getPositon());
					this->bishops[i]->bishop.setScale(sf::Vector2f(0, 0));
					this->isKingInChah();
				}
				else if (this->queen && this->queen->isCanMove(this->bishops[i]->getPositon()))
				{
					
					this->queen->setPosition(this->bishops[i]->getPositon());
					this->bishops[i]->bishop.setScale(sf::Vector2f(0, 0));
					this->isKingInChah();
				}



				this->pawn = nullptr;
				this->lady = nullptr;
				this->bishop = nullptr;
				this->queen = nullptr;
				this->knight = nullptr;
			}
		}

	if (!isInChah)
	{
		if (this->queen && this->queen->isOpen(this->mousePosView, this->knights, this->whitePawns, this->blackPawns, this->ladies, this->bishops, this->blackQueen) && this->whiteQueen->getGlobalBounds(this->mousePosView) &&
			((this->pawn && this->pawn->isWhite != true) || (this->lady && this->lady->isWhite != true) ||
				(this->bishop && this->bishop->isWhite != true) || (this->knight && this->knight->isWhite != true) || (this->queen && this->queen->isWhite != true)))
		{
			if (this->bishop && this->bishop->isCanMove(this->whiteQueen->getPositon()))
			{
		
				bishop->setPosition(this->whiteQueen->getPositon());
				this->whiteQueen->queen.setScale(sf::Vector2f(0, 0));
				this->isKingInChah();
			}
			else if (this->pawn && this->pawn->IsCanMove(this->whiteQueen->getPositon()))
			{
			
				this->pawn->setPosition(this->whiteQueen->getPositon());
				this->whiteQueen->queen.setScale(sf::Vector2f(0, 0));
				this->isKingInChah();
			}
			else if (this->knight && this->knight->isCanMove(this->whiteQueen->getPositon()))
			{
				
				this->knight->setPosition(this->whiteQueen->getPositon());
				this->whiteQueen->queen.setScale(sf::Vector2f(0, 0));
				this->isKingInChah();
			}
			else if (this->lady && this->lady->isCanMove(this->whiteQueen->getPositon()))
			{
				
				this->lady->setPosition(this->whiteQueen->getPositon());
				this->whiteQueen->queen.setScale(sf::Vector2f(0, 0));
				this->isKingInChah();
			}
			else if (this->queen && this->queen->isCanMove(this->whiteQueen->getPositon()))
			{
				
				this->queen->setPosition(this->whiteQueen->getPositon());
				this->whiteQueen->queen.setScale(sf::Vector2f(0, 0));
				this->isKingInChah();
			}


			this->pawn = nullptr;
			this->lady = nullptr;
			this->bishop = nullptr;
			this->queen = nullptr;
			this->knight = nullptr;

		}

		else if (this->blackQueen && this->blackQueen->isOpen(this->mousePosView, this->knights, this->whitePawns, this->blackPawns, this->ladies, this->bishops, this->whiteQueen) && this->blackQueen->getGlobalBounds(this->mousePosView) &&
			((this->pawn && this->pawn->isWhite == true) || (this->lady && this->lady->isWhite == true) ||
				(this->bishop && this->bishop->isWhite == true) || (this->knight && this->knight->isWhite == true) || (this->queen && this->queen->isWhite == true)))
		{
			if (this->bishop && this->bishop->isCanMove(this->blackQueen->getPositon()))
			{
			
				bishop->setPosition(this->blackQueen->getPositon());
				this->blackQueen->queen.setScale(sf::Vector2f(0, 0));
				this->isKingInChah();
			}
			else if (this->pawn && this->pawn->IsCanMove(this->blackQueen->getPositon()))
			{
				
				this->pawn->setPosition(this->blackQueen->getPositon());
				this->blackQueen->queen.setScale(sf::Vector2f(0, 0));
				this->isKingInChah();
			}
			else if (this->knight && this->knight->isCanMove(this->blackQueen->getPositon()))
			{
				
				this->knight->setPosition(this->blackQueen->getPositon());
				this->blackQueen->queen.setScale(sf::Vector2f(0, 0));
				this->isKingInChah();
			}
			else if (this->lady && this->lady->isCanMove(this->blackQueen->getPositon()))
			{
				
				this->lady->setPosition(this->blackQueen->getPositon());
				this->blackQueen->queen.setScale(sf::Vector2f(0, 0));
				this->isKingInChah();
			}
			else if (this->queen && this->queen->isCanMove(this->blackQueen->getPositon()))
			{
				
				this->queen->setPosition(this->blackQueen->getPositon());
				this->blackQueen->queen.setScale(sf::Vector2f(0, 0));
				this->isKingInChah();
			}


			this->pawn = nullptr;
			this->lady = nullptr;
			this->bishop = nullptr;
			this->queen = nullptr;
			this->knight = nullptr;
		}
	}
	
}

void GameState::updateInput()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (!this->isInChah)
		{
			for (int i = 0; i < this->whitePawns.size(); i++)
			{

				if (this->whitePawns[i]->getGlobalBounds(this->mousePosView))
				{
					this->pawn = this->whitePawns[i];
					this->isClicked = true;
				}

			}
			for (int i = 0; i < this->blackPawns.size(); i++)
			{
				if (this->blackPawns[i]->getGlobalBounds(this->mousePosView))
				{
					this->pawn = this->blackPawns[i];
					this->isClicked = true;
				}
			}
			for (int i = 0; i < this->ladies.size(); i++)
			{
				if (this->ladies[i]->getGlobalBounds(this->mousePosView))
				{
					this->lady = this->ladies[i];
					this->isClicked = true;
				}
			}
			for (int i = 0; i < this->knights.size(); i++)
			{
				if (this->knights[i]->getGlobalBounds(this->mousePosView))
				{
					this->knight = this->knights[i];
					this->isClicked = true;

				}
			}
			for (int i = 0; i < this->bishops.size(); i++)
			{
				if (this->bishops[i]->getGlobalBounds(this->mousePosView))
				{
					this->bishop = this->bishops[i];
					this->isClicked = true;
				}
			}
			if (this->blackQueen->getGlobalBounds(this->mousePosView))
				this->queen = this->blackQueen;
			else if (this->whiteQueen->getGlobalBounds(this->mousePosView))
				this->queen = this->whiteQueen;

				if (this->whiteKing->getGlobalBounds(this->mousePosView))
					this->king = this->whiteKing;
		
				if (this->blackKing->getGlobalBounds(this->mousePosView))
					this->blackking = this->blackKing;
			
		}
		else
		{
			if (this->isWhite)
			{
				if (this->whiteKing->getGlobalBounds(this->mousePosView))
					this->king = this->whiteKing;
			}
			else
			{
				if (this->blackKing->getGlobalBounds(this->mousePosView))
					this->blackking = this->blackKing;
			}
		}
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		if (this->pawn || this->lady ||this->knight ||this->bishop || this->queen||this->king ||this->blackking)
		{
			this->checkForEating();
			this->checkForClicked();		
		}
	}
}

void GameState::isKingInChah() {


	coor.x = floor(this->whiteKing->getPositon().x) / 100;
	coor.y = floor(this->whiteKing->getPositon().y) / 100;

	std::cout << "I: " << coor.x << "  " << coor.y << "\n";

	for (int i = 0; i < this->knights.size(); i++)
	{
		if (knights[i]->isWhite != true)
		{
			std::vector<Cor*> coorDinates;
			for (int j = 0; j < this->knights[i]->getNextCanMove().size(); j++)
			{
				coorDinates = this->knights[i]->getNextCanMove();

				if (coor.x == coorDinates[j]->y && coor.y == coorDinates[j]->x)
				{
					
					isInChah = true;
					isWhite = true;
					return;
				}
				std::cout << "A: " << coorDinates[j]->x << "  " << coorDinates[j]->y << "\n";
			}
		}
	}

	for (int i = 0; i < this->bishops.size(); i++)
	{
		if (bishops[i]->isWhite != true)
		{
			for (int j = 0; j < this->bishops[i]->getNextMove().size(); j++)
			{


				int x = floor(this->bishops[i]->getNextMove().at(j)->x) / 100;
				int y = floor(this->bishops[i]->getNextMove().at(j)->y) / 100;

				if (coor.x == x && coor.y == y)
				{
					isInChah = true;
					isWhite = true;
					return;
				}

			}
		}
	}

	for (int i = 0; i < this->ladies.size(); i++)
	{
		for (int j = 0; j < this->ladies[i]->getNextMove().size(); j++)
		{
			if (ladies[i]->isWhite != true)
			{
				int x = floor(this->ladies[i]->getPositon().x) / 100;
				int y = floor(this->ladies[i]->getPositon().y) / 100;

				if (coor.x == x && coor.y == y)
				{
					isInChah = true;
					isWhite = true;
					return;
				}
			}
		}
	}
	for (int i = 0; i < this->blackPawns.size(); i++)
	{
		for (int j = 0; j < this->blackPawns[i]->getNextMove().size(); j++)
		{
				int x = floor(this->blackPawns[i]->getPositon().x) / 100;
				int y = floor(this->blackPawns[i]->getPositon().y) / 100;
				if (coor.x == x && coor.y == y)
				{
					isWhite = true;
					isInChah = true;
					return;
				}
			
		}
	}

	int x = floor(this->blackQueen->getPositon().x) / 100;
	int y = floor(this->blackQueen->getPositon().y) / 100;
	if (x == coor.x && y == coor.y)
	{
		isInChah = true;
		isWhite = true;
		return;
	}

	coor = sf::Vector2i(this->blackKing->getPositon());
	coor.x = floor(coor.x) / 100;
	coor.y = floor(coor.y) / 100;

	for (int i = 0; i < this->knights.size(); i++)
	{
		for (int j = 0; j < this->knights[i]->getNextCanMove().size(); j++)
		{

			if (ladies[i]->isWhite == true)
			{
				int x = floor(this->knights[i]->getPositon().x) / 100;
				int y = floor(this->knights[i]->getPositon().y) / 100;

				if (coor.x == x && coor.y == y)
				{
					isInChah = true;
					isWhite = false;
					return;
				}
			}
		}
	}

	for (int i = 0; i < this->bishops.size(); i++)
	{
		for (int j = 0; j < this->bishops[i]->getNextMove().size(); j++)
		{

			if (bishops[i]->isWhite == true)
			{
				int x = floor(this->bishops[i]->getPositon().x) / 100;
				int y = floor(this->bishops[i]->getPositon().y) / 100;

				if (coor.x == x && coor.y == y)
				{
					isInChah = true;
					isWhite = false;
					return;
				}
			}
		}
	}

	for (int i = 0; i < this->ladies.size(); i++)
	{
		for (int j = 0; j < this->ladies[i]->getNextMove().size(); j++)
		{
			if (ladies[i]->isWhite == true)
			{
				int x = floor(this->ladies[i]->getPositon().x) / 100;
				int y = floor(this->ladies[i]->getPositon().y) / 100;

				if (coor.x == x && coor.y == y)
				{
					isInChah = true;
					isWhite = false;
					return;
				}
			}
		}
	}
	for (int i = 0; i < this->whitePawns.size(); i++)
	{
		for (int j = 0; j < this->whitePawns[i]->getNextMove().size(); j++)
		{
			int x = floor(this->whitePawns[i]->getPositon().x) / 100;
			int y = floor(this->whitePawns[i]->getPositon().y) / 100;
			if (coor.x == x && coor.y == y)
			{
				isWhite = false;
				isInChah = true;
				return;
			}

		}
	}

	x = floor(this->whiteQueen->getPositon().x) / 100;
    y = floor(this->whiteQueen->getPositon().y) / 100;
	if (x == coor.x && y == coor.y)
	{
		isInChah = true;
		isWhite = false;
		return;
	}

}