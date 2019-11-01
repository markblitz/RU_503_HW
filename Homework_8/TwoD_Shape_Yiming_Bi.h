#ifndef _TWODSHAPE_
#define _TWODSHAPE_

#include "Shape_Yiming_Bi.h"
class TwoD_Shape :
	public Shape
{
public:
	virtual double Get_Area() const = 0;
	virtual void Print() const = 0;
private:

};

#endif
