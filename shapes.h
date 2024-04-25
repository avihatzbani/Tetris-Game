#pragma once
#include "shape.h"
#include "point.h"


class shapes
{
	static constexpr int SHAPE_SIZE = 4;
	static constexpr int ROTATE_ELEMENTS_SIZE = 4;
	static constexpr int NO_COLORS = 20;
	static constexpr int COLORS = 30;

public:
	enum class colors {
		BLUE = 1, GREEN = 2, RED = 4, YELLOW = 5, PURPPLE = 6, AQUA = 3, LIGHT_BLUE = 9
	};

	void randShape(Shape& shape, int GameColor);
	Point** copyShape(Point shape[][SHAPE_SIZE]);

	Point SQUAR_SHAPE[ROTATE_ELEMENTS_SIZE][SHAPE_SIZE] =
	{ {Point(0,0) , Point(1,0) , Point(0,1) , Point(1,1)},
	{Point(0,0) , Point(1,0) , Point(0,1) , Point(1,1)} ,
	{Point(0,0) , Point(1,0) , Point(0,1) , Point(1,1)} ,
	{Point(0,0) , Point(1,0) , Point(0,1) , Point(1,1)} };

	Point L_RIGHT_SHAPE[ROTATE_ELEMENTS_SIZE][SHAPE_SIZE] =
	{ {Point(0,0) , Point(0,1) , Point(0,2) , Point(1,2)}, // 0
	{Point(0,0) , Point(1,0) , Point(2,0) , Point(0,1)}, // 90
	{Point(0,0) , Point(1,0) , Point(1,1) , Point(1,2)}, // 180
	{Point(2,0) , Point(0,1) , Point(1,1) , Point(2,1)} }; // 270

	Point L_LEFT_SHAPE[ROTATE_ELEMENTS_SIZE][SHAPE_SIZE] =
	{ {Point(1,0) , Point(1,1) , Point(1,2) , Point(0,2)}, // 0
	{Point(0,0) , Point(0,1) , Point(1,1) , Point(2,1)}, // 90
	{Point(0,0) , Point(1,0) , Point(0,1) , Point(0,2)}, // 180
	{Point(0,0) , Point(1,0) , Point(2,0) , Point(2,1)} }; // 270

	Point PLUS_SHAPE[ROTATE_ELEMENTS_SIZE][SHAPE_SIZE] =
	{ {Point(0,0) , Point(1,0) , Point(2,0) , Point(1,1)}, // 0
	{Point(1,0) , Point(0,1) , Point(1,1) , Point(1,2)}, // 90
	{Point(1,0) , Point(0,1) , Point(1,1) , Point(2,1)}, // 180
	{Point(0,0) , Point(0,1) , Point(1,1) , Point(0,2)} }; // 270

	Point Z_SHAPE[ROTATE_ELEMENTS_SIZE][SHAPE_SIZE] =
	{ {Point(0,0) , Point(1,0) , Point(1,1) , Point(2,1)}, // 0
	{Point(1,0) , Point(0,1) , Point(1,1) , Point(0,2)} ,// 90
	{Point(0,0) , Point(1,0) , Point(1,1) , Point(2,1)}, // 180
	{Point(1,0) , Point(0,1) , Point(1,1) , Point(0,2)} };// 270

	Point S_SHAPE[ROTATE_ELEMENTS_SIZE][SHAPE_SIZE] =
	{ {Point(1,0) , Point(2,0) , Point(0,1) , Point(1,1)}, //0 
	{Point(0,0) , Point(0,1) , Point(1,1) , Point(1,2)} , // 90
	{Point(1,0) , Point(2,0) , Point(0,1) , Point(1,1) }, // 180
	{ Point(0,0) , Point(0,1) , Point(1,1) , Point(1,2) } }; // 270

	Point LINE_SHAPE[ROTATE_ELEMENTS_SIZE][SHAPE_SIZE] =
	{ {Point(0,0) , Point(0,1) , Point(0,2) , Point(0,3)}, //0
	{Point(0,0) , Point(1,0) , Point(2,0) , Point(3,0)} , // 90
	{Point(0,0) , Point(0,1) , Point(0,2) , Point(0,3)}, // 180
	{Point(0,0) , Point(1,0) , Point(2,0) , Point(3,0)} }; // 270

};
