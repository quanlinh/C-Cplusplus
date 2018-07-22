#include "RangeSearch.h"
#include <assert.h>
#include <iostream>


vector<int>  RangeSearch::searchRange(vector<int>& nums, int target)
	{
		int size = nums.size();
		vector<int> rangeIndex = { -1,-1 };
		int leftIndex = search_left_index(nums, target, 0, size - 1) + 1;
		int rightIndex = search_right_index(nums, target, 0, size - 1) - 1;
		if (leftIndex <= rightIndex)
		{
			rangeIndex[0] = leftIndex;
			rangeIndex[1] = rightIndex;
		}
		return rangeIndex;
	}

	int RangeSearch::search_left_index(const vector<int>& nums, int target, int lo, int hi)
	{
		if (lo > hi) return hi;
		int mid = (lo + hi) / 2;
		if (target <= nums[mid]) return search_left_index(nums, target, lo, mid - 1);
		else					 return search_left_index(nums, target, mid + 1, hi);
	}

	int RangeSearch::search_right_index(const vector<int>& nums, int target, int lo, int hi)
	{
		if (lo > hi) return lo;
		int mid = (lo + hi) / 2;
		if (target < nums[mid]) return search_right_index(nums, target, lo, mid - 1);
		else					 return search_right_index(nums, target, mid + 1, hi);

	}

	RangeSearch::~RangeSearch() {}


