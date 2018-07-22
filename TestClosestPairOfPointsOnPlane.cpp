#include <iostream>
#include "TestClosestPairOfPointsOnPlane.h"
void TestClosestPairOfPointsOnPlane::testSimpleCases()
{
    ClosestPairOfPointsOnPlane<int> cP;

    vector<int> twoPointsX = {0, 3};
    vector<int> twoPointsY = {0, 4};
    assert(cP.closestPairDistance(twoPointsX, twoPointsY) == 5.0);

    vector<int> fourPointsDuplicateX = {7, 1, 4, 7};
    vector<int> fourPointsDuplicateY = {7, 100, 8, 7};
    assert(cP.closestPairDistance(fourPointsDuplicateX, fourPointsDuplicateY) == 0.0);
    vector<int> elevenPointsX = {4, -2, -3, -1, 2, -4, 1, -1, 3, -4, -2};
    vector<int> elevenPointsY = {4, -2, -4, 3, 3, 0, 1, -1, -1, 2, 4};

    assert(cP.closestPairDistance(elevenPointsX, elevenPointsY) == sqrt(2));

    vector<int> fourPointsX = {7, 1, 4, 6};
    vector<int> fourPointsY = {7, 100, 8, 6};
    assert(cP.closestPairDistance(fourPointsX, fourPointsY) == sqrt(2));
    assert(cP.closestPairDistance(fourPointsX, fourPointsY) == cP.bruteForceClosestPairDistance(fourPointsX, fourPointsY));
    vector<int> x1 = {94162, 1817, 40563, 47224, 74510, 1952, 57252, 78843, 90027, 70620, 9364, 43228, 87053, 40154,
                      43108, 8526, 78761, 97996, 99425, 12128, 7872, 17761, 9942, 39976, 1993, 90848, 23386, 66475, 74733,
                      43681, 55177, 38091, 95020, 60488, 57585, 93773, 56349, 32670, 76003, 78150, 42802, 10926, 16233,
                      73091, 27898, 10649, 16247, 97617, 23424, 50167, 80378, 85679, 69680, 5995, 38093, 63086, 31994,
                      10081, 26122, 32033, 23951, 27270, 44061, 92199, 8840, 64772, 70004, 37619, 75847, 50489, 43667,
                      99636, 2677, 12147, 98053, 46950, 49130, 77706, 11820, 87636, 74122, 43674, 32409, 83975, 36269,
                      44443, 90967, 46800, 74231, 83198, 35650, 93934, 88742, 56231, 95861, 92733, 27307, 57954, 30977,
                      3163};
    vector<int> y1 = {98630, 52728, 14944, 50244, 93289, 6228, 59083, 94586, 24455, 36092, 41784, 27803, 35611,
                      138, 51064, 20661, 9814, 25085, 10998, 97370, 13259, 28101, 77877, 81824, 67015, 34632, 91670,
                      38097, 45694, 7471, 20182, 30096, 88288, 28369, 46996, 57129, 19371, 96889, 47504, 60403, 21018,
                      82774, 26671, 44582, 86331, 71583, 99675, 23763, 67551, 24193, 1256, 79268, 34826, 98278, 25809,
                      74160, 86538, 57220, 97504, 99835, 26820, 66527, 1836, 71560, 31049, 21276, 22269, 4220, 3880,
                      34307, 83691, 30513, 90302, 29135, 72580, 31027, 55208, 44438, 35725, 85306, 3641, 83088, 48512,
                      58597, 31367, 32582, 80243, 7727, 75455, 13048, 9689, 93489, 1017, 34602, 88802, 8756, 63110, 97356,
                      92990, 72657};
    assert(cP.closestPairDistance(x1, y1) == 603.0406288136812);
    vector<int> tenRandomX = {41333, 73225, 94829, 20960, 4343, 42655, 28353, 73301, 94457, 84876};
    vector<int> tenRandomY = {49423, 20397, 61209, 18118, 44466, 53710, 66407, 92718, 3301, 84781};
    assert(cP.bruteForceClosestPairDistance(tenRandomX, tenRandomY) == cP.closestPairDistance(tenRandomX, tenRandomY));
    size_t trialAndErrof = 0;
    while (trialAndErrof++ < 1000)
    {
        size_t sizeRandomArray = 10000;
        vector<int> randomArrayX(sizeRandomArray);
        vector<int> randomArrayY(sizeRandomArray);
        for (size_t i = 0; i < sizeRandomArray; i++)
        {
            randomArrayX[i] = rand() % (1000);
            randomArrayY[i] = rand() % (1000) + 15;
        }

        if (cP.bruteForceClosestPairDistance(randomArrayX, randomArrayY) != cP.closestPairDistance(randomArrayX, randomArrayY))
        {
            cout << cP.bruteForceClosestPairDistance(randomArrayX, randomArrayY);
            cout << cP.closestPairDistance(randomArrayX, randomArrayY);
            break;
        }
    }

    cout << "PASSED CLOSEST PAIR OF POINTS\n";
}
