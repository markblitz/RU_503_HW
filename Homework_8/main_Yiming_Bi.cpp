#include<iostream>

using namespace std;

#include "Circle_Yiming_Bi.h"
#include "Triangle_Yiming_Bi.h"
#include "Sphere_Yiming_Bi.h"
#include "Tetrahedron_Yiming_Bi.h"

int main() {

	int user_choice = 0;

	while (true) {
		cout << "Please choose a shape or 0 to exit:\n" << "1. Circle\n" << "2. Triangle\n"
			<< "3. Sphere\n" << "4. Regular Tetrahedron\n" << "0. Exit\n" << "Choice: ";
		cin >> user_choice;
		cout << endl;

		switch (user_choice) {

		case 1:
		{
			Circle A;
			cout << "You have chosen the circle.\n" << endl;
			cout << "Please enter the center of the circle (x-coordinate and then y-coordinate):\n";
			double input_x, input_y;
			cin >> input_x >> input_y;
			A.Set_X(input_x);
			A.Set_Y(input_y);
			cout <<endl << "Please enter the radius of the circle:\n";
			double input_radius;
			cin >> input_radius;
			A.Set_Radius(input_radius);
			cout << endl;
			A.Print();
			continue;
		}

		case 2:
		{
			Triangle A;
			cout << "You have chosen the triangle.\n" << endl;
			cout << "Please enter the center of the triangle (x-coordinate and then y-coordinate):\n";
			double input_x, input_y;
			cin >> input_x >> input_y;
			A.Set_X(input_x);
			A.Set_Y(input_y);
			cout << endl << "Please enter the edge length of the triangle:\n";
			double input_edge;
			cin >> input_edge;
			A.Set_Edge(input_edge);
			cout << endl;
			A.Print();
			continue;
		}

		case 3:
		{
			Sphere A;
			cout << "You have chosen the sphere.\n" << endl;
			cout << "Please enter the center of the sphere (x-coordinate, y-coordinate, then z-coordinate):\n";
			double input_x, input_y, input_z;
			cin >> input_x >> input_y >> input_z;
			A.Set_X(input_x);
			A.Set_Y(input_y);
			A.Set_Z(input_z);
			cout << endl << "Please enter the radius of the sphere:\n";
			double input_radius;
			cin >> input_radius;
			A.Set_Radius(input_radius);
			cout << endl;
			A.Print();
			continue;
		}

		case 4:
		{
			Tetrahedron A;
			cout << "You have chosen the tetrahedron.\n" << endl;
			cout << "Please enter the center of the tetrahedron (x-coordinate, y-coordinate, then z-coordinate):\n";
			double input_x, input_y, input_z;
			cin >> input_x >> input_y >> input_z;
			A.Set_X(input_x);
			A.Set_Y(input_y);
			A.Set_Z(input_z);
			cout << endl << "Please enter the edge length of the tetrahedron:\n";
			double input_edge;
			cin >> input_edge;
			A.Set_Edge(input_edge);
			cout << endl;
			A.Print();
			continue;
		}

		case 0: 
			cout << "Exit!\n\n";
			break;

		default:
			cout << "Invalid input! Try again!\n\n";
			continue;

		}

		break;

	}

	return 0;
}
