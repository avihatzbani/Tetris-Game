#include "shapes.h"
#include <iostream>
#include <Windows.h>
#include "general.h"
#include "board.h"
#define SHAPE_SIZE 4
#define ROTATION_SIZE 4 // לשאול אם יש דרך אחרת לעשות

using namespace std;

//LEFT1 = 'a', RIGHT1 = 'd', ROTATE_COLCK1 = 's', ROTATE_COUNTER_CLOCK1 = 'w', DROP1 = 'x'
void Shape:: initPlayer(int player)
{
	this->player = player;

}
int Shape::getPlayer()
{
	return this->player;
}
int Shape::getRotation()
{
	return this->rotation;
}
Point** Shape:: getShapeCordinates()
{
	return shape;
}
int Shape::getColor()
{
	return this->backColor;
}
void Shape::init(Point** shape, int backColor, int diff_x, int diff_y, int rotation)
{
	this->backColor = backColor;
	this->diff_x = diff_x;
	this->diff_y = diff_y;
	this->rotation = rotation;


	for (int rotations = 0; rotations < ROTATION_SIZE; rotations++)
	{
		for (int points = 0; points < SHAPE_SIZE; points++)
		{
			this->shape[rotations][points].x = shape[rotations][points].x;
			this->shape[rotations][points].y = shape[rotations][points].y;
		}
	}
}
//changing the shape cordinates sbased on the key the player choose
void Shape::MoveLeftPlayer(Shape::eKeys key)
{
	switch (key)
	{
	case Shape::eKeys::LEFT1:
		diff_x = -1;
		diff_y = 0;
		break;
	case Shape::eKeys::LEFT1_CAMEL_CASE:
		diff_x = -1;
		diff_y = 0;
		break;
	case Shape::eKeys::RIGHT1:
		diff_x = 1;
		diff_y = 0;
		break;
	case Shape::eKeys::RIGHT1_CAMEL_CASE:
		diff_x = 1;
		diff_y = 0;
		break;
	case Shape::eKeys::DROP1:
		diff_x = 0;
		diff_y = 1;
		break;
	case Shape::eKeys::DROP1_CAMEL_CASE:
		diff_x = 0;
		diff_y = 1;
		break;
	case Shape::eKeys::ROTATE_COLCK1:
		
		diff_x = 0;
		diff_y = 0;
		rotation = (++rotation) % 4;

		break;
	case Shape::eKeys::ROTATE_COLCK1_CAMEL_CASE:

		diff_x = 0;
		diff_y = 0;
		rotation = (++rotation) % 4;

		break;
	case Shape::eKeys::ROTATE_COUNTER_CLOCK1:

		diff_x = 0;
		diff_y = 0;
		rotation--;
		rotation = (rotation + 4) % 4;
		break;
	case Shape::eKeys::ROTATE_COUNTER_CLOCK1_CAMEL_CASE:

		diff_x = 0;
		diff_y = 0;
		rotation--;
		rotation = (rotation + 4) % 4;
		break;
	
	}
	for (int rotations = 0; rotations < ROTATION_SIZE; rotations++)
	{
		for (int points = 0; points < SHAPE_SIZE; points++)
		{
			shape[rotations][points].x += diff_x;
			shape[rotations][points].y += diff_y;
		}
	}

}
void Shape::MoveRightPlayer(Shape::eKeys key)
{
	switch (key)
	{
	case Shape::eKeys::LEFT2:
		diff_x = -1;
		diff_y = 0;

		break;
	case Shape::eKeys::LEFT2_CAMEL_CASE:
		diff_x = -1;
		diff_y = 0;

		break;
	case Shape::eKeys::RIGHT2:
		diff_x = 1;
		diff_y = 0;
		break;
	case Shape::eKeys::RIGHT2_CAMEL_CASE:
		diff_x = 1;
		diff_y = 0;
		break;
	case Shape::eKeys::DROP2:
		diff_x = 0;
		diff_y = 1;

		break;
	case Shape::eKeys::DROP2_CAMEL_CASE:
		diff_x = 0;
		diff_y = 1;

		break;
	case Shape::eKeys::ROTATE_COLCK2:

		diff_x = 0;
		diff_y = 0;
		rotation = (++rotation) % 4;

		break;
	case Shape::eKeys::ROTATE_COLCK2_CAMEL_CASE:

		diff_x = 0;
		diff_y = 0;
		rotation = (++rotation) % 4;

		break;
	case Shape::eKeys::ROTATE_COUNTER_CLOCK2:

		diff_x = 0;
		diff_y = 0;
		rotation--;
		rotation = (rotation + 4) % 4;
		break;
	case Shape::eKeys::ROTATE_COUNTER_CLOCK2_CAMEL_CASE:

		diff_x = 0;
		diff_y = 0;
		rotation--;
		rotation = (rotation + 4) % 4;
		break;
	}

		for (int rotations = 0; rotations < ROTATION_SIZE; rotations++)
		{
			for (int points = 0; points < SHAPE_SIZE; points++)
			{
				shape[rotations][points].x += diff_x;
				shape[rotations][points].y += diff_y;
			}
		}
}

void Shape:: drawShape(char ch)
{
	int middleOfTheScreen = 0;
	if (this->player == LEFT_PLAYER)
		middleOfTheScreen = MIDDLE_SCREEN_LEFT_PLAYER;
	else
		middleOfTheScreen = MIDDLE_SCREEN_RIGHT_PLAYER;

	for (int i = 0; i < 4; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), this->backColor);
		gotoxy(this->shape[rotation][i].x + middleOfTheScreen, this->shape[rotation][i].y+1);
		cout << ch << endl;		
	}
	
	
}
void Shape:: moveShapeDown()
{
	for (int i = 0; i < SHAPE_SIZE; i++)
	{
		for (int j = 0; j < SHAPE_SIZE; j++)
		{
			shape[i][j].y++;
		}
	}
}


