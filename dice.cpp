//  In this program I convert the dice Carlo simulation to C++ version
#include <iostream> 
#include <cstdlib> 
#include <ctime>
#include <vector>
using namespace std;
using std::vector; // in C++ we will have to call template vector to use it
const int N = 40; // I change defines of constants to constant
inline void sum(int &accum, int N, vector <int> data);
void sum(int*p, int n, vector<int> d)
{
	*p = 0;
	for (int i = 0; i < n; ++i) {
		*p = *p + d[i]; 
	}
}

int main() 
{
	 
	int accum = 0;
	vector<int> data; // change the array into vector
	for (int i = 0; i < N; ++i) {
		data.push_back(i); // append sequential integers in to data
	}
	sum(&accum, N, data);
	cout << "sum is " << accum << "\n"; // using cout instead of printf
	return 0;
}
