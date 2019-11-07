#include "Customer_Yiming_Bi.h"
#ifndef _PACKAGE_
#define _PACKAGE_
class Package
{
public:
	Package();
	Package(const Customer&, const Customer&, double, double);
	~Package();
	void Set_Weight(double);
	void Set_Cost(double);
	void Set_Sender(const Customer&);
	void Set_Recipient(const Customer&);
	double Get_Weight() const;
	double Get_Cost() const;
	void Print_Sender() const;
	void Print_Recipient() const;
	virtual double Calculate_Cost() const;
	virtual void Print_Package() const;

private:
	Customer sender, recipient;
	double weight, cost_per_ounce;
};

#endif