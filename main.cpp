#include "TestClosestPairOfPointsOnPlane.h"
#include "TestmajorityElementValidate.h"
#include "TestRandomizedQuickSorted.h"
#include "RandomizedQuickSorted.h"
#include "TestLongestIncreasingSub.h"
#include "TestPriorityQueueBinaryHeap.h"
int main()
{
    cout << "\n TEST BEGIN \n";
    TestLongestIncreasingSub TLIS;
    TLIS.testLIS();
    TLIS.testLISPatienceSort();
    TestRandomizedQuickSorted testRandomQuickSort;
    testRandomQuickSort.testSwap();
    testRandomQuickSort.testSmallCases();
    testRandomQuickSort.testBigCases();
    testRandomQuickSort.testPickPivot();
    TestmajorityElementValidate tesMajor;
    tesMajor.testMajorityElement();

    TestPriorityQueueBinaryHeap testHeap;
    testHeap.test();
    testHeap.testHeapSorted();

    TestClosestPairOfPointsOnPlane tClosePair;
    tClosePair.testSimpleCases();
    cout << "\n TEST END \n";
    return 0;
}
