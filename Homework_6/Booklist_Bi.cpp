#include"Booklist_Bi.h"

using namespace std;

Booklist::Booklist()
{
	//cout << "Constructing a new booklist!\n";
	book_list_.resize(20);
	//cout << "Construction done!\n";
}

void Booklist::Print()
{
	if (Empty_Check()) {
		cout << "Book list is empty!\n\n";
	}
	// print all non-zero elements
	else {
		cout << "The current book list is:\n";
		const vector<int>* list_pointer;
		list_pointer = &book_list_;
		for (size_t i = 0; i < list_pointer->size(); i++) {
			if (list_pointer->at(i) != 0) {
				cout << setw(3) << i + 1 << ". " << list_pointer->at(i) << endl;
				continue;
			}
			break;
		}
		cout << "Book list ends here!\n" << endl;
	}
}

void Booklist::Remove_Space()
{
	// in loop, for any 0 element, move the next one up
	vector<int>* list_pointer;
	list_pointer = &book_list_;
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

bool Booklist::Full_Check()
{
	// traverse the vector for non-zero elements,if there are certain number of non-zero elements,
	// return true, otherwise return false
	const vector<int>* list_pointer;
	list_pointer = &book_list_;
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

bool Booklist::Empty_Check()
{
	// traverse the vector for non-zero elements,if there are no non-zero elements,
	// return true, otherwise return false
	const vector<int>* list_pointer;
	list_pointer = &book_list_;
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

bool Booklist::Sorted_Check()
{
	// traverse the vector for non-zero elements,if each element is smaller than the next one,
	// return true, otherwise return false
	const vector<int>* list_pointer;
	list_pointer = &book_list_;
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

void Booklist::Insert_End(int new_book)
{
	// traverse the vector, for the first non-zero position, insert
	vector<int>* list_pointer;
	list_pointer = &book_list_;
	for (size_t i = 0; i <= list_pointer->size(); i++) {
		if (list_pointer->at(i) == 0) {
			list_pointer->at(i) = new_book;
			break;
		}
	}
}

void Booklist::Insert_Position(int new_book, unsigned int position)
{
	// if any element at the position, move the rest one position down and insert
	vector<int>* list_pointer;
	list_pointer = &book_list_;
	if (list_pointer->at(position - 1) != 0) {
		for (size_t i = list_pointer->size() - 1; i > position - 1; i--) {
			list_pointer->at(i) = list_pointer->at(i - 1);
		}
	}
	list_pointer->at(position - 1) = new_book;
}

int Booklist::Linear_Search(int aim_ISBN)
{
	// traverse the vector, do compare directly and return position in netural language (start from 1
	const vector<int>* list_pointer;
	list_pointer = &book_list_;
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

int Booklist::Binary_Search(int aim_ISBN)
{
	// search the sorted vector using the algorithm
	const vector<int>* list_pointer;
	list_pointer = &book_list_;
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

void Booklist::Delete_Position(unsigned int position)
{
	// replace the ceratin element by 0
	vector<int>* list_pointer;
	list_pointer = &book_list_;
	if (list_pointer->at(position - 1) == 0) {
		cout << "The position is already empty!\n";
	}
	list_pointer->at(position - 1) = 0;
}

void Booklist::Selection_Sort()
{
	// as the algorithm, find the minimun and place it at right position in each loop
	vector<int>* list_pointer;
	list_pointer = &book_list_;
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

void Booklist::Bubble_Sort()
{
	// as the algorithm, compare and swap, one for loop in the function beacuse another one is in the sorted check function
	vector<int>* list_pointer;
	list_pointer = &book_list_;
	int swap_temp;
	cout << "Bubble sorting...";
	while (!Sorted_Check()) {
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


