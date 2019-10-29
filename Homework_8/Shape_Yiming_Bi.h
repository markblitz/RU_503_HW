#ifndef _SHAPE_
#define _SHAPE_
class Shape
{
public:
	Shape(int&, int&);
	~Shape();
	void Set_X(int&);
	void Set_Y(int&);
	int Get_X();
	int Get_Y();

private:
	// center of shape in (x,y) form
	int center_x;
	int center_y;
};

#endif
