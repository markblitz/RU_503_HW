#include <iostream>

using namespace std;

#include "Shape_Yiming_Bi.h"

Shape::Shape()
{
	Set_X(0);
	Set_Y(0);
}

Shape::~Shape()
{
	// nothing I may do here...
}

void Shape::Set_X(double input_x)
{
	center_x = input_x;
}

void Shape::Set_Y(double input_y)
{
	center_y = input_y;
}

double Shape::Get_X() const
{
	return center_x;
}

double Shape::Get_Y() const
{
	return center_y;
}

void Shape::Print_Center() const
{
	cout << "(" << Get_X() << "," << Get_Y() << ")";
}
