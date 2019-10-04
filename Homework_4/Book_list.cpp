// Name: Yiming Bi
// This is the book list program of HW4

#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

// some functions to be used
bool Full_Check(const vector<int>& list);
bool Empty_Check(const vector<int>& list);
bool Sorted_Check(const vector<int>& list);
void Insert_End(vector<int>& list, int new_book);
void Insert_Position(vector<int>& list, int new_book, unsigned int position);
int Linear_Search(const vector<int>& list, int aim_ISBN);
int Binary_Search(const vector<int>& list, int aim_ISBN);
void Delete_Position(vector<int>& list, unsigned int position);
void Selection_Sort(vector<int>& list);
void Bubble_Sort(vector<int>& list);
void Remove_Space(vector<int>& list);
void Print_List(const vector<int>& list);

int main() {
	// initialization
	int menu_user_choice = 0;
	vector<int> book_list(20, 0);

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
			list_full = Full_Check(book_list);
			if (list_full == 1) {
				cout << "The list is full! Try delete first!\n\n";
				continue;
			}
			// ask input
			cout << "Please enter new book ISBN to insert at the end:\n";
			int new_book_ISBN = 0;
			cin >> new_book_ISBN;
			// check if the new ISBN already existed, if so, delete the existed one
			int new_book_position = Linear_Search(book_list, new_book_ISBN);
			if (new_book_position != 0) {
				Delete_Position(book_list, new_book_position);
				Remove_Space(book_list);
			}
			// actually insert and print
			Insert_End(book_list, new_book_ISBN);
			Print_List(book_list);
			continue;
		}

		case 2:	// insert at certain position
		{
			// check if the list is full
			bool list_full = 0;
			list_full = Full_Check(book_list);
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
			int new_book_position = Linear_Search(book_list, new_book_ISBN);
			if (new_book_position != 0) {
				Delete_Position(book_list, new_book_position);
				Remove_Space(book_list);
			}
			cout << "Please enter new book position:\n";
			cin >> insert_position;
			// position check, avoid too big or negative position
			if ((insert_position < 0) || (insert_position > book_list.size())) {
				cout << "Invaild position!\n";
				continue;
			}
			// actually insert and print
			Insert_Position(book_list, new_book_ISBN, insert_position);
			Remove_Space(book_list);
			Print_List(book_list);
			continue;
		}

		case 3:	// linear search
		{
			// check if the list is empty, if so, search meaningless
			bool list_empty = 0;
			list_empty = Empty_Check(book_list);
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
			position = Linear_Search(book_list, aim_ISBN);
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
			list_empty = Empty_Check(book_list);
			if (list_empty == 1) {
				cout << "The list is empty! Try insert first!\n\n";
				continue;
			}
			// sorted check
			bool list_sorted = 0;
			list_sorted = Sorted_Check(book_list);
			if (list_sorted == 0) {
				cout << "The list is not sorted! Try sorted first!\n\n";
				continue;
			}
			// input check
			cout << "Please enter the ISBN you want to find:\n";
			int aim_ISBN = 0;
			cin >> aim_ISBN;
			if (aim_ISBN <= 0) {
				cout << "ISBN number needs to be positive!\n\n";
				continue;
			}
			// get position and print out
			int position = 0;
			position = Binary_Search(book_list, aim_ISBN);
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
			list_empty = Empty_Check(book_list);
			if (list_empty == 1) {
				cout << "The list is empty! Try insert first!\n\n";
				continue;
			}
			// ask input
			cout << "Please enter the position to delete at the position:\n";
			unsigned int delete_position = 0;
			cin >> delete_position;
			// position check, avoid too big or negative position
			if ((delete_position < 0) || (delete_position > book_list.size())) {
				cout << "Invaild position!\n";
				continue;
			}			
			Delete_Position(book_list, delete_position);	// delete!
			// move up after deleting
			Remove_Space(book_list);
			Print_List(book_list);
			continue;
		}

		case 6:	// delete by ISBN
		{
			// empty check first
			bool list_empty = 0;
			list_empty = Empty_Check(book_list);
			if (list_empty == 1) {
				cout << "The list is empty! Try insert first!\n\n";
				continue;
			}
			// ask ISBN, search by it, then delete by position from search result
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
			// move up after deleting
			Remove_Space(book_list);
			Print_List(book_list);
			continue;
		}

		case 7:	// selection sort
		{
			// empty check
			bool list_empty = 0;
			list_empty = Empty_Check(book_list);
			if (list_empty == 1) {
				cout << "The list is empty! Try insert first!\n\n";
				continue;
			}
			Selection_Sort(book_list);
			Print_List(book_list);
			continue;
		}
			

		case 8:	// bubble sort
		{
			// empty check
			bool list_empty = 0;
			list_empty = Empty_Check(book_list);
			if (list_empty == 1) {
				cout << "The list is empty! Try insert first!\n\n";
				continue;
			}
			Bubble_Sort(book_list);
			Print_List(book_list);
			continue;
		}

		case 9: 
		{
			Print_List(book_list);
			continue;
		}

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
	// traverse the vector for non-zero elements,if there are certain number of non-zero elements,
	// return true, otherwise return false
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
	// traverse the vector for non-zero elements,if there are no non-zero elements,
	// return true, otherwise return false
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

bool Sorted_Check(const vector<int>& list)
{
	// traverse the vector for non-zero elements,if each element is smaller than the next one,
	// return true, otherwise return false
	const vector<int>* list_pointer;
	list_pointer = &list;
	for (size_t i = 0; i < list_pointer->size() - 1; i++) {
		if (list_pointer->at(i + 1) == 0) {
			break;
		}
	//	cout << list_pointer->at(i) << " " << list_pointer->at(i + 1) << endl;
		if (list_pointer->at(i) > list_pointer->at(i + 1)) {
			return false;
		}
	}
	return true;
}

void Insert_End(vector<int>& list, int new_book)
{
	// traverse the vector, for the first non-zero position, insert
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
	// if any element at the position, move the rest one position down and insert
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
	// traverse the vector, do compare directly and return position in netural language (start from 1
	const vector<int>* list_pointer;
	list_pointer = &list;
	for (size_t i = 0; i < list_pointer->size(); i++) {
		if (list_pointer->at(i) == 0) {
			break;
		}
		if (list_pointer->at(i) == aim_ISBN) {
			return i + 1;
		}
	}
	return 0;
}

int Binary_Search(const vector<int>& list, int aim_ISBN)
{
	// search the sorted vector using the algorithm
	const vector<int>* list_pointer;
	list_pointer = &list;
	size_t left_position = 0;
	size_t right_position = 0;
	for (size_t i = 0; i < list_pointer->size(); i++) {
		if (list_pointer->at(i) == 0) {
			break;
		}
		right_position = i;
	}
	while (left_position <= right_position) {
		size_t mid_position = (left_position + right_position) / 2;
		if (list_pointer->at(mid_position) < aim_ISBN) {
			left_position = mid_position + 1;
		}
		else if (list_pointer->at(mid_position) > aim_ISBN)
		{
			right_position = mid_position - 1;
		}
		else {
			return mid_position + 1;
		}
	}
	return 0;
}

void Delete_Position(vector<int>& list, unsigned int position)
{
	// replace the ceratin element by 0
	vector<int>* list_pointer;
	list_pointer = &list;
	if (list_pointer->at(position - 1) == 0) {
		cout << "The position is already empty!\n";
	}
	list_pointer->at(position - 1) = 0;
}

void Selection_Sort(vector<int>& list)
{
	// as the algorithm, find the minimun and place it at right position in each loop
	vector<int>* list_pointer;
	list_pointer = &list;
	int min = list_pointer->at(0);
	int swap_temp = 0;
	size_t min_position = 0;
	cout << "Selection sorting...";
	for (size_t i = 0; i < list_pointer->size(); i++) {
		if (list_pointer->at(i) == 0) {
			break;
		}
		min = list_pointer->at(i);
		min_position = i;
		for (size_t j = i; j < list_pointer->size(); j++) {
			if (list_pointer->at(j) == 0) {
				break;
			}
			if (list_pointer->at(j) < min) {
				min = list_pointer->at(j);
				min_position = j;
			}
		}
	//	Print_List(list);
	//	cout << min << " " << min_position << " " << i << endl;
		swap_temp = list_pointer->at(i);
		list_pointer->at(i) = list_pointer->at(min_position);
		list_pointer->at(min_position) = swap_temp;
	}
	cout << "Done!\n";
}

void Bubble_Sort(vector<int>& list)
{
	// as the algorithm, compare and swap, one for loop in the function beacuse another one is in the sorted check function
	vector<int>* list_pointer;
	list_pointer = &list;
	int swap_temp;
	cout << "Bubble sorting...";
	while (!Sorted_Check(list)) {
		for (size_t i = 0; i < list_pointer->size() - 1; i++) {
			if (list_pointer->at(i + 1) == 0) {
				break;
			}
			if (list_pointer->at(i) > list_pointer->at(i + 1)) {
				swap_temp = list_pointer->at(i);
				list_pointer->at(i) = list_pointer->at(i + 1);
				list_pointer->at(i + 1) = swap_temp;
			}
		}
	//	Print_List(list);
	}
	cout << "Done!\n";
}

void Remove_Space(vector<int>& list)
{
	// in loop, for any 0 element, move the next one up
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
	// print all non-zero elements
	cout << "The current book list is:\n";
	const vector<int>* list_pointer;
	list_pointer = &list;
	for (size_t i = 0; i < list_pointer->size(); i++) {
		if (list_pointer->at(i) != 0) {
			cout << setw(3) << i + 1 << ". " << list_pointer->at(i) << endl;
			continue;
		}
		break;
	}
	cout << "Book list ends here!\n" << endl;
}
