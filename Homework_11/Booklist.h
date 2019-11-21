#ifndef _BOOKLIST_
#define _BOOKLIST_

#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

template <class T>
class Booklist
{

public:
	// constructor
	Booklist();
	void Print();
	void Remove_Space();

	bool Full_Check();
	bool Empty_Check();
	bool Sorted_Check();

	void Insert_End(T new_book);
	void Insert_Position(T new_book, unsigned int position);

	int Linear_Search(T aim_book);
	int Binary_Search(T aim_book);

	void Delete_Position(unsigned int position);

	void Selection_Sort();
	void Bubble_Sort();

private:
	vector<T> book_list_;

};



template<class T>
inline Booklist<T>::Booklist()
{
	book_list_.resize(20);
}

template<class T>
inline void Booklist<T>::Print()
{
	if (Empty_Check()) {
		cout << "Book list is empty!\n\n";
	}
	// print all non-zero elements
	else {
		cout << "The current book list is:\n";
		const vector<T>* list_pointer;
		list_pointer = &book_list_;
		for (size_t i = 0; i < list_pointer->size(); i++) {
			if (list_pointer->at(i) != "") {
				cout << setw(3) << i + 1 << ". " << list_pointer->at(i) << endl;
				continue;
			}
			break;
		}
		cout << "Book list ends here!\n" << endl;
	}
}

template<class T>
inline void Booklist<T>::Remove_Space()
{
	// in loop, for any 0 element, move the next one up
	vector<T>* list_pointer;
	list_pointer = &book_list_;
	for (size_t i = 0; i < list_pointer->size(); i++) {
		if (list_pointer->at(i) == "") {
			for (size_t j = i; j < list_pointer->size() - 1; j++) {
				if (list_pointer->at(j + 1) != "") {
					list_pointer->at(i) = list_pointer->at(j + 1);
					list_pointer->at(j + 1) = "";
					break;
				}
			}
		}
	}
}

template<class T>
inline bool Booklist<T>::Full_Check()
{
	// traverse the vector for non-zero elements,if there are certain number of non-zero elements,
	// return true, otherwise return false
	const vector<T>* list_pointer;
	list_pointer = &book_list_;
	size_t i = 0;
	while (true) {
		//cout << i << "  " << list_pointer->size() << endl;
		if (i == list_pointer->size()) {
			return true;
		}
		if (list_pointer->at(i) != "") {
			i++;
			continue;
		}
		return false;
	}
}

template<class T>
inline bool Booklist<T>::Empty_Check()
{
	// traverse the vector for non-zero elements,if there are no non-zero elements,
	// return true, otherwise return false
	const vector<T>* list_pointer;
	list_pointer = &book_list_;
	size_t i = 0;
	while (true) {
		//cout << i << "  " << list_pointer->size() << endl;
		if (i == list_pointer->size()) {
			return true;
		}
		if (list_pointer->at(i) == "") {
			i++;
			continue;
		}
		return false;
	}
}

template<class T>
inline bool Booklist<T>::Sorted_Check()
{
	// traverse the vector for non-zero elements,if each element is smaller than the next one,
	// return true, otherwise return false
	const vector<T>* list_pointer;
	list_pointer = &book_list_;
	for (size_t i = 0; i < list_pointer->size() - 1; i++) {
		if (list_pointer->at(i + 1) == "") {
			break;
		}
		//	cout << list_pointer->at(i) << " " << list_pointer->at(i + 1) << endl;
		if (list_pointer->at(i) > list_pointer->at(i + 1)) {
			return false;
		}
	}
	return true;
}

template<class T>
inline void Booklist<T>::Insert_End(T new_book)
{
	// traverse the vector, for the first non-zero position, insert
	vector<T>* list_pointer;
	list_pointer = &book_list_;
	for (size_t i = 0; i <= list_pointer->size(); i++) {
		if (list_pointer->at(i) == "") {
			list_pointer->at(i) = new_book;
			break;
		}
	}
}

template<class T>
inline void Booklist<T>::Insert_Position(T new_book, unsigned int position)
{
	// if any element at the position, move the rest one position down and insert
	vector<T>* list_pointer;
	list_pointer = &book_list_;
	if (list_pointer->at(position - 1) != "") {
		for (size_t i = list_pointer->size() - 1; i > position - 1; i--) {
			list_pointer->at(i) = list_pointer->at(i - 1);
		}
	}
	list_pointer->at(position - 1) = new_book;
}

template<class T>
inline int Booklist<T>::Linear_Search(T aim_book)
{
	// traverse the vector, do compare directly and return position in netural language (start from 1
	const vector<T>* list_pointer;
	list_pointer = &book_list_;
	for (size_t i = 0; i < list_pointer->size(); i++) {
		if (list_pointer->at(i) == "") {
			break;
		}
		if (list_pointer->at(i) == aim_book) {
			return i + 1;
		}
	}
	return 0;
}

template<class T>
inline int Booklist<T>::Binary_Search(T aim_book)
{
	// search the sorted vector using the algorithm
	const vector<T>* list_pointer;
	list_pointer = &book_list_;
	size_t left_position = 0;
	size_t right_position = 0;
	for (size_t i = 0; i < list_pointer->size(); i++) {
		if (list_pointer->at(i) == "") {
			break;
		}
		right_position = i;
	}
	while (left_position <= right_position) {
		size_t mid_position = (left_position + right_position) / 2;
		if (list_pointer->at(mid_position) < aim_book) {
			left_position = mid_position + 1;
		}
		else if (list_pointer->at(mid_position) > aim_book)
		{
			right_position = mid_position - 1;
		}
		else {
			return mid_position + 1;
		}
	}
	return 0;
}

template<class T>
inline void Booklist<T>::Delete_Position(unsigned int position)
{
	// replace the ceratin element by 0
	vector<T>* list_pointer;
	list_pointer = &book_list_;
	if (list_pointer->at(position - 1) == "") {
		cout << "The position is already empty!\n";
	}
	list_pointer->at(position - 1) = "";
}

template<class T>
inline void Booklist<T>::Selection_Sort()
{
	// as the algorithm, find the minimun and place it at right position in each loop
	vector<T>* list_pointer;
	list_pointer = &book_list_;
	string min = list_pointer->at(0);
	string swap_temp;
	size_t min_position = 0;
	cout << "Selection sorting...";
	for (size_t i = 0; i < list_pointer->size(); i++) {
		if (list_pointer->at(i) == "") {
			break;
		}
		min = list_pointer->at(i);
		min_position = i;
		for (size_t j = i; j < list_pointer->size(); j++) {
			if (list_pointer->at(j) == "") {
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

template<class T>
inline void Booklist<T>::Bubble_Sort()
{
	// as the algorithm, compare and swap, one for loop in the function beacuse another one is in the sorted check function
	vector<T>* list_pointer;
	list_pointer = &book_list_;
	string swap_temp;
	cout << "Bubble sorting...";
	while (!Sorted_Check()) {
		for (size_t i = 0; i < list_pointer->size() - 1; i++) {
			if (list_pointer->at(i + 1) == "") {
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


#endif 