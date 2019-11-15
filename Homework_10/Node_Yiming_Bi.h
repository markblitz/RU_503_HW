#include <iostream>
using namespace std;
#ifndef _NODE_
#define _NODE_

class Node {
	friend class LinkedList;
public:
	Node(string& name, int no) :ItemName(name), ItemNo(no) {
		this->next = NULL;
	}
private:
	string ItemName;
	int ItemNo;
	Node* next;
};
#endif

