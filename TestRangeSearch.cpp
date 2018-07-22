#include "TestRangeSearch.h"
#include <assert.h>
void TestRangeSearch::testRangeSearch() {
	try {
		vector<int> array2 = { 5,7,7,8,8,10 };
		RangeSearch test;
		vector<int> rs1 = test.searchRange(array2, 6);
		assert(rs1[0] == -1);
		assert(rs1[1] == -1);
		cout << "Test Range Search Passed";
		cin.sync();
		cin.get();
	}
	catch (exception assert) {
		cout << "Test Range Search Passed";
	}
}




