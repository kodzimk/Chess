#pragma once
#include"stdafh.h"
#include"GameBoard.h"
#include"Pawn.h"
#include"Queen.h"
#include"Bishop.h"
#include"King.h"
#include"Knight.h"
#include"Lady.h"

class GameState {

public:

	std::vector<sf::RectangleShape> shapes;
	std::vector<Pawn*> whitePawns;
	std::vector<Pawn*> blackPawns;
	std::vector<Bishop*> bishops;
	std::vector<Knight*> knights;
	std::vector<Lady*> ladies;

	King* blackking;
	King* king;
	Queen* queen;
	Bishop* bishop;
	Knight* knight;
	Lady* lady;
	Queen* whiteQueen;
	Queen* blackQueen;
	King* whiteKing;
	King* blackKing;
	sf::RenderWindow* window;
	GameBoard board;
	Pawn* pawn;
	int count = 0;
	sf::Vector2f mousePosView;

	float gridSize;
	bool isInChah;
	sf::Vector2i coor;
	bool isWhite;
	bool isClicked;

	void initPieces();
	void initShapes();
	void initVariables();

	GameState();

	void updateGame();
	void render();
	void checkForClicked();
	void checkForEating();
	void updateInput();
	void isKingInChah();
	


	~GameState();
};