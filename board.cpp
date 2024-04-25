#include <iostream>
#include "board.h"
#include "general.h"
#include "Shape.h"
#include <string.h>
using namespace std;
void const board:: printBoard(Shape& shape) const
{
	int color;
	int boardStartingPoint = 0;
	int player = shape.getPlayer();


	if (player == 0)
		boardStartingPoint = MIN_X_LEFT_PLAYER ;
	else
		boardStartingPoint = MIN_X_RIGHT_PLAYER;

	for (int i = 1; i <= ONE_BOARD_HEIGHT; i++)
	{
		for (int j = 1; j <= ONE_BOARD_WIDTH; j++)
		{			
			if (this->GAME_BOARD[i][j] != ' ')
			{
				gotoxy(j + boardStartingPoint , i);
				color = (int)GAME_BOARD[i][j];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
				cout << "X" << endl;
			}
			if (GAME_BOARD[i][j] == ' ')
			{
				gotoxy(j + boardStartingPoint, i );
				cout << ' ';
			}
				
		}
	}
}
// if shappe got in possision the board is changed based on the shape cordinates
void board:: changeBoard(Shape& shape)
{
	Point** shapeCordinates = shape.getShapeCordinates();
	int rotationPosition = shape.getRotation();
	int x = 0, y = 0;
	int color = shape.getColor();

	for (int i = 0; i < SHAPE_SIZE; i++)
	{
		x = shapeCordinates[rotationPosition][i].x + MIDDLE_BOARD;
		y = shapeCordinates[rotationPosition][i].y;
		this->GAME_BOARD[y][x] = char(color);
	}
	
}
char** board:: getBoard()
{
	return GAME_BOARD;
}
void board::drawBorder(Shape& shape)
{
	int player = shape.getPlayer();

	if (player == LEFT_PLAYER)
	{
		for (int col = 0; col <= board::ONE_BOARD_WIDTH + 1; col++)
		{
			gotoxy(col, 0);
			cout << "-";

			gotoxy(col, board::ONE_BOARD_HEIGHT + 1);
			cout << "-";
		}
		for (int row = 0; row <= board::GMAE_HEIGHT + 1; row++)
		{
			gotoxy(0, row);
			cout << "|";

			gotoxy(board::ONE_BOARD_WIDTH + 1, row);
			cout << "|";
		}



	}
	else if(player == RIGHT_PLAYER)
	{
		for (int col = MIN_X_RIGHT_PLAYER; col <= board::GAME_WIDTH + 1; col++)
		{
			gotoxy(col, 0);
			cout << "-";

			gotoxy(col, board::GMAE_HEIGHT + 1);
			cout << "-";


		}

		for (int row = 0; row <= board::GMAE_HEIGHT + 1; row++)
		{
			gotoxy(0, row);
			cout << "|";

			gotoxy(board::ONE_BOARD_WIDTH + 1, row);
			cout << "|";

			gotoxy(board::GAME_WIDTH - board::ONE_BOARD_WIDTH, row);
			cout << "|";

			gotoxy(board::GAME_WIDTH + 1, row);
			cout << "|";
		}
	}
}
// cheking if the key that was the pressed is valid, or the move is possibole based on the board limits and data
bool board:: isValidMove(Shape& currentShape, int key)
{
	int rotation = currentShape.getRotation();
	Point** shape = currentShape.getShapeCordinates();
	int player = currentShape.getPlayer();
	int x = 0, y = 0;

	if (player == LEFT_PLAYER)
	{
		if ((Shape::eKeys)key == Shape::eKeys::RIGHT1 || ((Shape::eKeys)key == Shape::eKeys::RIGHT1_CAMEL_CASE))
		{
			for (int i = 0; i < SHAPE_SIZE; i++)
			{
				x = shape[rotation][i].x + MIDDLE_SCREEN_LEFT_PLAYER;
					y = shape[rotation][i].y;

					if (x >= (ONE_BOARD_WIDTH) || (GAME_BOARD[y][x + 1] != ' '))
						return false;
			}
		}
		else if ((Shape::eKeys)key == Shape::eKeys::LEFT1 || (Shape::eKeys)key == Shape::eKeys::LEFT1_CAMEL_CASE)
		{
			for (int i = 0; i < SHAPE_SIZE; i++)
			{
				x = shape[rotation][i].x + MIDDLE_SCREEN_LEFT_PLAYER;
				y = shape[rotation][i].y;

				if ((x <= 1) || (GAME_BOARD[y][x - 1] != ' '))
					return false;
			}
		}
		else if((Shape::eKeys)key == Shape::eKeys::DROP1 || (Shape::eKeys)key == Shape::eKeys::DROP1_CAMEL_CASE)
		{
			for (int i = 0; i < SHAPE_SIZE; i++)
			{
				x = shape[rotation][i].x + MIDDLE_SCREEN_LEFT_PLAYER;
				y = shape[rotation][i].y;

				if ((y+1) == ONE_BOARD_HEIGHT)
					return false;
			}
		}
		else if ((Shape::eKeys)key == Shape::eKeys::ROTATE_COLCK1 || (Shape::eKeys)key == Shape::eKeys::ROTATE_COLCK1_CAMEL_CASE)
		{
			for (int i = 0; i < SHAPE_SIZE; i++)
			{
				x = shape[(rotation + 1) % 4][i].x + MIDDLE_SCREEN_LEFT_PLAYER;
				y = shape[(rotation + 1) % 4][i].y;

				if (x <= 0 || x >= (ONE_BOARD_WIDTH + 1) || y > ONE_BOARD_HEIGHT|| (GAME_BOARD[y][x - 1] != ' ') || (GAME_BOARD[y][x + 1] != ' ')  || (GAME_BOARD[y + 1][x] != ' '))
					return false;
			}
		}
		else if ((Shape::eKeys)key == Shape::eKeys::ROTATE_COUNTER_CLOCK1 || (Shape::eKeys)key == Shape::eKeys::ROTATE_COUNTER_CLOCK1_CAMEL_CASE)
		{
			for (int i = 0; i < SHAPE_SIZE; i++)
			{
				x = shape[(rotation + 4) % 4][i].x + MIDDLE_SCREEN_LEFT_PLAYER;
				y = shape[(rotation + 4) % 4][i].y;

				if (x <= 0 || x >= (ONE_BOARD_WIDTH + 1) || y > ONE_BOARD_HEIGHT ||(GAME_BOARD[y][x - 1] != ' ') || (GAME_BOARD[y][x + 1] != ' ')  || (GAME_BOARD[y + 1][x] != ' '))
					return false;
			}
		}
	}
	if (player == RIGHT_PLAYER)
	{
		if ((Shape::eKeys)key == Shape::eKeys::RIGHT2 || (Shape::eKeys)key == Shape::eKeys::RIGHT2_CAMEL_CASE)
		{
			for (int i = 0; i < SHAPE_SIZE; i++)
			{
				x = shape[rotation][i].x + MIDDLE_BOARD;
				y = shape[rotation][i].y;

				if (x >= ONE_BOARD_WIDTH || (GAME_BOARD[y][x + 1] != ' '))
					return false;
			}
		}
		else if ((Shape::eKeys)key == Shape::eKeys::LEFT2 || (Shape::eKeys)key == Shape::eKeys::LEFT2_CAMEL_CASE)
		{
			for (int i = 0; i < SHAPE_SIZE; i++)
			{
				x = shape[rotation][i].x + MIDDLE_BOARD;
				y = shape[rotation][i].y;

				if (x <= 1)
					return false;
				if ((x <= 1) || (GAME_BOARD[y][x - 1] != ' '))
					return false;
			}
		}
		else if ((Shape::eKeys)key == Shape::eKeys::ROTATE_COLCK2 || (Shape::eKeys)key == Shape::eKeys::ROTATE_COLCK2_CAMEL_CASE)
		{
			for (int i = 0; i < SHAPE_SIZE; i++)
			{
				x = shape[(rotation + 1) % 4][i].x + MIDDLE_BOARD;
				y = shape[(rotation + 1) % 4][i].y;

				if ((x <= 0) || x >= (ONE_BOARD_WIDTH + 1) || y > ONE_BOARD_HEIGHT|| (GAME_BOARD[y][x - 1] != ' ') || (GAME_BOARD[y][x + 1] != ' ') || (GAME_BOARD[y + 1][x] != ' '))
					return false;
			}
		}
		else if ((Shape::eKeys)key == Shape::eKeys::ROTATE_COUNTER_CLOCK2 || (Shape::eKeys)key == Shape::eKeys::ROTATE_COUNTER_CLOCK2_CAMEL_CASE)
		{
			for (int i = 0; i < SHAPE_SIZE; i++)
			{
				x = shape[(rotation + 4) % 4][i].x + MIDDLE_BOARD;
				y = shape[(rotation + 4) % 4][i].y;

				if (x <= 0 || x >= (ONE_BOARD_WIDTH + 1) || y > ONE_BOARD_HEIGHT || (GAME_BOARD[y][x - 1] != ' ') || (GAME_BOARD[y][x + 1] != ' ') || (GAME_BOARD[y + 1][x] != ' '))
				return false;
			}
		}
		else if ((Shape::eKeys)key == Shape::eKeys::DROP2 || (Shape::eKeys)key == Shape::eKeys::DROP2_CAMEL_CASE)
		{
			for (int i = 0; i < SHAPE_SIZE; i++)
			{
				x = shape[rotation][i].x + MIDDLE_BOARD;
				y = shape[rotation][i].y;	

				if ((y + 1) == ONE_BOARD_HEIGHT)
					return false;
			}
		}
	}
	return true;
}
//for checking if the player filled a all line so it will vanish 
void board:: isLineFull()
{
	int countFullSquars;

	for (int rows = 1; rows <= ONE_BOARD_HEIGHT; rows++)
	{
		countFullSquars = 0;
		for (int cols = 1; cols <= ONE_BOARD_WIDTH; cols++)
		{
			if (GAME_BOARD[rows][cols] != ' ')
				countFullSquars++;
		}
			if (countFullSquars == ONE_BOARD_WIDTH) // if line full
			{
				countFullSquars = 0;
				// Shift lines down starting from the full line
				for (int i = rows; i > 0; i--)
				{
					for (int j = 1 ; j <= ONE_BOARD_WIDTH; j++)
					{
						GAME_BOARD[i][j] = GAME_BOARD[i - 1][j];
					}
				}

				// Clear the top line
				for (int j = 0; j < ONE_BOARD_WIDTH; j++)
				{
					GAME_BOARD[1][j] = ' ';
				}
				
				
			}
	
	}
	
}
// clears the board after game is over and the player wants to start a new game 
 void board:: clearBoard() 
{
	char** board = this->getBoard();

	for (int i = 0; i < ONE_BOARD_HEIGHT + BORDER; i++)
	{
		for (int j = 0; j < ONE_BOARD_WIDTH + BORDER; j++)
		{
			this->GAME_BOARD[i][j] = ' ';
		}
	}
}
