#include <string>
using namespace std;
#ifndef _CUSTOMER_
#define _CUSTOMER_
// this class is made to avoid typing name, address and those information twice for b
class Customer
{
public:
	Customer();
	Customer(string, string, string, string, string);
	~Customer();
	void operator=(const Customer&);
	void Print() const;

	void Set_Name(string);
	void Set_Address(string);
	void Set_City(string);
	void Set_State(string);
	void Set_Zip(string);

	string Get_Name() const;
	string Get_Address() const;
	string Get_City() const;
	string Get_State() const;
	string Get_Zip() const;

private:
	string name, address, city, state, zip;
};
#endif