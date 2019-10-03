// Name: Yiming Bi
// This is the book list program of HW4

#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

bool Full_Check(const vector<int>& list);
bool Empty_Check(const vector<int>& list);
void Insert_End(vector<int>& list, int new_book);
void Insert_Position(vector<int>& list, int new_book, unsigned int position);
int Linear_Search(const vector<int>& list, int aim_ISBN);

void Delete_Position(vector<int>& list, unsigned int position);

void Remove_Space(vector<int>& list);
void Print_List(const vector<int>& list);

int main() {
	// initialization
	int menu_user_choice = 0;
	vector<int> book_list(7, 0);

	// ask user choice in huge loop
	while (true) {
		cout << "Welcome to the Book list program.\n" << "What would you like to do?\n";
		cout << "	1. add an element to the end of list\n" << "	2. edd an element at a loction\n";
		cout << "	3. find an element by ISBN number (linear search)\n" << "	4. fina an element by ISBN number (binary search)\n";
		cout << "	5. delete an element at position\n" << "	6. delete an element by ISBN number\n";
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
			unsigned int insert_position = 0;
			cin >> new_book_ISBN >> insert_position;
			// position check, avoid too big or negative position
			if ((insert_position < 0) || (insert_position > book_list.size())) {
				cout << "Invaild position!\n";
				continue;
			}
			Insert_Position(book_list, new_book_ISBN, insert_position);
			Remove_Space(book_list);
			Print_List(book_list);
			continue;
		}

		case 3:
		{
			cout << "Please enter the ISBN you want to find:\n";
			int aim_ISBN = 0;
			cin >> aim_ISBN;
			int position = 0;
			position = Linear_Search(book_list, aim_ISBN);
			if (position == 0) {
				cout << "The ISBN number may not be in the list!\n\n";
				continue;
			}
			cout << "The ISBN number " << aim_ISBN << " you are looking for is at position " << position << endl << endl;
		}
			continue;

		case 4:
			cout << "input " << menu_user_choice << endl;
			continue;

		case 5:
		{
			bool list_empty = 0;
			list_empty = Empty_Check(book_list);
			if (list_empty == 1) {
				cout << "The list is empty! Try insert first!\n\n";
				continue;
			}

			cout << "Please enter the position to delete at the position:\n";
			unsigned int delete_position = 0;
			cin >> delete_position;
			// position check, avoid too big or negative position
			if ((delete_position < 0) || (delete_position > book_list.size())) {
				cout << "Invaild position!\n";
				continue;
			}
			Delete_Position(book_list, delete_position);
			Remove_Space(book_list);
			Print_List(book_list);
			continue;
		}
			continue;

		case 6:
		{
			bool list_empty = 0;
			list_empty = Empty_Check(book_list);
			if (list_empty == 1) {
				cout << "The list is empty! Try insert first!\n\n";
				continue;
			}

			cout << "Please enter the ISBN you want to delete:\n";
			int aim_ISBN = 0;
			cin >> aim_ISBN;
			int position = 0;
			position = Linear_Search(book_list, aim_ISBN);
			if (position == 0) {
				cout << "The ISBN number may not be in the list!\n\n";
				continue;
			}
			Delete_Position(book_list, position);
			Remove_Space(book_list);
			Print_List(book_list);
		}
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
	const vector<int>* list_pointer;
	list_pointer = &list;
	size_t i = 0;
	while (true) {
		//cout << i << "  " << list_pointer->size() << endl;
		if (i == list_pointer->size()) {			
			return true;
		}
		if (list_pointer->at(i) != 0) {
			i++;
			continue;
		}
		return false;
	}
}

bool Empty_Check(const vector<int>& list)
{
	const vector<int>* list_pointer;
	list_pointer = &list;
	size_t i = 0;
	while (true) {
		//cout << i << "  " << list_pointer->size() << endl;
		if (i == list_pointer->size()) {
			return true;
		}
		if (list_pointer->at(i) == 0) {
			i++;
			continue;
		}
		return false;
	}
}

void Insert_End(vector<int>& list, int new_book)
{
	vector<int>* list_pointer;
	list_pointer = &list;
	for (size_t i = 0; i <= list_pointer->size(); i++) {
		if (list_pointer->at(i) == 0) {
			list_pointer->at(i) = new_book;
			break;
		}	
	}
}

void Insert_Position(vector<int>& list, int new_book, unsigned int position)
{
	vector<int>* list_pointer;
	list_pointer = &list;
	if (list_pointer->at(position - 1) != 0) {
		for (size_t i = list_pointer->size() - 1; i > position - 1; i--) {
			list_pointer->at(i) = list_pointer->at(i - 1);
		}
	}
	list_pointer->at(position - 1) = new_book;
}

int Linear_Search(const vector<int>& list, int aim_ISBN)
{
	const vector<int>* list_pointer;
	list_pointer = &list;
	for (size_t i = 0; i < list_pointer->size(); i++) {
		if (list_pointer->at(i) == aim_ISBN) {
			return i + 1;
		}
	}
	return 0;
}

void Delete_Position(vector<int>& list, unsigned int position)
{
	vector<int>* list_pointer;
	list_pointer = &list;
	if (list_pointer->at(position - 1) == 0) {
		cout << "The position is already empty!\n";
	}
	list_pointer->at(position - 1) = 0;
}

void Remove_Space(vector<int>& list)
{
	vector<int>* list_pointer;
	list_pointer = &list;
	for (size_t i = 0; i < list_pointer->size(); i++) {
		if (list_pointer->at(i) == 0) {
			for (size_t j = i; j < list_pointer->size() - 1; j++) {
				if (list_pointer->at(j + 1) != 0) {
					list_pointer->at(i) = list_pointer->at(j + 1);
					list_pointer->at(j + 1) = 0;
					break;
				}
			}
		}
	}
}

void Print_List(const vector<int>& list)
{
	cout << "The current book list is:\n";
	const vector<int>* list_pointer;
	list_pointer = &list;
	for (size_t i = 0; i < list_pointer->size(); i++) {
		//if (list_pointer->at(i) != 0) {
			cout << setw(3) << i + 1 << ". " << list_pointer->at(i) << endl;
			continue;
		//}
		//break;
	}
	cout << "Book list ends here!\n" << endl;
}
