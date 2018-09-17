#include "FindingInSortedArray.h"
/**
 * The idea is only search binary that can be cut off
 * by two partion of the element is always exists and sorted partition
 *  */

int search(vector<int> &nums, int target)
{
    return searchSortedOnly(nums, 0, nums.size() - 1, target);
}
int searchSortedOnly(vector<int> nums, int lo, int hi, int target)
{
    if (lo == hi)
    {
        if (nums[lo] == target)
            return lo;
        else
            return -1;
    }
    if (lo > hi)
        return -1;
    int mid = (lo + hi) / 2;
    if(nums[mid] == target) return mid;
    if(nums[lo] < nums[mid]) {
        if(nums[lo] <= target && target < nums[mid]) return searchSortedOnly(nums,lo,mid-1,target);
        else return searchSortedOnly(nums, mid+1,hi,target);
    } else {
        if(nums[mid+1] <= target && target <= nums[hi]) return searchSortedOnly(nums, mid+1,hi,target);
        else return searchSortedOnly(nums,lo,mid-1,target);
    }
}
