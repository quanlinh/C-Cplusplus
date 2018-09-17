#include "GenerateSubsets.h"
#include "math.h"
vector<vector<int>> generateSubSetBits(vector<int> &S)
{
    size_t subSetSize = pow(2, S.size());
    vector<vector<int>> subSets(subSetSize);
    for (size_t i = 0; i < S.size(); i++)
    {
        for (int j = 0; j < subSetSize; j++)
        {
            if ((j >> i) & 1) {
                subSets[j].push_back(S[i]);
            }
        }
    }

    return subSets;
}
