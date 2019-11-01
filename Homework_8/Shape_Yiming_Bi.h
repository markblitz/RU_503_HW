#ifndef _SHAPE_
#define _SHAPE_
class Shape
{
public:
	Shape();
	~Shape();
	void Set_X(double);
	void Set_Y(double);
	double Get_X() const;
	double Get_Y() const;
	void Print_Center() const;

private:
	// center of shape in (x,y) form
	double center_x;
	double center_y;
};

#endif
