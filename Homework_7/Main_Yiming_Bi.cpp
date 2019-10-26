#include<iostream>
using namespace std;

#include "Polynomial_Yiming_Bi.h"

int main() {

	Polynomial poly1;
	Polynomial poly2;
	poly1.Set_Polynomial();
	poly2.Set_Polynomial();

	cout << "poly1: " << poly1 << endl;
	cout << "poly2: " << poly2 << endl;

	Polynomial add_result;
	add_result = poly1 + poly2;

	cout << "add result: " << add_result << endl;

	return 0;
}