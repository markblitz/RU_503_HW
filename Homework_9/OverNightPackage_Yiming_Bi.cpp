#include "OverNightPackage_Yiming_Bi.h"
#include <iostream>
using namespace std;

OverNightPackage::OverNightPackage()
{
	flat_cost = 0;
}

OverNightPackage::OverNightPackage(const Customer& input_sender, const Customer& input_recipient, 
	double input_weight, double input_cost, double input_flat_cost)
{
	Set_Sender(input_sender);	Set_Recipient(input_recipient);
	Set_Weight(input_weight);	Set_Cost(input_cost);	Set_Flat_Cost(input_flat_cost);
}

OverNightPackage::~OverNightPackage()
{
	// nothing
}

void OverNightPackage::Set_Flat_Cost(double input_flat_cost)
{
	flat_cost = input_flat_cost;
}

double OverNightPackage::Get_Flat_Cost() const
{
	return flat_cost;
}

double OverNightPackage::Calculate_Cost() const
{
	return (Get_Cost() + flat_cost) * Get_Weight();
}

void OverNightPackage::Print_Package() const
{
	cout << "Sender:\n";
	Print_Sender();
	cout << endl << "Recipient:\n";
	Print_Recipient();
	cout << endl << "Weight of package: " << Get_Weight() << " ounces\n";
	cout << "Type if delivery: Overnight Delivery\n";
	cout << "Cost of package: $" << Calculate_Cost() << endl;
}
