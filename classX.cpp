#include <iostream>
#include <cstdlib> 

class X {
	private:
			int m;
	public:
			X(int i = 0) :m{i} {} 		// a constructor ( initialize member m) 

			int mf(int i) 				// a member function
			{
					int old = m;
					m = i;				// set a new value 
					return old;			// return old value
			}			
};

X var {7}; // a variable of type X, initialized to 7

int user(X var, X* ptr) 
{
	int x = var.mf(7);					// accesing using .(dot)
	int y = ptr->mf(9);					// accessing using -> arrow
 
}

int main(){return 0;}
