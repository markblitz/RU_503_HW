// Name: Yiming Bi
// This is the book list program of HW4

#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

bool Full_Check(const vector<int>& list);
void Insert_End(vector<int>& list, int new_book);
void Insert_Position(vector<int>& list, int new_book, int position);

void Print_List(const vector<int>& list);

int main() {
	// initialization
	int menu_user_choice = 0;
	vector<int> book_list(5, 0);

	// ask user choice in huge loop
	while (true) {
		cout << "Welcome to the Book list program.\n" << "What would you like to do?\n";
		cout << "	1. add an element to the end of list\n" << "	2. edd an element at a loction\n";
	//	cout << "	3. find an element by ISBN number (linear search)\n" << "	4. fina an element by ISBN number (binary search)\n";
	//	cout << "	5. delete an element at position\n" << "	6. delete an element by ISBN number\n";
	//	cout << "	7. sort the list (using selection sort)\n" << "	8. sort the list (using bubble sort)\n";
		cout << "	9. print the list\n" << "	10. exit\n" << "your choice ---\n";

		cin >> menu_user_choice;

		switch (menu_user_choice) {
		case 1:
		{
			bool list_full = 0;
			list_full = Full_Check(book_list);
			if (list_full == 1) {
				cout << "The list is full! Try delete first!\n\n";
				continue;
			}

			cout << "Please enter new book ISBN to insert at the end:\n";
			int new_book_ISBN = 0;
			cin >> new_book_ISBN;
			Insert_End(book_list, new_book_ISBN);
			Print_List(book_list);
			continue;
		}

		case 2: 
		{
			bool list_full = 0;
			list_full = Full_Check(book_list);
			if (list_full == 1) {
				cout << "The list is full! Try delete first!\n\n";
				continue;
			}

			cout << "Please enter new book ISBN and position to insert at the position:\n";
			int new_book_ISBN = 0;
			int insert_position = 0;

			continue;
		}

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
			cout << "The current book list is:\n";
			Print_List(book_list);
			continue;

		case 10:
			cout << "Exit\n";
			break;

		default:
			cout << "Invalid input, please try again! \n";			
			continue;
		}

	}

	return 0;
}

bool Full_Check(const vector<int>& list)
{
	const vector<int>* book_list_pointer;
	book_list_pointer = &list;
	size_t i = 0;
	while (true) {
		//cout << i << "  " << book_list_pointer->size() << endl;
		if (i == book_list_pointer->size()) {			
			return true;
		}
		if (book_list_pointer->at(i) != 0) {
			i++;
			continue;
		}
		return false;
	}
}

void Insert_End(vector<int>& list, int new_book)
{
	vector<int>* book_list_pointer;
	book_list_pointer = &list;
	for (size_t i = 0; i <= book_list_pointer->size(); i++) {
		if (book_list_pointer->at(i) == 0) {
			book_list_pointer->at(i) = new_book;
			break;
		}	
	}
}

void Insert_Position(vector<int>& list, int new_book, int position)
{
	vector<int>* book_list_pointer;
	book_list_pointer = &list;
	book_list_pointer->at(position - 1) = new_book;
}

void Print_List(const vector<int>& list)
{
	cout << "The current book list is:\n";
	const vector<int>* book_list_pointer;
	book_list_pointer = &list;
	for (size_t i = 0; i < book_list_pointer->size(); i++) {
		if (book_list_pointer->at(i) != 0) {
			cout << setw(3) << i + 1 << ". " << book_list_pointer->at(i) << endl;
			continue;
		}
		break;
	}
	cout << "Book list ends here!\n" << endl;
}
