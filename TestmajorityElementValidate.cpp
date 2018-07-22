#include "TestmajorityElementValidate.h"
void TestmajorityElementValidate::testMajorityElement()
{
    majorityElementValidate mj;
    vector<int> array1 = {1, 2, 2, 3, 3, 2, 5, 0};
    vector<int> empty = {};
    vector<int> array3 = {2, 3, 9, 2, 2};
    vector<int> array4 = {1, 2, 3, 4};
    vector<int> array5 = {1, 2, 3, 1};
    vector<int> array6 = {1};
    vector<int> array7 = {1, 1};
    vector<int> array8 = {512766168, 717383758, 5, 126144732, 5, 573799007, 5, 5, 5, 405079772};
    assert(mj.majorityElementValidateDivideAndConquer(array1) == 0);
    assert(mj.majorityElementValidateDivideAndConquer(empty) == 0);
    assert(mj.majorityElementValidateDivideAndConquer(array3) == 1);
    assert(mj.majorityElementValidateDivideAndConquer(array4) == 0);
    assert(mj.majorityElementValidateDivideAndConquer(array5) == 0);
    assert(mj.majorityElementValidateDivideAndConquer(array6) == 1);
    assert(mj.majorityElementValidateDivideAndConquer(array7) == 1);
    assert(mj.majorityElementValidateDivideAndConquer(array8) == 0);

    assert(mj.majorityElementValidateBoyerAndMoore(array1) == 0);
    assert(mj.majorityElementValidateBoyerAndMoore(empty) == 0);
    assert(mj.majorityElementValidateBoyerAndMoore(array3) == 1);
    assert(mj.majorityElementValidateBoyerAndMoore(array4) == 0);
    assert(mj.majorityElementValidateBoyerAndMoore(array5) == 0);
    assert(mj.majorityElementValidateBoyerAndMoore(array6) == 1);
    assert(mj.majorityElementValidateBoyerAndMoore(array7) == 1);
    assert(mj.majorityElementValidateBoyerAndMoore(array8) == 0);
    cout << "PASSED MAJORITY TEST" << endl;
}
