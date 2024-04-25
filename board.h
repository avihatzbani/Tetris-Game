#pragma once
#include <iostream>
#include "Shape.h"

using namespace std;

class board
{

private:
	static constexpr int ONE_BOARD_WIDTH = 12;
	static constexpr int ONE_BOARD_HEIGHT = 18;
	static constexpr int GAME_WIDTH = 12 + 12 + 5;
	static constexpr int GMAE_HEIGHT = 18;

	static constexpr int LEFT_PLAYER = 0;
	static constexpr int RIGHT_PLAYER = 1;
	static constexpr int SHAPE_SIZE = 4;
	static constexpr int BORDER = 2;
	
	static constexpr int MIN_X_LEFT_PLAYER = 0;
	static constexpr int MIN_X_RIGHT_PLAYER = 17;
	static constexpr int MIDDLE_BOARD = 5;
	static constexpr int MIDDLE_SCREEN_LEFT_PLAYER = 5;
	static constexpr int MIDDLE_SCREEN_RIGHT_PLAYER = 14 + 6 + 5;

	char** GAME_BOARD;

public:


	board()
	{
		//alocate memory for the game board 
		GAME_BOARD = new char* [ONE_BOARD_HEIGHT + BORDER];

		for (int j = 0; j < ONE_BOARD_HEIGHT + BORDER; j++)
		{
			GAME_BOARD[j] = new char[ONE_BOARD_WIDTH + BORDER];
		}
		
		for (int i = 0; i < ONE_BOARD_HEIGHT + BORDER; i++)
		{
			for (int j = 0; j < ONE_BOARD_WIDTH + BORDER; j++)
			{
				this->GAME_BOARD[i][j] = ' ';
			}
		}
	}
	~board()
	{
		// Deallocate memory for the game board
		for (int j = 0; j < ONE_BOARD_HEIGHT + BORDER; j++)
		{
			delete[] GAME_BOARD[j];
		}
		delete[] GAME_BOARD;
	}
	
	void const printBoard(Shape& shape) const;
	char** getBoard(); 
	void changeBoard(Shape& shape);
	bool isValidMove(Shape& currentShape, int key);
	void drawBorder(Shape& shape);
	void isLineFull();
	void clearBoard();
};

