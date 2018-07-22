#include "TestRandomizedQuickSorted.h"
#include <algorithm>
#include <fstream>
#include <vector>
void TestRandomizedQuickSorted::testSmallCases()
{
    RandomizeQuickSorted<int> qs;
    vector<int> empty = {};
    vector<int> one = {1};
    qs.quickSorted(empty);
    qs.quickSorted(one);
    assert(empty.size() == 0);
    assert(one[0] == 1);
    vector<int> a1 = {2, 2, 2, 2, 2, 2, 1};
    vector<int> a1_expected = {1, 2, 2, 2, 2, 2, 2};
    qs.quickSorted(a1);

    for (int i = 0; i < a1.size(); i++)
    {
        // cout << a1[i] << "\n";
        assert(a1[i] == a1_expected[i]);
    }
    // Test swap

    cout << "\n  PASSED SMALL CASES \n"
         << endl;
}

void TestRandomizedQuickSorted::testBigCases()
{
    RandomizeQuickSorted<int> qs;
    vector<int> randomArray(10000);
    for (int i = 0; i < randomArray.size(); i++)
    {
        randomArray[i] = rand() % (1000);
    }
    vector<int> copyRandomArray(randomArray);
    qs.quickSorted(copyRandomArray);
    sort(randomArray.begin(), randomArray.end());
    for (int i = 0; i < randomArray.size(); i++)
    {
        assert(copyRandomArray[i] == randomArray[i]);
    }

    cout << "\n  PASSED BIG CASES \n";
}

void TestRandomizedQuickSorted::testSwap()
{
    int a = 5;
    int b = 6;
    RandomizeQuickSorted<int> qs;
    qs.swapElement(a, b);
    assert(a == 6 && b == 5);
    cout << "\n  PASSED SMALL CASES \n"
         << endl;
}
void TestRandomizedQuickSorted::testPickPivot()
{
    vector<int> quickSortArray1;
    vector<int> quickSortArray2;
    vector<int> quickSortArray3;

    ifstream inFile;
    int x;
    inFile.open("/home/qtran/IdeaProjects/AlgorithmsCodingJava/AlgorithmStanford1000IntegersQuickSorted.txt");
    if (!inFile)
    {
        cout << "\n Unable to open file \n ";
        exit(1); // terminate with error
    }

    while (inFile >> x)
    {
        quickSortArray1.push_back(x);
        quickSortArray2.push_back(x);
        quickSortArray3.push_back(x);

    }
    inFile.close();
    RandomizeQuickSorted<int> rQS;
    size_t first = rQS.twoWayPartitioningPickingPivot(quickSortArray1, 0, quickSortArray1.size()-1, 0, 0);
    size_t last = rQS.twoWayPartitioningPickingPivot(quickSortArray2, 0, quickSortArray2.size()-1,0,1);
    size_t threeMedian = rQS.twoWayPartitioningPickingPivot(quickSortArray3, 0, quickSortArray3.size()-1,0,2);
    assert(first==162085);
    assert(last==164123);
    assert(threeMedian==138382);
    cout << "PASSED PICKING PIVOT OF QUICKSORTED" << "\n";
}