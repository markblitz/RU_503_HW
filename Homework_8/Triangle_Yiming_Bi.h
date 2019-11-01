#ifndef _TRIANGLE_
#define _TRIANGLE_

#include "TwoD_Shape_Yiming_Bi.h"
class Triangle :
	public TwoD_Shape
{
public:
	Triangle();
	~Triangle();
	void Set_Edge(double);
	double Get_Edge() const;
	virtual double Get_Area() const;
	virtual void Print() const;
private:
	double edge;
};

#endif
