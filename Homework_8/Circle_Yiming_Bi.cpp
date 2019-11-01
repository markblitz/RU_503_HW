#include<iostream>

using namespace std;

#include "Circle_Yiming_Bi.h"

Circle::Circle()
{
	Set_radius(0);	Set_X(0);	Set_Y(0);
}

Circle::~Circle()
{
}

void Circle::Set_radius(double input_radius)
{
	radius = input_radius;
}

double Circle::Get_radius() const
{
	return radius;
}

double Circle::Get_Area() const
{
	double pi = 3.14159265359;
	return pi * radius * radius;
}

void Circle::Print() const
{
	cout << "The circle with radius " << Get_radius() << " that is located at ";
	Print_Center();
	cout << " has: \n" << "An area of " << Get_Area() << endl << endl;
}
