#include"Booklist_Bi.h"

int main() {
	// initialization
	int menu_user_choice = 0;
	Booklist booklist;

	// ask user choice in huge loop
	while (true) {
		cout << "Welcome to the Book list program.\n" << "What would you like to do?\n";
		cout << "	1. add an element to the end of list\n" << "	2. edd an element at a loction\n";
		cout << "	3. find an element by ISBN number (linear search)\n" << "	4. find an element by ISBN number (binary search)\n";
		cout << "	5. delete an element at position\n" << "	6. delete an element by ISBN number\n";
		cout << "	7. sort the list (using selection sort)\n" << "	8. sort the list (using bubble sort)\n";
		cout << "	9. print the list\n" << "	10. exit\n" << "your choice ---\n";

		cin >> menu_user_choice;

		switch (menu_user_choice) {
		case 1:	// insert at the end
		{
			// check if the list is full, if so, stop inserting
			bool list_full = 0;
			list_full = booklist.Full_Check();
			if (list_full == 1) {
				cout << "The list is full! Try delete first!\n\n";
				continue;
			}
			// ask input
			cout << "Please enter new book ISBN to insert at the end:\n";
			int new_book_ISBN = 0;
			cin >> new_book_ISBN;
			// check if the new ISBN already existed, if so, delete the existed one

			// actually insert and print
			booklist.Insert_End(new_book_ISBN);
			booklist.Print();
			continue;
		}
		
		case 2:	// insert at certain position
		{
			// check if the list is full
			bool list_full = 0;
			list_full = booklist.Full_Check();
			if (list_full == 1) {
				cout << "The list is full! Try delete first!\n\n";
				continue;
			}
			// ask input
			cout << "Please enter new book ISBN to insert:\n";
			int new_book_ISBN = 0;
			unsigned int insert_position = 0;
			cin >> new_book_ISBN;
			// check if the new ISBN already existed, if so, delete the existed one

			// ask position input
			cout << "Please enter new book position:\n";
			cin >> insert_position;
			// position check, avoid too big or negative position
			if ((insert_position < 0) || (insert_position > 20)) {
				cout << "Invaild position!\n";
				continue;
			}
			// actually insert and print
			booklist.Insert_Position(new_book_ISBN, insert_position);
			booklist.Remove_Space();
			booklist.Print();
			continue;
		}
		
		case 3:	// linear search
		{
			// check if the list is empty, if so, search meaningless
			bool list_empty = 0;
			list_empty = booklist.Empty_Check();
			if (list_empty == 1) {
				cout << "The list is empty! Try insert first!\n\n";
				continue;
			}
			cout << "Please enter the ISBN you want to find:\n";
			int aim_ISBN = 0;
			cin >> aim_ISBN;
			// input check to avoid potential error
			if (aim_ISBN <= 0) {
				cout << "ISBN number needs to be positive!\n\n";
				continue;
			}
			int position = 0;
			// do the easrch and get position
			position = booklist.Linear_Search(aim_ISBN);
			if (position == 0) {	// not in the list
				cout << "The ISBN number may not be in the list!\n\n";
				continue;
			}
			// in the list at certain position
			cout << "The ISBN number " << aim_ISBN << " you are looking for is at position " << position << endl << endl;
			continue;
		}

		case 4:	// binary search
		{
			// empty check
			bool list_empty = 0;
			list_empty = booklist.Empty_Check();
			if (list_empty == 1) {
				cout << "The list is empty! Try insert first!\n\n";
				continue;
			}
			// sorted check
			bool list_sorted = 0;
			list_sorted = booklist.Sorted_Check();
			if (list_sorted == 0) {
				cout << "The list is not sorted! Try sorted first!\n\n";
				continue;
			}
			// ask input
			cout << "Please enter the ISBN you want to find:\n";
			int aim_ISBN = 0;
			cin >> aim_ISBN;
			// get position and print out
			int position = 0;
			position = booklist.Binary_Search(aim_ISBN);
			if (position == 0) {
				cout << "The ISBN number may not be in the list!\n\n";
				continue;
			}
			cout << "The ISBN number " << aim_ISBN << " you are looking for is at position " << position << endl << endl;
			continue;
		}

		case 5:	// delete by position
		{
			// empty check
			bool list_empty = 0;
			list_empty = booklist.Empty_Check();
			if (list_empty == 1) {
				cout << "The list is empty! Try insert first!\n\n";
				continue;
			}
			// ask input
			cout << "Please enter the position to delete at the position:\n";
			unsigned int delete_position = 0;
			cin >> delete_position;
			// position check, avoid too big or negative position
			if ((delete_position < 0) || (delete_position > 20)) {
				cout << "Invaild position!\n";
				continue;
			}
			booklist.Delete_Position(delete_position);	// delete!
			// move up after deleting
			booklist.Remove_Space();
			booklist.Print();
			continue;
		}

		case 6:	// delete by ISBN
		{
			// empty check first
			bool list_empty = 0;
			list_empty = booklist.Empty_Check();
			if (list_empty == 1) {
				cout << "The list is empty! Try insert first!\n\n";
				continue;
			}
			// ask ISBN, search by it, then delete by position from search result
			cout << "Please enter the ISBN you want to delete:\n";
			int aim_ISBN = 0;
			cin >> aim_ISBN;
			int position = 0;
			position = booklist.Linear_Search(aim_ISBN);
			if (position == 0) {
				cout << "The ISBN number may not be in the list!\n\n";
				continue;
			}
			booklist.Delete_Position(position);
			// move up after deleting
			booklist.Remove_Space();
			booklist.Print();
			continue;
		}

		case 7:	// selection sort
		{
			// empty check
			bool list_empty = 0;
			list_empty = booklist.Empty_Check();
			if (list_empty == 1) {
				cout << "The list is empty! Try insert first!\n\n";
				continue;
			}
			booklist.Selection_Sort();
			booklist.Print();
			continue;
		}


		case 8:	// bubble sort
		{
			// empty check
			bool list_empty = 0;
			list_empty = booklist.Empty_Check();
			if (list_empty == 1) {
				cout << "The list is empty! Try insert first!\n\n";
				continue;
			}
			booklist.Bubble_Sort();
			booklist.Print();
			continue;
		}

		case 9:
		{
			booklist.Print();
			continue;
		}

		case 10:
			cout << "Exit\n";
			return 0;

		default:
			cout << "Invalid input, please try again! \n";
			continue;
		}

	}

	return 0;
}