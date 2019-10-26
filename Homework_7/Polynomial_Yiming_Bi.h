#ifndef _POLYNOMIAL_
#define _POLYNOMIAL_

class Polynomial
{
public:
	Polynomial();
	void Set_Polynomial();
	void operator+=(const Polynomial&);
	void operator-=(const Polynomial&); 
	void operator*=(const Polynomial&);
	void operator=(const Polynomial&);
	Polynomial operator+(const Polynomial&);
	Polynomial operator-(const Polynomial&);
	Polynomial operator*(const Polynomial&);
	friend ostream& operator<<(ostream&, const Polynomial&);
private:
	int inner_array[13];
};

#endif