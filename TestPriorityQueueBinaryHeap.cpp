#include <assert.h>
#include "TestPriorityQueueBinaryHeap.h"
#include "RandomizedQuickSorted.h"
#include <iostream>
#include <vector>
#include <algorithm>
void TestPriorityQueueBinaryHeap::test()
{
    size_t value = 10;
    PriorityQueueBinaryHeap<int> integerQueue; // it is able to create objects, but it can not
                                               //    // call the function inside that class
    integerQueue.insert(1);
    // cout << " min \t " << integerQueue.removeMin() << " \n ";

    integerQueue.insert(2);
    // cout << " min \t " << integerQueue.removeMin();

    integerQueue.insert(3);
    integerQueue.insert(4);
    integerQueue.insert(5);
    integerQueue.insert(6);
    integerQueue.insert(8);
    integerQueue.insert(9);
    integerQueue.insert(7);
    integerQueue.insert(4);
    integerQueue.insert(5);
    integerQueue.insert(6);
    integerQueue.insert(-1);
    integerQueue.insert(3);
    integerQueue.insert(4);
    integerQueue.insert(5);
    integerQueue.insert(6);
    integerQueue.insert(8);
    integerQueue.insert(9);
    integerQueue.insert(7);
    integerQueue.insert(4);
    integerQueue.insert(5);
    integerQueue.insert(6);
    integerQueue.insert(-1);
    integerQueue.insert(3);
    integerQueue.insert(4);
    integerQueue.insert(5);
    integerQueue.insert(6);
    integerQueue.insert(8);
    integerQueue.insert(9);
    integerQueue.insert(7);
    integerQueue.insert(4);
    integerQueue.insert(5);
    integerQueue.insert(6);
    integerQueue.insert(-1);
    // cout << " last but not least \n";
    // cout << " min \t " << integerQueue.removeMin();
    // cout << " min \t " << integerQueue.removeMin();
    // cout << " min \t " << integerQueue.removeMin();
    // cout << " min \t " << integerQueue.removeMin();
    size_t sizeRandomArray = 1000;
    RandomizeQuickSorted<int> qs;
    vector<int> rd;
    rd.reserve(sizeRandomArray);
}
void TestPriorityQueueBinaryHeap::testHeapSorted()
{
    size_t sizeRandomArray = 10000;
    RandomizeQuickSorted<int> qs;
    vector<int> randomArray(sizeRandomArray);
    for (size_t i = 0; i < randomArray.size(); i++)
    {
        randomArray[i] = rand() % (1000);
    }
    vector<int> copyRandomArray(randomArray);
    qs.quickSorted(copyRandomArray);

    PriorityQueueBinaryHeap<int> pq;
    for (size_t i = 0; i < sizeRandomArray; i++)
    {
        pq.insert(randomArray[i]);
    }
    vector<int> heapSortedArray(sizeRandomArray);
    for (size_t i = 0; i < sizeRandomArray; i++)
    {
        heapSortedArray[i] = pq.removeMin();
    }
    for (size_t i = 0; i < sizeRandomArray; i++)
    {
        assert(heapSortedArray[i] == copyRandomArray[i]);
    }
    cout << "PASSED HEAPSORTED TEST \n";
}