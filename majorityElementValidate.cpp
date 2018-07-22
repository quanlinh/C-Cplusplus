#include "majorityElementValidate.h"
#include <iostream>
int majorityElementValidate::majorityElementValidateBoyerAndMoore(vector<int> &nums)
{
    size_t size = nums.size();
    if(size < 2) return size;
    int candidate = nums[0], cnt = 0;
    
    for(int num : nums)
    {
        if(cnt == 0) 
        {
            candidate = num;
            cnt++;
        } else if(candidate == num)
        {
               cnt++;
        } else cnt--;
    }
    cnt = count(nums,candidate);
    if(cnt > size/2) return 1;
    else return 0;

}
/*
Using devide and conquer approache to solve majority element problems
How to combine two results of two recursive called? Solved.
Using checking for the range of majority
*/
int majorityElementValidate::majorityElementValidateDivideAndConquer(vector<int> &nums)
{   size_t size = nums.size();
    if(size < 2) return size;
    int isMajor = majorityElementValidateDivideAndConquerHelper(nums, 0, size-1);
    int cnt = count(nums, isMajor);
    if(cnt > size/2) return 1;
    else return 0;
}

int majorityElementValidate::majorityElementValidateDivideAndConquerHelper(vector<int> &nums, int lo, int hi)               
{
    if(lo == hi) return nums[lo];
    int mid = (lo + hi) / 2;
    int leftMajor = majorityElementValidateDivideAndConquerHelper(nums,lo,mid);
    int rightMajor = majorityElementValidateDivideAndConquerHelper(nums,mid + 1,hi);
    int countLeft = countRange(nums,leftMajor,lo, mid);
    int countRight= countRange(nums,rightMajor,mid+1, hi);
    if(countLeft > countRight) return leftMajor;
    else return rightMajor;
}

int majorityElementValidate::countRange(vector<int> &nums, int key, int lo, int hi)
{
    int count = 0;
    for(int i = lo; i <= hi; i++)  if(nums[i] == key) count++;
    return count;
}

int majorityElementValidate::count(vector<int> &nums, int key)
{
    int count = 0;
    for(int num : nums) if(num == key) count++;
    return count;    
}

