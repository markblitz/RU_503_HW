#include<iostream>
using namespace std;

#include "Polynomial_Yiming_Bi.h"

int main() {

	Polynomial poly1;
	Polynomial poly2;
	poly1.Set_Polynomial();	cout << endl;
	poly2.Set_Polynomial();	cout << endl;

	cout << "First polynomial is: " << poly1;
	cout << "Second polynomial is: " << poly2 << endl << endl;

	Polynomial poly_add, poly_sub, poly_mult, result;
	result = poly1 + poly2;
	poly_add = poly1;
	poly_add += poly2;

	cout << "Adding polynomial yields: " << result;
	cout << "+= the polynomial yields: " << poly_add << endl;

	result = poly1 - poly2;
	poly_sub = poly1;
	poly_sub -= poly2;

	cout << "Subtracting polynomial yields: " << result;
	cout << "-= the polynomial yields: " << poly_sub << endl;

	result = poly1 * poly2;
	poly_mult = poly1;
	poly_mult *= poly2;

	cout << "Multiplying polynomials yields: " << result;
	cout << "*= the polynomial yields: " << poly_mult << endl;

	return 0;
}