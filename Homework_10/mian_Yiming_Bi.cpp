#include<iostream>
using namespace std;

#include"Node_Yiming_Bi.h"
#include"LinkedList_Yiming_Bi.h"

int main() {
	LinkedList shopping_list;
	while (true) {
		// ask input
		cout << "Welcome to the shopping list program\n"
			<< "Please choose an option:\n"
			<< "1. Add a new node at the beginning\n"
			<< "2. Add a new node at the end\n"
			<< "3. Remove the beginning node\n"
			<< "4. Remove the end node\n"
			<< "5. Remove a node from the list by entering an item number\n"
			<< "6. Remove a node from the list by entering an item name\n"
			<< "7. Print out the list\n"
			<< "8. Quit the program\n\n"
			<< "Your choice: ";
		int user_choice;
		cin >> user_choice;

		switch (user_choice)
		{
		case 1:
		{
			cout <<"\nPlease enter product number to insert at beginning:\n";
			int input_item_number;
			cin >> input_item_number;
			cout << "Please enter the name for the product:\n";
			string input_item_name;
			cin >> input_item_name;
			Node *input_item = new Node(input_item_name, input_item_number);
			shopping_list.Add_To_Start(input_item);
			shopping_list.Print_List();
			continue;
		}
		case 2:
		{
			cout << "\nPlease enter product number to insert at end:\n";
			int input_item_number;
			cin >> input_item_number;
			cout << "Please enter the name for the product:\n";
			string input_item_name;
			cin >> input_item_name;
			Node* input_item = new Node(input_item_name, input_item_number);
			shopping_list.Add_To_End(input_item);
			shopping_list.Print_List();
			continue;
		}
		case 3:
		{
			shopping_list.Remove_From_Start();
			shopping_list.Print_List();
			continue;
		}
		case 4:
		{
			shopping_list.Remove_From_End();
			shopping_list.Print_List();
			continue;
		}
		case 5:
		{
			cout << "\nPlease enter the number of product you want to delete:\n";
			int input_to_delete;
			cin >> input_to_delete;
			shopping_list.Remove_Node_From_List(input_to_delete);
			shopping_list.Print_List();
			continue;
		}
		case 6:
		{
			cout << "\nPlease enter the name of product you want to delete:\n";
			string input_to_delete;
			cin >> input_to_delete;
			shopping_list.Remove_Node_From_List(input_to_delete);
			shopping_list.Print_List();
			continue;
		}
		case 7:
		{
			shopping_list.Print_List();
			continue;
		}
		case 8: 
		{
			cout << "Exit the program!\n";
			break;
		}
		default:
			cout << "Invalid input!\n";
			continue;
		}

		break;


	}
	return 0;
}