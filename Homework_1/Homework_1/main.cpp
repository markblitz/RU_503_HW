// name: Yiming Bi
// This is homework 1 of 16:332:503, programming finance

#include <iostream>
#include <iomanip>
using namespace std;

int main() {

	// initialization
	int input_number = 5;
	float user_input, input_max, input_min;
	cout << "Please enter " << input_number << " numbers, one at a time using enter key. \n";
	cin >> user_input;
	cout << "You input is: " << user_input << endl << endl;
	input_max = user_input;	input_min = user_input;

	// loop starts at the second input
	for (int i = 1; i < input_number; i++) {
		cout << "You still have " << input_number - i << " number(s) to go, please enter your next number: \n";
		cin >> user_input;
		cout << "You input is: " << user_input << endl << endl;

		// compare within each loop
		if (user_input > input_max) {
			input_max = user_input;
		}
		if (user_input < input_min) {
			input_min = user_input;
		}
	}

	// give outputs
	cout << "You have entered " << input_number << " numbers. \n";
	cout << "The maximun of your inputs is: " << input_max << endl;
	cout << "The minimun of your inputs is: " << input_min << endl;

	return 0;
}