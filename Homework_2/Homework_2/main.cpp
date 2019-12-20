// Name: Yiming Bi
// This is the program of 503 homework 2, estmate Pi value

#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<fstream>

using namespace std;

int main() {

	// initialization
	double x, y, est_pi;	// they are float numbers between 0 and 1
	int hit, point_number;	// how many points are in the cicle and the total number of points
	point_number = 10000;
	hit = 0;

	srand(time(0));

	ofstream file;
	file.open("results.txt");

	// process
	for (int i = 0; i < point_number; i++) {
		x = rand() / double(RAND_MAX);	y = rand() / double(RAND_MAX);

		file << x << "," << y << endl;
		if (x * x + y * y < 1) {
			hit++;
		}
		// random x and y to get a point, write x and y values into results.txt
		// if the norm-2 of x and y smaller than 1, this point falls in the cicle
	}

	est_pi = (double(hit) / double(point_number)) * 4;
	cout << "The estimated Pi from this program is: " << est_pi << endl;

	return 0;
}