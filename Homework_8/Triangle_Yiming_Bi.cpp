#include "Triangle_Yiming_Bi.h"
#include <iostream>
using namespace std;

Triangle::Triangle()
{
	Set_X(0);	Set_Y(0);	Set_Edge(0);
}

Triangle::~Triangle()
{
	// a simple destructor
}

void Triangle::Set_Edge(double input_edge)
{
	edge = input_edge;
}

double Triangle::Get_Edge() const
{
	return edge;
}

double Triangle::Get_Area() const
{
	return sqrt(3) / 4 * Get_Edge() * Get_Edge();
}

void Triangle::Print() const
{
	cout << "The triangle with edge length " << Get_Edge() << " that is located at ";
	Print_Center();
	cout << " has: \n" << "An area of " << Get_Area() << endl << endl;
}
