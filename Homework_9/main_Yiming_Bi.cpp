#include<iostream>
#include<vector>
#include<string>
using namespace std;

#include "Package_Yiming_Bi.h"
#include "TwoDayPackage_Yiming_Bi.h"
#include "OverNightPackage_Yiming_Bi.h"
#include "Customer_Yiming_Bi.h"

int main() {

	Customer first_sender ("First Sender", "1 Virtual Ave", "Virtual City", "AA", "12345");
	Customer first_recipient ("First Recipient", "2 Virtual Ave", "Virtual City", "AA", "12345");
	Customer second_sender("Second Sender", "3 Virtual Ave", "Virtual City", "AA", "12345");
	Customer second_recipient("Second Recipient", "4 Virtual Ave", "Virtual City", "AA", "12345");
	Customer third_sender("Third Sender", "5 Virtual Ave", "Virtual City", "AA", "12345");
	Customer third_recipient("Third Recipient", "6 Virtual Ave", "Virtual City", "AA", "12345");

	double regular_cost = 0.5, two_day_flat_cost = 2, overnight_flat_cost = 5;
	double weight_p1 = 10, weight_p2 = 5, weight_p3 = 2;

	vector<Package*> package;	// create a vector for type pointer of class package
	Package* p1 = new Package(first_sender, first_recipient, weight_p1, regular_cost);
	TwoDayPackage* p2 = new TwoDayPackage(second_sender, second_recipient, weight_p2, regular_cost, two_day_flat_cost);
	OverNightPackage* p3 = new OverNightPackage(third_sender, third_recipient, weight_p3, regular_cost, overnight_flat_cost);
	package.push_back(p1);
	package.push_back(p2);
	package.push_back(p3);

	cout << "Package delivery servies program\n\n";
	cout << "Cost per ounce for a package: $" << regular_cost << "/ounce\n";
	cout << "Additional cost for two-day delivery: $" << two_day_flat_cost << "/ounce\n";
	cout << "Additional cost for overnight delivery: $" << overnight_flat_cost << "/ounce\n";
	cout << endl;

	int package_index = 0;
	double total_cost = 0;

	for (vector<Package*>::iterator it = package.begin(); it != package.end(); it++) {
		if ((*it)->Get_Weight() == -1 || (*it)->Get_Cost() == -1) {
			cout << "This package may have invalid weight or regular cost per ounce!\nIt will not be printed!\n";
		}
		else {
			cout << "Package " << ++package_index << ":\n\n";
			(*it)->Print_Package();	// I use a class member function to avoid typing many Get functions
			cout << endl;
			total_cost += (*it)->Calculate_Cost();
		}
	}

	cout << "Total cost of all the package: $" << total_cost << endl;

	return 0;
}