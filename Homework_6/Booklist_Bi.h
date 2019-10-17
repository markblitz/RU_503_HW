#ifndef _BOOKLIST_
#define _BOOKLIST_

#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

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

	void Insert_End(int new_book);
	void Insert_Position(int new_book, unsigned int position);

	int Linear_Search(int aim_ISBN);
	int Binary_Search(int aim_ISBN);

	void Delete_Position(unsigned int position);

	void Selection_Sort();
	void Bubble_Sort();

private:
	vector<int> book_list_;

};

#endif // !1
