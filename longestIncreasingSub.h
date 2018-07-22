#pragma once
#include <vector>
using namespace std;
class longestIncreasingSub
{
    public:
        size_t LenLongestIncreasingSubDynamic(const vector<int> &nums);
        vector<int> longestIncreasingSubPatienceSorted(const vector<int> &nums);
    private:
        // size_t binarySearch(const deque<deque<int>> &arrayOfStack, int key);
        size_t binarySearch(const vector<vector<int>> &arrayOfStack, int key);
        size_t binarySearchRangeLeft(const vector<vector<int>>  &nums, int key, const size_t lo, const size_t hi);
        // size_t binarySearchRangeLeft(const deque<deque<int>>  &nums, int key, const size_t lo, const size_t hi);
};