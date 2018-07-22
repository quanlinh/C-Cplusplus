#pragma once
#ifndef PRIORITYQUEUEBINARYHEAP_H_
#define PRIORITYQUEUEBINARYHEAP_H_
#include <vector>
#include <string.h>
#include <iostream>
// The most important lesson to learn. 
// 1) Vector is well tests, using it much easier than use Type Array
// 2) Template class in C++ is powerful and complicated
// 3) C/C++ is a language have to know as as PROFESSIONAL SOFTWARE DEVELOPER: NOT AN OPTION :)
// template<class C> says that C is a type name; it need not be the name of a class
// C++ Proramming language special edition page 328
// This syntax create a generic class for priority
// binary heap
// use PirorityQueueBinaryHeap<Type> name; to called it
// We do not have to do resize in c++ vector, which is great
using namespace std;
template <class Type>
class PriorityQueueBinaryHeap
{
private:
  size_t sizeofQueue = 0;
  enum
  {
    DEFAULT_CAPACITY = 10
  };
  // Type *priorityQueue; // hold queue items3
  vector<Type> priorityQueue;
  size_t sizeOfQueue;
  // size_t capacity;
  void swim(size_t index);
  void sink(size_t index);
  // void resize();
  inline bool less(const Type &a, const Type &b) { return a < b; }

public:
  explicit PriorityQueueBinaryHeap(size_t size = DEFAULT_CAPACITY); // extra one for 0_index
  inline size_t sizeOfPriorityQueue() { return sizeOfQueue; }
  void insert(const Type &value);
  Type removeMin(); // return a type value min that in the queue
  // An overload operator so client can use the = to left hand side
  // PriorityQueueBinaryHeap &operator=(const PriorityQueueBinaryHeap &pq);
  // we need extra one member to store the root is null
};
// The operator to able to created new priority queue from this task
// template <class Type>
// PriorityQueueBinaryHeap<Type> &PriorityQueueBinaryHeap<Type>::operator=(const PriorityQueueBinaryHeap<Type> &pq)
// {
//   if (this == &pq)
//     return *this;
//   delete[] priorityQueue;
//   sizeOfQueue = pq.sizeOfQueue;
//   priorityQueue = new Type[sizeOfQueue];
//   for (int i = 0; i < sizeOfQueue; i++)
//     priorityQueue[i] = pq.priorityQueue[i];
//   return *this;
// }
template <class Type>
PriorityQueueBinaryHeap<Type>::PriorityQueueBinaryHeap(size_t size) : priorityQueue(size + 1), sizeOfQueue(0)
{
  // priorityQueue(size+1);
}
template <class Type>
void PriorityQueueBinaryHeap<Type>::insert(const Type &value)
{
  if (sizeOfQueue >= priorityQueue.size() - 1)
  {
    priorityQueue.resize(2*sizeOfQueue);
  }
  priorityQueue[++sizeOfQueue] = value; // move pointer before set the value to it
  swim(sizeOfQueue);
}


template <class Type>
Type PriorityQueueBinaryHeap<Type>::removeMin()
{
  Type minValue = priorityQueue[1];
  priorityQueue[1] = priorityQueue[sizeOfQueue--];
  priorityQueue.pop_back();
  sink(1);
  return minValue;
}
/** This method will swim the last element in the vector up to it right places
 **/

template <class Type>
void PriorityQueueBinaryHeap<Type>::swim(size_t childrenIndex)
{
  while (childrenIndex > 1) // if size == 0, this is the root we ignore for easy arithmetic operatoins
  {
    // cout << " go here " ;
    size_t parentIndex = childrenIndex / 2;
    if (less(priorityQueue[childrenIndex], priorityQueue[parentIndex]))
    {
      // cout << " should not go here \n";
      swap(priorityQueue[parentIndex], priorityQueue[childrenIndex]);
      childrenIndex = parentIndex;
    }
    else
    {
      break;
    }
  }
}

/**
 * This method will keep the invariants of order of the elements in
 * the heap.
 */

template <class Type>
void PriorityQueueBinaryHeap<Type>::sink(size_t parentIndex)
{

  while (static_cast<bool>(2 * parentIndex <= sizeOfQueue))
  {
    size_t leftChildIndex = 2 * parentIndex;
    size_t rightChildIndex = leftChildIndex + 1;
    if (static_cast<bool>(leftChildIndex < sizeOfQueue) &&
        less(priorityQueue[rightChildIndex], priorityQueue[leftChildIndex]))
    {
      leftChildIndex = rightChildIndex;
    }

    if (less(priorityQueue[parentIndex], priorityQueue[leftChildIndex]))
    {
      break;
    }
    swap(priorityQueue[leftChildIndex], priorityQueue[parentIndex]);
    parentIndex = leftChildIndex;
  }
}
#endif