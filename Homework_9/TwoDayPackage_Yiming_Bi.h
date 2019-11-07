#ifndef _TWODAYPACKAGE_
#define _TWODAYPACKAGE_
#include "Package_Yiming_Bi.h"
class TwoDayPackage :
	public Package
{
public:
	TwoDayPackage();
	TwoDayPackage(const Customer&, const Customer&, double, double, double);
	~TwoDayPackage();

	void Set_Flat_Cost(double);
	double Get_Flat_Cost() const;

	virtual double Calculate_Cost() const;
	virtual void Print_Package() const;

private:
	double flat_cost;
};

#endif