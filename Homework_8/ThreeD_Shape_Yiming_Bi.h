#ifndef _THREEDSHAPE_
#define _THREEDSHAPE_
#include "Shape_Yiming_Bi.h"
class ThreeD_Shape :
	public Shape
{
public:
	void Set_Z(double);
	double Get_Z() const;
	virtual double Get_Area() const = 0;
	virtual double Get_Volume() const = 0;
	virtual void Print() = 0;
	void Print_Center() const;
private:
	double center_z;
};

#endif
