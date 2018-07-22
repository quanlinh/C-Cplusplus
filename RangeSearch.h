#pragma once
#include <vector>

using namespace std;
class RangeSearch
{
public:

	vector<int>  searchRange(vector<int>& nums, int target);	
	int search_left_index(const vector<int>& nums, int target, int lo, int hi);	
	int search_right_index(const vector<int>& nums, int target, int lo, int hi);	
	~RangeSearch();
};

