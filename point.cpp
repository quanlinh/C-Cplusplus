#include <iostream>
#include <cstdlib>

using namespace std;

class point{
	public:
		point(double x=0.0, double y =0.0):x(x),y(y){} 
		// constructor using list initialization syntax
		// NOTE: only in the contstructor we are allow to usei
		double const getx() {return x;}
		void setx(double value) {x = value;}	
		double const gety() {return y;}
		void sety(double value) {y = value;}
	private:
			double x,y;			



	point::point& operator+ (const point& p1) {
		const point& sum = point (p1.x + this->x, p1.y + this->y);
		return sum;
	}
};

	ostream& operator<< (ostream& out, const point& p) {
		out << "( " << p.getx() << ", " << p.gety() <<" )";
		return out;
	}	

int main() {
//	point a = {3.5,2.5}, b = {1.5,4.5}, c;
//	cout << "a = " << a << " b = " << b << endl;
//	cout << " sum = " << a + b << endl;
	return 0;

}


// usual signature for overloading ostream& operator << 
// 	(ostream& out, const my_type& v) 
// 	both arguments are pass by reference
// 	my_type is passed with a const modifier
// 	so as not to be modified
