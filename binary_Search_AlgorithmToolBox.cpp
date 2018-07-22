#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class BinarySearch
{
	public:
		int iterative_binary_search(const vector<int>& a, int value);
		int linear_search(const vector<int>& a, int value);
		// No destructor need, did not declare anythings big
};


int BinarySearch::iterative_binary_search(const vector<int> &a, int value) {
	int size = (int)a.size();
	int lo = 0;
	int hi = size - 1;
	int mid = (hi - lo) / 2;
	while (mid >= lo && mid <= hi)
	{
		int valueAtMid = a[mid];
		if (value < valueAtMid)
		{
			hi = mid - 1;
			if (hi < lo) return -1;
			if (hi - lo == 0) mid = hi;
			else mid = lo + (hi - lo) / 2;			
		} 
		else if (value > valueAtMid)
		{
			lo = mid + 1;
			if (lo > hi) return -1;
			if (hi - lo == 0) mid = hi;
			else mid = lo + (hi - lo) / 2;
		}
		else
		{
			while (mid > 0 && a[mid] == a[mid - 1]) mid = lo + (hi - lo) / 2;		
			return mid;
		}

	}
	return -1;
}

int BinarySearch::linear_search(const vector<int> &a, int x) {
	for (size_t i = 0; i < a.size(); ++i) {
		if (a[i] == x) return i;
	}
	return -1;
}



int main() {
	BinarySearch bs;
	int n;
	cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); i++) {
		std::cin >> a[i];
	}
	int m;
	cin >> m;
	vector<int> b(m);
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}
	for (int i = 0; i < m; ++i) {
		cout << bs.iterative_binary_search(a, b[i]) << ' ';
		// cout << binary_search(a, b[i]) << ' ';
	}
	cin.sync();
	cin.get();
	cin.ignore();
	return 0;
}
