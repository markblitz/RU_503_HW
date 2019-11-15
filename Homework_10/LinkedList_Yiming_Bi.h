#ifndef _LINKEDLIST_
#define _LINKEDLIST_

#include "Node_Yiming_Bi.h"

class LinkedList
{public:
	LinkedList();
	~LinkedList();
	int size() const;
	void Add_To_Start(Node*);
	void Add_To_End(Node*);
	void Print_List();
	void Remove_From_Start();
	void Remove_From_End();
	void Remove_Node_From_List(int);
	void Remove_Node_From_List(string);
private:
	Node* list_head;
	Node* list_tail;
	int list_size;
};

#endif
