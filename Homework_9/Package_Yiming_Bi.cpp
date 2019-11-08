#include "Package_Yiming_Bi.h"
#include <iostream>
using namespace std;

Package::Package()
{
	weight = 0;	cost_per_ounce = 0;
	Set_Sender(Customer());
	Set_Recipient(Customer());
}

Package::Package(const Customer& input_sender, const Customer& input_recipient, double input_weight, double input_cost)
{
	Set_Sender(input_sender);
	Set_Recipient(input_recipient);
	Set_Weight(input_weight);
	Set_Cost(input_cost);
}

Package::~Package()
{
	// nothing
}

void Package::Set_Weight(double input_weight)
{
	if(input_weight <= 0) {
		cout << "Your input weight is negative or zero! Please set later again!\n";
		weight = -1;
	}
	else {
		weight = input_weight;
	}
}

void Package::Set_Cost(double input_cost)
{
	if (input_cost <= 0) {
		cout << "Your input cost is negative or zero! Please set later again!\n";
		cost_per_ounce = -1;
	}
	else {
		cost_per_ounce = input_cost;
	}
}

void Package::Set_Sender(const Customer& input_sender)
{
	sender = input_sender;
}

void Package::Set_Recipient(const Customer& input_recipient)
{
	recipient = input_recipient;
}

double Package::Get_Weight() const
{
	return weight;
}

double Package::Get_Cost() const
{
	return cost_per_ounce;
}

double Package::Calculate_Cost() const
{
	return weight * cost_per_ounce;
}

void Package::Print_Sender() const
{
	sender.Print();
}

void Package::Print_Recipient() const
{
	recipient.Print();
}

void Package::Print_Package() const
{
	cout << "Sender:\n";
	Print_Sender();
	cout << endl << "Recipient:\n";
	Print_Recipient();
	cout << endl << "Weight of package: " << Get_Weight() << " ounces\n";
	cout << "Type if delivery: Regular Delivery\n";
	cout << "Cost of package: $" << Calculate_Cost() << endl;
}
