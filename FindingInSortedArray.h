#pragma once
#include <vector>
using namespace std;

class FindingSortedArray
{
  public:
    int search(vector<int> &nums, int target);

  private:
    int searchSortedOnly(vector<int> nums, int lo, int hi, int target);
};
