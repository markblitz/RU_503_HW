#include "Sphere_Yiming_Bi.h"
#include <iostream>
using namespace std;

Sphere::Sphere()
{
	Set_X(0);	Set_Y(0);	Set_Z(0);	Set_Radius(0);
}

Sphere::~Sphere()
{
	// do nothing for now
}

void Sphere::Set_Radius(double input_radius)
{
	radius = input_radius;
}

double Sphere::Get_Radius() const
{
	return radius;
}

double Sphere::Get_Area() const
{
	double pi = 3.14159265359;
	return 4 * pi * Get_Radius() * Get_Radius();
}

double Sphere::Get_Volume() const
{
	double pi = 3.14159265359;
	return 4 * pi * Get_Radius() * Get_Radius() * Get_Radius() / 3;
}

void Sphere::Print()
{
	cout << "The sphere with radius " << Get_Radius() << " at location";
	Print_Center();
	cout << "has:\n" << "Surface area of " << Get_Area() << endl << "Volume of " << Get_Volume() << endl << endl;
}
