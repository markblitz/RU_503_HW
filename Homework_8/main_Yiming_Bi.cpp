#include<iostream>

using namespace std;

#include "Circle_Yiming_Bi.h"

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
			A.Set_radius(input_radius);
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
