#include<iostream>
using namespace std;
#include "Polynomial_Yiming_Bi.h"

Polynomial::Polynomial()
{
	for (int i = 0; i < 13; i++) {
		inner_array[i] = 0;
	}
}

void Polynomial::Set_Polynomial()
{
	cout << "Enter the number of polynomial trems: ";
	int term_number = 0;
	cin >> term_number;

	for (int i = 0; i < term_number; i++) {
		cout << "Enter coefficient and exponent: ";
		int coefficient, exponent;
		cin >> coefficient >> exponent;
		if ((exponent > 6) || (exponent < 0)) {
			cout << "Invalid exponent number! The latest input line does not count!\n";
			i--;
			continue;
		}
		if (inner_array[exponent] != 0) {
			cout << "This exponent already exists! Input coefficient will be added into the existing degree!\n";
			inner_array[exponent - 1] += coefficient;
			continue;
		}
		inner_array[exponent] = coefficient;
	}
}

Polynomial Polynomial::operator+(const Polynomial& poly)
{
	Polynomial output;
	for (int i = 0; i < 13; i++) {
		output.inner_array[i] = inner_array[i] + poly.inner_array[i];
	}
	return output;
}

Polynomial Polynomial::operator-(const Polynomial& poly)
{
	Polynomial output;
	for (int i = 0; i < 7; i++) {
		output.inner_array[i] = inner_array[i] - poly.inner_array[i];
	}
	return output;
}

Polynomial Polynomial::operator=(const Polynomial& poly)
{
	Polynomial output;
	for (int i = 0; i < 7; i++) {
		output.inner_array[i] = poly.inner_array[i];
	}
	return output;
}

ostream& operator<<(ostream& output, const Polynomial& poly)
{
	int print_counter = 0;
	for (int i = 0; i < 13; i++) {
		if (poly.inner_array[i] != 0) {
			print_counter++;
		}
	}

	if (print_counter == 0) {
		cout << "0\n";
	}
	else {
		for (int i = 0; i < 13; i++) {
			if (poly.inner_array[i] != 0) {
				output << poly.inner_array[i];
				print_counter--;
				if (i == 0) {
					cout << "x";
					if (print_counter == 0) { cout << endl; }
					else { cout << " + "; }
				}
				else {
					cout << "x^" << i;
					if (print_counter == 0) { cout << endl; }
					else { cout << " + "; }
				}
			}
		}
	}
	return output;
}
