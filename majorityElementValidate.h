#pragma once
#include <vector>
using namespace std;
class majorityElementValidate
{
  public:
    int majorityElementValidateBoyerAndMoore(vector<int> &nums);
    int majorityElementValidateDivideAndConquer(vector<int> &nums);
    int majorityElementValidateDivideAndConquerHelper(vector<int> &nums, int lo, int hi);
    int count(vector<int> &nums, int key);
    int countRange(vector<int> &nums, int key, int lo, int hi);
};