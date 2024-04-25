#include <conio.h> // for kbhit+getch
#include <iostream>
#include <Windows.h> // for Sleep and colors

#include "board.h"
#include "game.h"
#include "shapes.h"
#include "general.h"


void game:: playGame()
{

	shapes ChooseShape; // all the shapes of the egame
	srand(time(NULL));
	Shape TetrisShapeLeftPlayer;
	TetrisShapeLeftPlayer.initPlayer(LEFT_PLAYER);

	Shape TetrisShapeRightPlayer;
	TetrisShapeRightPlayer.initPlayer(RIGHT_PLAYER);

	board GameBoardLeftPlayer;
	board GameBoardRightPlayer;
	char key = ' ';
	int LeftPlayer = 0, RightPlayer = 1, GameStatus = BEGINING_OF_GAME, player = 0, colors = 0;

	
	GameStatus = this->GameMenu(); // shows the menu with all the options
	colors = isGameWithColor(GameStatus); // ask the pleywr if game with colors or without colors

	if (GameStatus == START_GAME_WITH_COLORS || GameStatus == START_GAME_WITHOUT_COLORS) // if plyer press strat game and choose game with/without color
	{
		while (GameStatus!= LEFT_PLAYER_WON && GameStatus!= RIGHT_PLAYER_WON && GameStatus!= EXIT) // while no one wins or the player dosent press exit
		{
			ChooseShape.randShape(TetrisShapeLeftPlayer, colors);// choose random shape for left player
			ChooseShape.randShape(TetrisShapeRightPlayer, colors); // for right player
			GameBoardLeftPlayer.drawBorder(TetrisShapeLeftPlayer); 
			GameBoardRightPlayer.drawBorder(TetrisShapeRightPlayer);

			while (true)
			{
				if (key == ESC) // player pause game
				{
					GameStatus = PAUSE_GAME;
					system("cls");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					GameStatus = this->GameMenu();
					if (GameStatus == CONTINUE_GAME)
					{
						GameBoardLeftPlayer.drawBorder(TetrisShapeLeftPlayer);
						GameBoardRightPlayer.drawBorder(TetrisShapeRightPlayer);
						GameBoardLeftPlayer.printBoard(TetrisShapeLeftPlayer);
						GameBoardRightPlayer.printBoard(TetrisShapeRightPlayer);

						key = KEEP_GOING;
					}
					else if (GameStatus == EXIT)
					{
						break;
					}
					else if (GameStatus == START_GAME_WITH_COLORS || GameStatus == START_GAME_WITHOUT_COLORS)
					{
						system("cls");
						GameBoardRightPlayer.clearBoard();
						GameBoardLeftPlayer.clearBoard();
						colors = isGameWithColor(GameStatus);
						key = KEEP_GOING;
						break;

					}
				}

				//drawing the shpae
				TetrisShapeLeftPlayer.drawShape('X');
				TetrisShapeRightPlayer.drawShape('X');
				Sleep(400);
				TetrisShapeLeftPlayer.drawShape(' ');
				TetrisShapeRightPlayer.drawShape(' ');

				//moving the shape down allways
				TetrisShapeLeftPlayer.moveShapeDown();
				TetrisShapeRightPlayer.moveShapeDown();



				//checking if the shape got to the bottom or on another shape
				if (this->isShapeStop(GameBoardLeftPlayer, TetrisShapeLeftPlayer))
				{
					GameBoardLeftPlayer.changeBoard(TetrisShapeLeftPlayer);
					GameBoardLeftPlayer.isLineFull();
					GameBoardLeftPlayer.printBoard(TetrisShapeLeftPlayer);
					ChooseShape.randShape(TetrisShapeLeftPlayer, colors);
					TetrisShapeLeftPlayer.initPlayer(LEFT_PLAYER);
				}
				if (this->isShapeStop(GameBoardRightPlayer, TetrisShapeRightPlayer))
				{
					GameBoardRightPlayer.changeBoard(TetrisShapeRightPlayer);
					GameBoardRightPlayer.isLineFull();
					GameBoardRightPlayer.printBoard(TetrisShapeRightPlayer);
					ChooseShape.randShape(TetrisShapeRightPlayer, colors);
					TetrisShapeRightPlayer.initPlayer(RIGHT_PLAYER);
				}

				// if players pressing the moves bottens
				if (_kbhit())
				{
					key = _getch();

					//checking witch player press the key board 
					player = PlayerKey(key);

					if (player == LEFT_PLAYER)
					{
						if (GameBoardLeftPlayer.isValidMove(TetrisShapeLeftPlayer, key)) // checking if the move is valid
							TetrisShapeLeftPlayer.MoveLeftPlayer((Shape::eKeys)key); // moves the shape based on the key

					}
					else if (player == RIGHT_PLAYER)
					{
						if (GameBoardRightPlayer.isValidMove(TetrisShapeRightPlayer, key))
							TetrisShapeRightPlayer.MoveRightPlayer((Shape::eKeys)key);
					}

				}



				// checking if one of the players won 
				GameStatus = isGameOver(GameBoardLeftPlayer, GameBoardRightPlayer);
				if (GameStatus == LEFT_PLAYER_WON || GameStatus == RIGHT_PLAYER_WON)
				{
					system("cls");
					gotoxy(10, 2);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					printWinner(GameStatus);
					gotoxy(7, 4);
					cout << "Press any key to continue" << endl;
					key = _getch();

					GameStatus = GameMenu();

					// for playing another game after a win of one of the players
					if (GameStatus == START_GAME_WITH_COLORS || GameStatus == START_GAME_WITHOUT_COLORS)
					{
						system("cls");
						GameBoardRightPlayer.clearBoard();
						GameBoardLeftPlayer.clearBoard();
						colors = isGameWithColor(GameStatus);
						key = KEEP_GOING;
						break;

					}
					if (GameStatus == EXIT)
						break;
				

				}
			}
		}
	}
}
//for checking if the shape got to the bottom or is on another shape 
bool game::isShapeStop(board& gameBoard, Shape& currentShape)
{
	int rotation = currentShape.getRotation();
	Point** shape = currentShape.getShapeCordinates();
	char** board = gameBoard.getBoard();
	int y = 0 , x = 0; 

	for (int i = 0; i < SHAPE_SIZE; i++)
	{
		y = (shape[rotation][i].y);
		x = (shape[rotation][i].x + MIDDLE_SCREEN_LEFT_PLAYER);

		if ((y == ONE_BOARD_HEIGHT) || (board[y+1][x] != ' '))
			return true;			
	}
	
	return false;
}
// checking witch player pressed the key board for a fastter respond with the moves
int game:: PlayerKey(int key)
{
	int leftPlayer = 0, rightPlayer = 1;

	if ((Shape::eKeys)key == Shape::eKeys::DROP1 || (Shape::eKeys)key == Shape::eKeys::DROP1_CAMEL_CASE || (Shape::eKeys)key == Shape::eKeys::LEFT1 || (Shape::eKeys)key == Shape::eKeys::LEFT1_CAMEL_CASE || (Shape::eKeys)key == Shape::eKeys::RIGHT1 || (Shape::eKeys)key == Shape::eKeys::RIGHT1_CAMEL_CASE || (Shape::eKeys)key == Shape::eKeys::ROTATE_COLCK1 || (Shape::eKeys)key == Shape::eKeys::ROTATE_COLCK1_CAMEL_CASE || (Shape::eKeys)key == Shape::eKeys::ROTATE_COUNTER_CLOCK1 || (Shape::eKeys)key == Shape::eKeys::ROTATE_COUNTER_CLOCK1_CAMEL_CASE)
		return leftPlayer;

	else
	{
		if ((Shape::eKeys)key == Shape::eKeys::DROP2 || (Shape::eKeys)key == Shape::eKeys::DROP2_CAMEL_CASE|| (Shape::eKeys)key == Shape::eKeys::LEFT2 || (Shape::eKeys)key == Shape::eKeys ::LEFT2_CAMEL_CASE|| (Shape::eKeys)key == Shape::eKeys::RIGHT2 || (Shape::eKeys)key == Shape::eKeys::RIGHT2_CAMEL_CASE|| (Shape::eKeys)key == Shape::eKeys::ROTATE_COLCK2 || (Shape::eKeys)key == Shape::eKeys::ROTATE_COLCK2_CAMEL_CASE || (Shape::eKeys)key == Shape::eKeys::ROTATE_COUNTER_CLOCK2 || (Shape::eKeys)key == Shape::eKeys::ROTATE_COUNTER_CLOCK2_CAMEL_CASE)
			return rightPlayer;
	}


}
int game::GameMenu()
{
	gotoxy(0, 0);
	char key, color = 'c';
	static bool isBeginingOfTheGame  = true;

	system("cls");
	cout << "(1) Start a new game" << endl;
	if (isBeginingOfTheGame == false)
		cout << "(2) Continue a paused game" << endl;
	cout << "(8) Present instructionsand keys" << endl;
	cout << "(9) EXIT" << endl;
	
	key = _getch();
	
	system("cls");

	switch (key)
	{
	case '1':
		isBeginingOfTheGame = true;
		system("cls");
		gotoxy(0, 0);

		cout << "(c) For plyaing in color" << endl;
		cout << "(b) For playing in black and white" << endl;

		color = _getch();

	
			while (color != 'c' && color != 'b')
			{
				gotoxy(0, 4);
				cout << "Invalid key, Please try again!" << endl;
				color = _getch();
			}
			
		system("cls");
		isBeginingOfTheGame = false;

		switch (color)
		{
		case'c':
			return START_GAME_WITH_COLORS;
			break;
		case 'b':
			return START_GAME_WITHOUT_COLORS;
			break;
		case ESC:
			GameMenu();		
		}

	case'2':
		return CONTINUE_GAME;
		break;

	case'8':

		while (key != ESC)
		{
			gotoxy(0, 0);
			cout << "How to Play Tetris: A Quick Guide." << endl << endl;
			cout << "Welcome to Tetris, the classic and addictive block - stacking puzzle game!" << endl;
			cout << "Follow these instructions to dive into the world of Tetris and sharpen your strategic skills." << endl;
			cout << "Objective:" << endl;
			cout << "The goal of Tetris is to clear lines by arranging falling blocks(tetriminos)" << endl;
			cout << "in a way that completes horizontal lines across the game grid." << endl << endl;
			cout << "Controls:" << endl << endl;
			cout << "Left player keys: " << endl;
			cout << "Left: a or A" << endl;
			cout << "Right: d or D" << endl;
			cout << "Rotate colokwise: s or S" << endl;
			cout << "Rotate counterclockseise: w or W" << endl;
			cout << "Drop: x or X" << endl << endl;
			cout << "Right player keys:" << endl;
			cout << "Left: j or J" << endl;
			cout << "Right: l (small L) or L" << endl;
			cout << "Rotate colokwise: k or k" << endl;
			cout << "Rotate counterclockseise: i or I(uppercase i)" << endl;
			cout << "Drop: m or M" << endl;
			key = _getch();
		}
		if (key == ESC)
		{
			GameMenu();
		}
		break;
	case '9':
		system("cls");
		gotoxy(10, 2);
		cout << "GAME OVER!" << endl;
		gotoxy(6, 3);
		cout << "Thank you for playing" << endl;
		return EXIT;
		break;
	}

	isBeginingOfTheGame = false;
}

// for checking if one of the players got to the top , so the other pkayer won 
int game:: isGameOver(board& leftBoard , board& rightBoard)
{
	char** leftBoardPointer = leftBoard.getBoard();
	char** rightBoardPointer = rightBoard.getBoard();
	int winner = NO_WIN_KEEP_GOING;

	for (int i = 1; i <= ONE_BOARD_WIDTH; i++)
	{
		if (leftBoardPointer[1][i] != ' ')
			winner = RIGHT_PLAYER_WON;
		
	}
	for (int i = 1; i <= ONE_BOARD_WIDTH; i++)
	{
		if (rightBoardPointer[1][i] != ' ')
			winner = LEFT_PLAYER_WON;
	}

	return winner;

}
//checking what the user sellected 
int game:: isGameWithColor(int GameStatus)
{
	int colors = 0;

	if (GameStatus == START_GAME_WITH_COLORS)
		colors = COLORS;
	else if (GameStatus == START_GAME_WITHOUT_COLORS)
		colors = NO_COLORS;

	return colors;
}

void game:: printWinner(int winner)
{
	if (winner == LEFT_PLAYER_WON)
	{
		cout << "LEFT PLAYER WON!" << endl;
	}
	else if (winner == RIGHT_PLAYER_WON)
	{
		cout << "RIGHT PLAYER WON!" << endl << endl;
	}
}












