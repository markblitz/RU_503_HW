#include "Tetrahedron_Yiming_Bi.h"
#include <iostream>
using namespace std;

Tetrahedron::Tetrahedron()
{
	Set_X(0);	Set_Y(0);	Set_Z(0);	Set_Edge(0);
}

Tetrahedron::~Tetrahedron()
{
	// ...
}

void Tetrahedron::Set_Edge(double input_edge)
{
	edge = input_edge;
}

double Tetrahedron::Get_Edge() const
{
	return edge;
}

double Tetrahedron::Get_Area() const
{
	return sqrt(3) * Get_Edge() * Get_Edge();
}

double Tetrahedron::Get_Volume() const
{
	return sqrt(2) * Get_Edge() * Get_Edge() * Get_Edge() /12;
}

void Tetrahedron::Print()
{
	cout << "The tetrahedron with edge length " << Get_Edge() << " at location";
	Print_Center();
	cout << "has:\n" << "Surface area of " << Get_Area() << endl << "Volume of " << Get_Volume() << endl << endl;
}
