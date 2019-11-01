#ifndef _CIRCLE_
#define _CIRCLE_

#include "TwoD_Shape_Yiming_Bi.h"
class Circle :
	public TwoD_Shape
{
public:
	Circle();
	~Circle();
	void Set_Radius(double);
	double Get_Radius() const;
	virtual double Get_Area() const;
	virtual void Print() const;
private:
	double radius;
};

#endif
