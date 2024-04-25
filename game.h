#pragma once
#include "board.h"
class game
{
private:
	static constexpr int SHAPE_SIZE = 4;
	static constexpr int MIN_X_LEFT_PLAYER = 0;
	static constexpr int MIN_X_RIGHT_PLAYER = 17;
	static constexpr int MIDDLE_SCREEN_LEFT_PLAYER = 5;
	static constexpr int ONE_BOARD_WIDTH = 12;
	static constexpr int ONE_BOARD_HEIGHT = 18;

	static constexpr int LEFT_PLAYER = 0;
	static constexpr int RIGHT_PLAYER = 1;
	static constexpr int LEFT_PLAYER_WON = 0;
	static constexpr int RIGHT_PLAYER_WON = 1;
	static constexpr int BEGINING_OF_GAME = 10;
	static constexpr int START_GAME_WITH_COLORS = 11;
	static constexpr int START_GAME_WITHOUT_COLORS = 12;
	static constexpr int CONTINUE_GAME = 2;
	static constexpr int NO_WIN_KEEP_GOING = 4;
	static constexpr int PAUSE_GAME = 5;
	static constexpr int EXIT = 9;
	static constexpr char KEEP_GOING = 't';

	static constexpr int NO_COLORS = 20;
	static constexpr int COLORS = 30;

public:
	enum { ESC = 27 };
	int isGameWithColor(int GameStatus);
	void playGame();
	bool isShapeStop(board& gameBoard, Shape& currentShape);
	int PlayerKey(int key);
	int GameMenu();
	int isGameOver(board& leftBoard, board& rightBoard);
	void printWinner(int winner);

};

