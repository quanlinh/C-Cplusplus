#include <iostream>
#include "longestIncreasingSub.h"
#include <assert.h> // why failed asserted get core dump ?
class TestLongestIncreasingSub
{
  public:
    void testLIS();
    void testLISPatienceSort();

  private:
    void TestEachElement(const vector<int> a, const vector<int> b);
};