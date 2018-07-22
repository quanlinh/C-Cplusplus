#include "TestLongestIncreasingSub.h"

using namespace std;
void TestLongestIncreasingSub::testLIS()
{
    longestIncreasingSub lis;
    vector<int> a = {10, 9, 2, 5, 3, 7, 101, 18};
    size_t res = lis.LenLongestIncreasingSubDynamic(a);
    assert(lis.LenLongestIncreasingSubDynamic(a) == 4);
    vector<int> b = {2, 2};
    assert(lis.LenLongestIncreasingSubDynamic(b) == 1);
    vector<int> c = {-2, -1};
    assert(lis.LenLongestIncreasingSubDynamic(c) == 2);
    cout << "\npassed test Longest Increasing Subsequece \n"
         << endl;
}
void TestLongestIncreasingSub::testLISPatienceSort()
{
    longestIncreasingSub lis;
    vector<int> empty = {};
    assert(lis.longestIncreasingSubPatienceSorted(empty).size() == 0);
    vector<int> oneElement = {1};
    assert(lis.longestIncreasingSubPatienceSorted(oneElement).size() == 1);
    vector<int> a = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> expected_a = lis.longestIncreasingSubPatienceSorted(a);
    assert(expected_a.size() == 4);
    vector<int> b = {7, 2, 8, 1, 3, 4, 10, 6, 9, 5};
    vector<int> expected_b = lis.longestIncreasingSubPatienceSorted(b);
    vector<int> actual_b = {1, 3, 4, 6, 9};
    TestEachElement(expected_b, actual_b);
    vector<int> c = {18, 55, 66, 2, 3, 54};
    vector<int> expected_c = lis.longestIncreasingSubPatienceSorted(c);
    assert(expected_c.size() == 3);
    vector<int> d = {1, 3, 6, 7, 9, 4, 10, 5, 6};
    vector<int> expected_d = lis.longestIncreasingSubPatienceSorted(d);
    assert(expected_d.size() == 6);
    cout << "\npassed test Longest Increasing Subsequece Patience Sorted\n";

}
void TestLongestIncreasingSub::TestEachElement(const vector<int> a, const vector<int> b)
{
    assert(a.size() == b.size());
    for (size_t i = 0; i < b.size(); i++)
    {
        assert(a[i] == b[i]);
    }
}

