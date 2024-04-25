#include "shapes.h"
#include "Shape.h"
#include <iostream>
#include <cstdlib>
#include <ctime>    // Include for time

using namespace std;

//function for copying the shape that got chosen from shapes, where all the shapes are stored, to "shape" class that is usineg as the current shape that is playing
Point** shapes::copyShape(Point shape[][SHAPE_SIZE])
{
	Point** chosenShape;

	chosenShape = new Point * [ROTATE_ELEMENTS_SIZE];

	for (int i = 0; i < ROTATE_ELEMENTS_SIZE; i++)
	{
		chosenShape[i] = new Point[SHAPE_SIZE];

		for (int j = 0; j < SHAPE_SIZE; j++)
		{
			chosenShape[i][j] = shape[i][j];
		}
	}
	return chosenShape;
}

// for choosing a random shape for shpaes class that contains all the shapes in tetris 
void shapes::randShape(Shape& shape , int GameColor)
{
	int currShape = rand() % 7;
	
	Point** chosenShape;
	// for plating with color
	if (GameColor == COLORS)
	{
		switch (currShape)
		{

		case 0:
			chosenShape = this->copyShape(SQUAR_SHAPE);
			shape.init(chosenShape, (int)shapes::colors::BLUE, 0, 0, 0);
			break;
		case 1:
			chosenShape = this->copyShape(L_RIGHT_SHAPE);
			shape.init(chosenShape, (int)shapes::colors::GREEN, 0, 0, 0);
			break;
		case 2:
			chosenShape = this->copyShape(L_LEFT_SHAPE);
			shape.init(chosenShape, (int)shapes::colors::RED, 0, 0, 0);
			break;
		case 3:
			chosenShape = this->copyShape(PLUS_SHAPE);
			shape.init(chosenShape, (int)shapes::colors::PURPPLE, 0, 0, 0);
			break;
		case 4:
			chosenShape = this->copyShape(S_SHAPE);
			shape.init(chosenShape, (int)shapes::colors::AQUA, 0, 0, 0);
			break;
		case 5:
			chosenShape = this->copyShape(Z_SHAPE);
			shape.init(chosenShape, (int)shapes::colors::YELLOW, 0, 0, 0);
			break;
		case 6:
			chosenShape = this->copyShape(LINE_SHAPE);
			shape.init(chosenShape, (int)shapes::colors::LIGHT_BLUE, 0, 0, 0);

		}
	}

	// for playing with out colors

	if (GameColor == NO_COLORS)
	{
		{
			switch (currShape)
			{

			case 0:
				chosenShape = this->copyShape(SQUAR_SHAPE);
				shape.init(chosenShape,(int)RGB(255, 255, 255), 0, 0, 0);
				break;
			case 1:
				chosenShape = this->copyShape(L_RIGHT_SHAPE);
				shape.init(chosenShape, (int)RGB(255, 255, 255), 0, 0, 0);
				break;
			case 2:
				chosenShape = this->copyShape(L_LEFT_SHAPE);
				shape.init(chosenShape, (int)RGB(255, 255, 255), 0, 0, 0);
				break;
			case 3:
				chosenShape = this->copyShape(PLUS_SHAPE);
				shape.init(chosenShape, (int)RGB(255, 255, 255), 0, 0, 0);
				break;
			case 4:
				chosenShape = this->copyShape(S_SHAPE);
				shape.init(chosenShape, (int)RGB(255, 255, 255), 0, 0, 0);
				break;
			case 5:
				chosenShape = this->copyShape(Z_SHAPE);
				shape.init(chosenShape, (int)RGB(255, 255, 255), 0, 0, 0);
				break;
			case 6:
				chosenShape = this->copyShape(LINE_SHAPE);
				shape.init(chosenShape, (int)RGB(255, 255, 255), 0, 0, 0);

			}
		}
	}
}

