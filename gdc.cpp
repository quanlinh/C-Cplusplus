#include <iostream>
using namespace std;
int gcd(int m, int n) 		
{
	int r;

	while (n != 0) {
		r = m % n;
		m = n;
		n = r;
	}
	return m; 
}

int main() 
{
	int x, y, howMany; 

	cout << "\nPROGRAM GCD C++";
	cout << "\nEnter how many GCD computations? ";
	cin >> howMany;
	for (int i = 0; i < howMany; ++i) {
		cout << "\nEnter two integers: ";
		cin >> x >> y;
		cout << "\nGCD(" << x << ", " << y << ") = "
			 << gcd(x, y) << endl;
	}

}
