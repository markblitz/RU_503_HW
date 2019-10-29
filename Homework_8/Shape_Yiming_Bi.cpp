#include "Shape_Yiming_Bi.h"

Shape::Shape(int& input_x, int& input_y)
{
	center_x = input_x;
	center_y = input_y;
}

Shape::~Shape()
{
	// nothing I may do here...
}

void Shape::Set_X(int& input_x)
{
	center_x = input_x;
}

void Shape::Set_Y(int& input_y)
{
	center_y = input_y;
}

int Shape::Get_X()
{
	return center_x;
}

int Shape::Get_Y()
{
	return center_y;
}
