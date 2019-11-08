#ifndef _OVERNIGHTPACKAGE_
#define _OVERNIGHTPACKAGE_
#include "Package_Yiming_Bi.h"
class OverNightPackage :
	public Package
{
public:
	OverNightPackage();
	OverNightPackage(const Customer&, const Customer&, double, double, double);
	~OverNightPackage();

	void Set_Flat_Cost(double);
	double Get_Flat_Cost() const;

	virtual double Calculate_Cost() const;
	virtual void Print_Package() const;
private:
	double flat_cost;
};

#endif