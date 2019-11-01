#ifndef _SPHERE_
#define _SPHERE_
#include "ThreeD_Shape_Yiming_Bi.h"
class Sphere :
	public ThreeD_Shape
{
public:
	Sphere();
	~Sphere();
	void Set_Radius(double);
	double Get_Radius() const;
	virtual double Get_Area() const;
	virtual double Get_Volume() const;
	virtual void Print();
private:
	double radius;
};

#endif
