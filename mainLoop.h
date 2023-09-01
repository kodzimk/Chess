#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"board.h"
#include"Knight.h"
#include"King.h"
#include"Pawn.h"
#include"Queen.h"
#include"Bishop.h"
#include"Rook.h"

using namespace sf;
using namespace std;

class MainLoop {
public:
	Map board;
	Bishop whiteBishopF, whiteBishopS;
	Bishop blackBishopF, blackBishopS;
	Sprite sprite[32];

	int Biindex = 0, WIndex = 0;

	King blackKing;
	King whiteKing;
	RenderWindow window;
	Rook whiterookS;
	Rook whiteRookF;
	Rook blackrookS;
	Rook blackRookF;
	Pawn blacksPawn[8];
	Pawn whitePawns[8];
	Knight whiteKnightF;
	Knight whiteKnightS;
	Knight blackKnightF;
	Knight blackLnightS;
	Queen blackQueen,whiteQueen;

	bool ClickedToPiece = false;

	Pawn* refWhitePawn;
	Pawn* refBlackP;
	Queen* refBlackQ;
	Queen* refWhiteQ;
	Knight* refBlackKnght;
	Knight* refWhiteKnight;
	Rook* refWhitRook;
	Rook* refBlackRook;
	King* refWhiteKing;
	King* refBlackKing;
	Bishop* refWhiteBishop;
	Bishop* refBlackBishop;



	int wrookIndex = 0,brookIndex = 0,whitePieceCount = 16,BlackPieceCount = 16;
	int whiteIndex = 0,blackIndex = 0,wBK = 0,wWK=0;
	int width = 0, height = 200;
	int clickX, clickY = 0;
	Texture texture;

	MainLoop()
	{	
		init();
		window.create(VideoMode(800, 800), "Chess Game");
		Loop();
	}

	void init()
	{
		refWhiteQ = nullptr;
		refBlackQ = nullptr;
		refWhiteBishop = nullptr;
		refBlackBishop = nullptr;
		refWhitePawn = nullptr;
		refBlackP = nullptr;
		refBlackKing = nullptr;
		refWhiteKnight = nullptr;
		refWhitRook = nullptr;
		refWhiteKing = nullptr;
		refBlackRook = nullptr;
		refBlackKnght = nullptr;


		texture.loadFromFile("board.png");
		for (int i = 0; i < 32; i++)
		{
			if (i > 0 && i % 8 == 0)
			{
				height += 100;
				width = 0;
			}
			if (i % 8 != 0)
				width += 100;

			sprite[i].setTexture(texture);
			sprite[i].setTextureRect(IntRect(width, height, 100, 100));
			sprite[i].setPosition(width, height);

		}
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board.map[i][j] == -3)
				{
					if (Biindex == 0)
						blackBishopF.blackS.setPosition(j * 100, i * 100);
					else
						blackBishopS.blackS.setPosition(j * 100, i * 100);

					Biindex++;
				}
				if (board.map[i][j] == 3)
				{

					if (WIndex == 0)
						whiteBishopF.whiteS.setPosition(j * 100, i * 100);
					else
						whiteBishopS.whiteS.setPosition(j * 100, i * 100);

					WIndex++;
				}
				if (board.map[i][j] == 1)
				{
					whitePawns[whiteIndex].sprite.setPosition(j * 100, i * 100);
					whiteIndex++;
				}
				if (board.map[i][j] == 2)
				{
					if (wWK == 0)
						whiteKnightF.whiteS.setPosition(j * 100, i * 100);
					else
						whiteKnightS.whiteS.setPosition(j * 100, i * 100);
					wWK++;
				}
				if (board.map[i][j] == -2)
				{
					if (wBK == 0)
						blackKnightF.blackS.setPosition(j * 100, i * 100);
					else
						blackLnightS.blackS.setPosition(j * 100, i * 100);
					wBK++;
				}
				if  (board.map[i][j] == -1)
				{
					blacksPawn[blackIndex].blackPawnS.setPosition(j * 100, i * 100);
					blackIndex++;
				}
				if (board.map[i][j] == 5)
				{
					whiteKing.queenS.setPosition(j * 100, i * 100);
				}
				if (board.map[i][j] == -6)
				{
					if (brookIndex == 0)
						blackRookF.blackRookS.setPosition(j * 100, i * 100);
					else
						blackrookS.blackRookS.setPosition(j * 100, i * 100);

					brookIndex++;
				}
				if (board.map[i][j] == 6)
				{
					if (wrookIndex == 0)
						whiterookS.rookS.setPosition(j * 100, i * 100);
					else
						whiteRookF.rookS.setPosition(j * 100, i * 100);

					wrookIndex++;
				}
				if (board.map[i][j] == -5)
				{
					blackKing.blackQuS.setPosition(j * 100, i * 100);

				}
				if (board.map[i][j] == 4)
				{
					whiteQueen.whiteS.setPosition(j * 100, i * 100);
				}
				if (board.map[i][j] == -4)
				{
					blackQueen.blackS.setPosition(j * 100, i * 100);
				}
				
			}
		}
	}


	void Show()
	{
		window.clear();
		window.draw(board.boardS);
		for (int i = 0; i < 32; i++)
		{
			window.draw(sprite[i]);
		}
		window.draw(blackKing.blackQuS);
		window.draw(whiterookS.rookS);
		window.draw(whiteRookF.rookS);
		window.draw(whiteKing.queenS);
		window.draw(blackRookF.blackRookS);
		window.draw(blackrookS.blackRookS);
		window.draw(whiteKnightF.whiteS);
		window.draw(whiteKnightS.whiteS);
		window.draw(blackKnightF.blackS);
		window.draw(blackLnightS.blackS);
		window.draw(blackBishopF.blackS);
		window.draw(blackBishopS.blackS);
		window.draw(whiteBishopF.whiteS);
		window.draw(whiteBishopS.whiteS);
		window.draw(whiteQueen.whiteS);
		window.draw(blackQueen.blackS);

		for (int i = 0; i < 8; i++)
		{
			window.draw(whitePawns[i].sprite);
			window.draw(blacksPawn[i].blackPawnS);
		}
		window.display();
	}

	void CheckBoard()
	{
		ClickedToPiece = false;
		int i = clickY/100;
		int j = clickX/100;
		if (refWhitePawn != nullptr)
		{
			if (board.map[i][j] == 0)
			{
				if (i - refWhitePawn->sprite.getPosition().y / 100 <= 2)
				{
					(refWhitePawn)->sprite.setPosition(j * 100, i * 100);
					board.map[i][j] = 1;
				}
			}
			refWhitePawn = nullptr;
		}
		if (refBlackP != nullptr)
		{
			if (board.map[i][j] == 1)
			{
				for (int i = 0; i < 8; i++)
				{
					if (whitePawns[i].sprite.getGlobalBounds().contains(j,i))
					{
						whitePieceCount--;
						whitePawns[i].sprite.setPosition(-1000, -100);
						(refBlackP)->blackPawnS.setPosition(j * 100, i * 100);
						board.map[i][j] = -1;
					}
				}
			}
			if (board.map[i][j] == 0)
			{
				if (refBlackP->blackPawnS.getPosition().y / 100  - i<= 2)
				{
					(refBlackP)->blackPawnS.setPosition(j * 100, i * 100);
					board.map[i][j] = -1;
				}
			}
			refBlackP = nullptr;
		}
	}

	void Loop()
	{
		while (window.isOpen())
		{
			Event event;
			Vector2i mousePos = Mouse::getPosition(window);

			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}
			if (event.type == Event::MouseButtonPressed)
			{
				for (int i = 0; i < 8; i++)
				{
					if (!ClickedToPiece)
					{
						if (whitePawns[i].sprite.getGlobalBounds().contains(mousePos.x, mousePos.y))
						{
							refWhitePawn = &whitePawns[i];
							ClickedToPiece = true;
							break;
						}
					    else if (blacksPawn[i].blackPawnS.getGlobalBounds().contains(mousePos.x, mousePos.y))
						{
							refBlackP = &blacksPawn[i];
							ClickedToPiece = true;
							break;
						}
					}
					else 
					{
						if (whitePawns[i].sprite.getGlobalBounds().contains(mousePos.x, mousePos.y))
						{
							clickX = (int)whitePawns[i].sprite.getPosition().x;
							clickY = (int)whitePawns[i].sprite.getPosition().y;
							CheckBoard();
							break;
						}
						else if (blacksPawn[i].blackPawnS.getGlobalBounds().contains(mousePos.x, mousePos.y))
						{
							clickX = (int)blacksPawn[i].blackPawnS.getPosition().x;
							clickY = (int)blacksPawn[i].blackPawnS.getPosition().y;
							CheckBoard();
							break;
						}
					}
					
				}

			
				for (int i = 0; i < 32; i++)
				{
					
					if (sprite[i].getGlobalBounds().contains(mousePos.x, mousePos.y))
					{
						if (ClickedToPiece == true)
						{
							clickX = (int)sprite[i].getPosition().x;
							clickY = (int)sprite[i].getPosition().y;
							CheckBoard();
							break;
						}
				    }
				}
			}
			
			Show();
		}
	}

	~MainLoop()
	{
		if(refBlackBishop!=nullptr)
		delete refBlackBishop;
		if(refWhiteBishop!=nullptr)
		delete refWhiteBishop;
		if(refBlackKing!=nullptr)
		delete refBlackKing;
		if (refWhiteKing != nullptr)
		delete refWhiteKing;
		if (refBlackP != nullptr)
			delete refBlackP;
		if (refBlackQ != nullptr)
			delete refBlackQ;
		if (refWhitePawn != nullptr)
			delete refWhitePawn;
		if (refWhiteQ != nullptr)
			delete refWhiteQ;
		if (refBlackKnght != nullptr)
			delete refBlackKnght;
		if (refWhiteKnight != nullptr)
			delete refWhiteKnight;
		if (refBlackRook != nullptr)
			delete refBlackRook;
		if (refWhitRook != nullptr)
			delete refWhitRook;
	}
};