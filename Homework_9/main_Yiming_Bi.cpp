#include<iostream>
#include<vector>
#include<string>
using namespace std;

#include "Package_Yiming_Bi.h"
#include "Customer_Yiming_Bi.h"

int main() {

	Customer first_sender ("First Sender", "1 Virtual Ave", "Virtual City", "AA", "12345");
	Customer first_recipient ("First Recipient", "2 Virtual Ave", "Virtual City", "AA", "12345");

	double regular_cost = 0.5;
	double weight_p1 = 20.3;

	vector<Package*> package;
	Package* p1 = new Package(first_sender, first_recipient, regular_cost, weight_p1);
	package.push_back(p1);

	p1->Print_Package();

	return 0;
}