#include "Customer_Yiming_Bi.h"
#include <iostream>
using namespace std;

Customer::Customer()
{
	Set_Name("");
	Set_Address("");
	Set_City("");
	Set_State("");
	Set_Zip("");
}

Customer::Customer(string input_name, string input_address,
	string input_city, string input_state, string input_zip)
{
	Set_Name(input_name);
	Set_Address(input_address);
	Set_City(input_city);
	Set_State(input_state);
	Set_Zip(input_zip);
}

Customer::~Customer()
{
	// do nothing here!
}

void Customer::operator=(const Customer& input_customer)
{
	Set_Name(input_customer.Get_Name());
	Set_Address(input_customer.Get_Address());
	Set_City(input_customer.Get_City());
	Set_State(input_customer.Get_State());
	Set_Zip(input_customer.Get_Zip());
}

void Customer::Print() const
{
	cout << Get_Name() << endl;
	cout << Get_Address() << endl;
	cout << Get_City() << ", " << Get_State()
		<< " " << Get_Zip() << endl;
}

void Customer::Set_Name(string input_name)
{
	name = input_name;
}

void Customer::Set_Address(string input_address)
{
	address = input_address;
}

void Customer::Set_City(string input_city)
{
	city = input_city;
}

void Customer::Set_State(string input_state)
{
	state = input_state;
}

void Customer::Set_Zip(string input_zip)
{
	zip = input_zip;
}

string Customer::Get_Name() const
{
	return name;
}

string Customer::Get_Address() const
{
	return address;
}

string Customer::Get_City() const
{
	return city;
}

string Customer::Get_State() const
{
	return state;
}

string Customer::Get_Zip() const
{
	return zip;
}
