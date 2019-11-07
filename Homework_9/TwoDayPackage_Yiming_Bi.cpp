#include "TwoDayPackage_Yiming_Bi.h"
#include <iostream>
using namespace std;

TwoDayPackage::TwoDayPackage()
{
}

TwoDayPackage::TwoDayPackage(const Customer& input_sender, const Customer& input_recipient,
	double input_weight, double input_cost, double input_flat_cost)
{
	Set_Sender(input_sender);
	Set_Recipient(input_recipient);
	Set_Weight(input_weight);
	Set_Cost(input_cost);
	Set_Flat_Cost(input_flat_cost);

}

TwoDayPackage::~TwoDayPackage()
{
	// nothing here
}

void TwoDayPackage::Set_Flat_Cost(double input_flat_cost)
{
	flat_cost = input_flat_cost;
}

double TwoDayPackage::Get_Flat_Cost() const
{
	return flat_cost;
}

double TwoDayPackage::Calculate_Cost() const
{
	return (flat_cost + Get_Cost()) * Get_Weight();
}

void TwoDayPackage::Print_Package() const
{
	cout << "Sender:\n";
	Print_Sender();
	cout << endl << "Recipient:\n";
	Print_Recipient();
	cout << endl << "Weight of package: " << Get_Weight() << " ounces\n";
	cout << "Type if delivery: Two Day Delivery\n";
	cout << "Cost of package: $" << Calculate_Cost() << endl;
}
