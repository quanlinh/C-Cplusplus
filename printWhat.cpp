#include <iostream>
using namespace std;
int main() {
	int i = 9, j = 3;
	cout << "i is " << i << " j is " << j << endl; 
	{
		int i = j + 2;
		cout << "i is " << i << " j is " << j << endl;
	}

	cout << "i is " << i << " j is " << j << endl;
}
