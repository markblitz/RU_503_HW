// Name: Yiming Bi
// This is the program for hw5 question1

#include<iostream>

using namespace std;

void Print_Squares(int n);
int Ask_Input();

void Print_Squares(int n)
{
	if (n % 2 == 0) {	// if input is even, call next round first and print n*n
		Print_Squares(n - 1);
		cout << ", " << n * n;
	}

	if ((n % 2 != 0) & (n > 1)) {	// if input is odd, print n*n first then call next round
		cout << n * n << ", ";		// end condition n = 1 should be removed
		Print_Squares(n - 1);
	}


	if (n == 1) {	// end condition
		cout << n;
	}

}

int Ask_Input()
{
	cout << "Please enter a positive integer: ";
	int inpt_integer = 0;
	cin >> inpt_integer;
	return inpt_integer;
}

int main() {

	Print_Squares(Ask_Input());

	return 0;
}

