#include "ThreeD_Shape_Yiming_Bi.h"
#include <iostream>
using namespace std;

void ThreeD_Shape::Set_Z(double input_z)
{
	center_z = input_z;
}

double ThreeD_Shape::Get_Z() const
{
	return center_z;
}

void ThreeD_Shape::Print_Center() const
{
	cout << "(" << Get_X() << "," << Get_Y() << "," << Get_Z() << ")";
}
