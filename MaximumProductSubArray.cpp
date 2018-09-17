#include "MaximumProductSubArray.h"
#include <bits/stdc++.h>
int maxProduct(vector<int> &nums)
{
    // As maximum product can be negative, so initialize
    // ans with minimum integer value.
    int ans = INT_MIN;
    int maxVal = 1;
    int minVal = 1;

    int prevMax; // variable used during updattion of max and min product

    for (size_t i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
        {
            // if current element is positive, update max value
            maxVal = maxVal * nums[i];
            // update minVal if it is negative
            minVal = min(1, minVal * nums[i]);
        }
        // if current element is 0, maximum product cannot end at the current
        // element. Update minVal with 1, and maxVal with 0
        // maxVal is updated to 0 as  in case all other elements are negative,
        // the maxVal is 0
        else if (nums[i] == 0)
        {
            minVal = 1;
            maxVal = 0;
        }
        // If current element is negative, the new value of maxVal is previous minVal*nums[i]
        // and new value of minVal is previous maxVal*nums[i]
        // Before updating maxVal, store its previous value in prevMax to be used to update minVal.
        else
        {
            prevMax = maxVal;
            maxVal = minVal * nums[i];
            minVal = prevMax * nums[i];
        }
        ans = max(ans, maxVal);
        if (maxVal <= 0)
            maxVal = 1;
    }
    return ans;
}

int findMaxProductOptimize(vector<int> &nums)
{
    int maxVal = nums[0];
    int minimum = nums[0];
    int maximum = nums[0];

    for (size_t i = 1; i < nums.size(); i++)
    {
        int prevMin = minimum;
        int prevMax = maximum;
        minimum = min(nums[i], min(nums[i]*prevMin, nums[i]*prevMax));
        maximum = max(nums[i], max(nums[i]*prevMin, nums[i]*prevMax));
        maxVal = max(maxVal,maximum);

    }
    return maxVal;
}
