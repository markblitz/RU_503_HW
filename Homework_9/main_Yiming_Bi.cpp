#include<iostream>
#include<vector>
#include<string>
using namespace std;

#include "Package_Yiming_Bi.h"
#include "TwoDayPackage_Yiming_Bi.h"
#include "Customer_Yiming_Bi.h"

int main() {

	Customer first_sender ("First Sender", "1 Virtual Ave", "Virtual City", "AA", "12345");
	Customer first_recipient ("First Recipient", "2 Virtual Ave", "Virtual City", "AA", "12345");
	Customer second_sender("Second Sender", "3 Virtual Ave", "Virtual City", "AA", "12345");
	Customer second_recipient("Second Recipient", "4 Virtual Ave", "Virtual City", "AA", "12345");

	double regular_cost = 0.5,	two_day_flat_cost = 2;
	double weight_p1 = 10, weight_p2 = 5;

	vector<Package*> package;
	Package* p1 = new Package(first_sender, first_recipient, weight_p1, regular_cost);
	TwoDayPackage* p2 = new TwoDayPackage(second_sender, second_recipient, weight_p2, regular_cost, two_day_flat_cost);
	package.push_back(p1);
	package.push_back(p2);

	p2->Print_Package();

	return 0;
}