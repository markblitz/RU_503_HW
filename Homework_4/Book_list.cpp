// Name: Yiming Bi
// This is the book list program of HW4

#include<iostream>

using namespace std;

int main() {
	// initialization
	int menu_user_choice = 0;
	// ask user choice in huge loop
	while (true) {
		cout << "Welcome to the Book list program.\n" << "What would you like to do?\n";
		cout << "	1. add an element to the end of list\n" << "	2. edd an element at a loction\n";
		cout << "	3. find an element by ISBN number (linear search)\n" << "	4. fina an element by ISBN number (binary search)\n";
		cout << "	5. delete an element at position\n" << "	6. delete an element by ISBN number\n";
		cout << "	7. sort the list (using selection sort)\n" << "	8. sort the list (using bubble sort)\n";
		cout << "	9. print the list\n" << "	10. exit\n" << "your choice ---\n";

		cin >> menu_user_choice;

		switch (menu_user_choice) {
		case 1:
			cout << "input " << menu_user_choice << endl;
			continue;

		case 2:
			cout << "input " << menu_user_choice << endl;
			continue;

		case 3:
			cout << "input " << menu_user_choice << endl;
			continue;

		case 4:
			cout << "input " << menu_user_choice << endl;
			continue;

		case 5:
			cout << "input " << menu_user_choice << endl;
			continue;

		case 6:
			cout << "input " << menu_user_choice << endl;
			continue;

		case 7:
			cout << "input " << menu_user_choice << endl;
			continue;

		case 8:
			cout << "input " << menu_user_choice << endl;
			continue;

		case 9:
			cout << "input " << menu_user_choice << endl;
			continue;

		case 10:
			cout << "input " << menu_user_choice << endl;
			break;

		default:
			cout << "Invalid input, please try again! \n";			
			continue;
		}

	}

	return 0;
}
