#include "longestIncreasingSub.h"
#include <climits>
#include <algorithm>
#include <iostream>
/*
 * in this function solved the longest increasing subsequence by dynamic
 * programming, using an array to track the subsequence. It using two for 
 * loops. The first loop through all the numbers except the first one, 
 * the second loop throug all numbers until reach the number at the outer 
 * loop. It compares and keep track the longest increasing subsequence 
 */
// the size should be nonegative integers, since len should not less than 0
/* 
I can believe I fall into the reference one more time, I should always use & for
reference :(
Learn new things today. To add more vector of vectors. Just push_back empty vector
*/
size_t longestIncreasingSub::LenLongestIncreasingSubDynamic(const vector<int> &nums)
{
    size_t size = nums.size();
    if (size < 2)
        return size;
    vector<size_t> backTrack(size, 1);
    size_t lenLIS = 1;
    for (size_t i = 1; i < size; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                int maxSofar = backTrack[j] + 1;
                if (maxSofar > backTrack[i])
                    backTrack[i] = maxSofar;
                if (backTrack[i] > lenLIS)
                    lenLIS = backTrack[i];
            }
        }
    }
    return lenLIS;
}
/*
* In this patience sorted algorithms, we use an array of stack, we use the array
* of vector such that it can grows dynamic,  that stored each 
* piles. Using the greedy strategy that always pick the smalles element on the left
* We implement this by use binary search on the range to the left.
* 
*/
vector<int> longestIncreasingSub::longestIncreasingSubPatienceSorted(const vector<int> &nums)
{
    size_t size = nums.size();
    if(size < 2) return nums;
    vector<vector<int>> arrayOfStackVector;
    // create a backTrack matrix with size of two to store the value
    // of the previous element and current element
    vector<vector<int>> backTrack(size, vector<int>(2));
    backTrack[0][0] = INT_MIN;
    backTrack[0][1] = nums[0];

    // put the first element int to the stack
    vector<int> oneV;
    oneV.push_back(nums[0]);
    arrayOfStackVector.push_back(oneV);
    for (size_t i = 1; i < size; i++)
    {
        size_t stackIndex = binarySearch(arrayOfStackVector,nums[i]);
        if (stackIndex >= arrayOfStackVector.size()){
            vector<int> empty(1);
            arrayOfStackVector.push_back(empty);
        }
        arrayOfStackVector[stackIndex][0] = nums[i];
        if (stackIndex == 0) // if the first stack, it previous backtrack shoul be INT_MIN
            backTrack[i][0] = INT_MIN;        
        else // put the previous element is the first element in the fist stack
            backTrack[i][0] = arrayOfStackVector[stackIndex - 1][0];
        backTrack[i][1] = nums[i];
    }
    int lastElement = arrayOfStackVector[arrayOfStackVector.size() - 1][0];
    vector<int> res;
    res.push_back(lastElement);
    size_t lenOfBackTrack = backTrack.size();
    while (lenOfBackTrack > 0)
    {
        int previous = backTrack[lenOfBackTrack - 1][0];
        int current = backTrack[lenOfBackTrack - 1][1];
        if (current == lastElement && previous == INT_MIN)
            break;
        if (current == lastElement)
        {
            res.push_back(previous);
            lastElement = previous;
        }
        lenOfBackTrack--;
    }
    // reverse the order to become longest increasing sub
    reverse(res.begin(), res.end());
    return res;
}
size_t longestIncreasingSub::binarySearch(const vector<vector<int>> &nums, int key)
// size_t longestIncreasingSub::binarySearch(const deque<deque<int>> &nums, int key)
{
    return  binarySearchRangeLeft(nums, key, 0, nums.size() - 1);
}
size_t longestIncreasingSub::binarySearchRangeLeft(const vector<vector<int>> &nums, int key, const size_t lo,const size_t hi)

// size_t longestIncreasingSub::binarySearchRangeLeft(const deque<deque<int>> &nums, int key, const size_t lo,const size_t hi)
{
    if (lo > hi)
        return hi + 1;
    size_t mid = (lo + hi) / 2;
    if (nums[mid][0] >= key)
    {
        if (mid > 0 && nums[mid - 1][0] >= key) binarySearchRangeLeft(nums, key, 0, mid - 1);
        else return mid;
    }
    else return binarySearchRangeLeft(nums, key, mid + 1, hi);
}