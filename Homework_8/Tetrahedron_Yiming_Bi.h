#ifndef _TETRAHEDRON_
#define _TETRAHEDRON_
#include "ThreeD_Shape_Yiming_Bi.h"
class Tetrahedron :
	public ThreeD_Shape
{
public:
	Tetrahedron();
	~Tetrahedron();
	void Set_Edge(double);
	double Get_Edge() const;
	virtual double Get_Area() const;
	virtual double Get_Volume() const;
	virtual void Print();
private:
	double edge;
};

#endif
