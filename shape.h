#pragma once
#include <Windows.h>
#include "point.h"

class Shape
{
private:
	static constexpr int SHAPE_SIZE = 4;
	static constexpr int ROTATE_ELEMENTS_SIZE = 4;
	static constexpr int MIDDLE_SCREEN_LEFT_PLAYER = 5;
	static constexpr int MIDDLE_SCREEN_RIGHT_PLAYER = 12 + 5 + 5;
	static constexpr int LEFT_PLAYER = 0;
	static constexpr int RIGHT_PLAYER = 1;

	Point** shape;
	int player;
	int backColor;
	int diff_x;
	int diff_y;
	int rotation;

public:

	enum class eKeys {
		LEFT1 = 'a', LEFT1_CAMEL_CASE = 'A', RIGHT1 = 'd', RIGHT1_CAMEL_CASE = 'D', ROTATE_COLCK1 = 's', ROTATE_COLCK1_CAMEL_CASE = 'S', ROTATE_COUNTER_CLOCK1 = 'w', ROTATE_COUNTER_CLOCK1_CAMEL_CASE = 'W', DROP1 = 'x', DROP1_CAMEL_CASE = 'X', LEFT2 = 'j', LEFT2_CAMEL_CASE = 'J', RIGHT2 = 'l', RIGHT2_CAMEL_CASE = 'L', ROTATE_COLCK2 = 'k', ROTATE_COLCK2_CAMEL_CASE = 'K', ROTATE_COUNTER_CLOCK2 = 'i', ROTATE_COUNTER_CLOCK2_CAMEL_CASE = 'I', DROP2 = 'm', DROP2_CAMEL_CASE = 'M'
	};

	Shape() :backColor(0), diff_x(0), diff_y(0), rotation(0), player(0)
	{
		shape = new Point * [ROTATE_ELEMENTS_SIZE];

		for (int j = 0; j < ROTATE_ELEMENTS_SIZE; j++)
		{
			shape[j] = new Point[SHAPE_SIZE];
		}
	};
	~Shape()
	{
		// Deallocate memory for the shape
		for (int j = 0; j < ROTATE_ELEMENTS_SIZE; j++)
		{
			delete[] shape[j];
		}
		delete[] shape;
	};

	Point** getShapeCordinates();
	int getRotation();
	int getColor();
	void init(Point** shape, int backColor, int diff_x, int diff_y, int rotation);
	void initPlayer(int player);
	int getPlayer();
	void MoveLeftPlayer(Shape::eKeys key);
	void MoveRightPlayer(Shape::eKeys key);
	void moveShapeDown();
	void drawShape(char ch);

};



