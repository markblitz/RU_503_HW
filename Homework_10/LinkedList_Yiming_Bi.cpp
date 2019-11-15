#include <iostream>
#include <iomanip>
using namespace std;
#include "LinkedList_Yiming_Bi.h"

LinkedList::LinkedList()
{
	list_head = NULL;
	list_tail = NULL;
	list_size = 0;
}

LinkedList::~LinkedList()
{
}

int LinkedList::size() const
{
	return list_size;
}

void LinkedList::Add_To_Start(Node* newPtr)
{
	if (list_size == 0) {
		list_head = list_tail = newPtr;
	}
	else {
		newPtr->next = list_head;
		list_head = newPtr;
	}
	list_size++;
}

void LinkedList::Add_To_End(Node* newPtr)
{
	if (list_size == 0) {
		list_head = list_tail = newPtr;
	}
	else {
		list_tail->next = newPtr;
		list_tail = newPtr;
	}
	list_size++;
}

void LinkedList::Print_List()
{
	if (list_size == 0) {
		cout << "\nThe list is empty!\n\n";
	}
	else {
		Node* currentPtr = list_head;
		cout << setw(10) << "\nItem No." << setw(16) << "Item Name" << endl;
		while (currentPtr != NULL) {
				cout << setw(4) << currentPtr->ItemNo << setw(18) << currentPtr->ItemName << endl;
				currentPtr = currentPtr->next;
		}
		cout << "The list ends here.\n\n";
	}
}

void LinkedList::Remove_From_Start()
{
	if (list_size == 0) {
		cout << "\nThe list is empty!\n";
	}
	else {
		Node* current_first = list_head;
		list_head = list_head->next;
		delete current_first;
		list_size--;
	}
}

void LinkedList::Remove_From_End()
{
	if (list_size == 0) {
		cout << "\nThe list is empty!\n";
	}
	else {
		Node* currentPtr = list_head;
		while (currentPtr->next != list_tail) {
			currentPtr = currentPtr->next;
		}
		list_tail = currentPtr;
		Node* current_last;
		current_last = list_tail->next;
		list_tail->next = NULL;
		delete current_last;
		list_size--;
	}
}

void LinkedList::Remove_Node_From_List(int input_number)
{
	if (list_size == 0) {
		cout << "\nThe list is empty!\n";
	}
	else {
		Node* currentPtr = list_head;
		if (currentPtr->ItemNo == input_number) {
			Remove_From_Start();
		}
		else {
			while (currentPtr->next != NULL) {	// view each node
				if (currentPtr->next->ItemNo == input_number) {	// if the next node needs to be deleted
					Node* to_delete = currentPtr->next;	// make the deleted node
					currentPtr->next = currentPtr->next->next;	// skip it from the like
					delete to_delete;	// delete it!
					list_size--;
					break;
				}
				currentPtr = currentPtr->next;
			}
			if (currentPtr == list_tail) {
				cout << "The number may not exist!\n";
			}
		}
	}
}

void LinkedList::Remove_Node_From_List(string input_name)
{
	if (list_size == 0) {
		cout << "\nThe list is empty!\n";
	}
	else {
		Node* currentPtr = list_head;
		if (currentPtr->ItemName == input_name) {
			Remove_From_Start();
		}
		else {
			while (currentPtr->next != NULL) {
				if (currentPtr->next->ItemName == input_name) {
					Node* to_delete = currentPtr->next;
					currentPtr->next = currentPtr->next->next;
					delete to_delete;
					list_size--;
					break;
				}
				currentPtr = currentPtr->next;
			}
			if (currentPtr == list_tail) {
				cout << "The name may not exist!\n";
			}
		}
	}
}
