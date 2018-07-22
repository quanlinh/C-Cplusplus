#ifndef RANDOMIZEQUICKSORTED_H
#define RANDOMIZEQUICKSORTED_H
#pragma once

#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

template <class Type>
class RandomizeQuickSorted
{
public:
  template <typename Predicate> // template method
  void quickSortedWithPredicate(vector<Type> &nums, Predicate &predicate);
  void quickSorted(vector<int> &nums);
  template <typename Predicate>
  void randomizedQuickSortedWithPredicate(vector<Type> &nums, const size_t lo, const size_t hi, Predicate &predicate);
  void randomizedQuickSorted(vector<Type> &nums, const size_t lo, const size_t hi);
  template <typename Predicate>
  vector<size_t> threeWayPartioningWithPredicate(vector<Type> &nums, size_t lo, size_t hi, Predicate &predicate);
  vector<size_t> threeWayPartioning(vector<Type> &nums, const size_t lo, const size_t hi);
  void swapElement(Type &a, Type &b);
  size_t twoWayPartitioningPickingPivot(vector<int> &nums, const int lo, const int hi, size_t numberOfComparision, const size_t wayToPickPivot);
  int twoWayPartioningPickFirstElement(vector<int> &nums, const int lo, const int hi);
  int medianOfTheThree(vector<int> &nums, int lo, int mid, int hi);
};

// #include <vector>
// using namespace std;
// Is it shuffle the array and picking up random pivot means the same things?
// YES.
// The key ideas here is Quicksorted work for every input at the average running
// time of O(nlogn).
// The way to guranteed this is because we pick the pivot randomly, internally in
// our codes or programs. So the randomized algorithms really random and there
// is not luck.
// There are two ways to solved it.
// One is to shuffle the arrays, which make the
// the input random, and choosed a fixed pivot.
// Second is pick a random pivot everytime we choose in each recursive called.
// 3 way partitioning
// Goal: Partition array into 3 parts so that:
// Entries between less than and greater than equal to partition item v.
// No larger entries to left of less than
// No smaller entries to the right of greater than.
// Dijstra 3-way partitioning
// -> Let v be partitioning item a[pivot], pick a random pivot or a[lo] if the array had been shuffle
// -> Scan i from left to right.
// -> (a[i]  < v): exchange a[lt] with a[i]; increment both lessThan and i
// -> (a[i]  > v): exchange a[gt] with a[i]; decrement only greaterThan
// -> (a[i] == v): increment i

// assume pivot had been place to the left most of the array by the caller
// What is the condtion we wan to guranteed for pivot to return in parition ?
// Return two elements of left equals and right equals
// Lessons today, don't give up your dream just because the time it takes
// to achive it.
// Real things, when it said something is not recognize, the name maybe wrong.
template <class Type>
template <typename Predicate>
void RandomizeQuickSorted<Type>::quickSortedWithPredicate(vector<Type> &nums, Predicate &predicate)
{
  size_t size = nums.size();
  if (size < 2)
    return;
  randomizedQuickSortedWithPredicate(nums, 0, nums.size() - 1, predicate);
}

template <class Type>
void RandomizeQuickSorted<Type>::quickSorted(vector<int> &nums)
{
  size_t size = nums.size();
  if (size < 2)
    return;
  randomizedQuickSorted(nums, 0, nums.size() - 1);
}

template <class Type>
void RandomizeQuickSorted<Type>::randomizedQuickSorted(vector<Type> &nums, size_t lo, size_t hi)
{
  if (lo >= hi)
    return;
  // rand() return a integers between a 0 and rand max
  size_t pivot = lo + rand() % (hi - lo + 1);
  swapElement(nums[lo], nums[pivot]);
  vector<size_t> twoIndex = threeWayPartioning(nums, lo, hi);
  randomizedQuickSorted(nums, lo, twoIndex[0]);
  randomizedQuickSorted(nums, twoIndex[1], hi);
}

template <class Type>
template <typename Predicate>
void RandomizeQuickSorted<Type>::randomizedQuickSortedWithPredicate(vector<Type> &nums, size_t lo, size_t hi, Predicate &predicate)
{
  if (lo >= hi)
    return;
  // rand() return a integers between a 0 and rand max
  size_t pivot = lo + rand() % (hi - lo + 1);
  swapElement(nums[lo], nums[pivot]);
  vector<size_t> twoIndex = threeWayPartioningWithPredicate(nums, lo, hi, predicate);
  randomizedQuickSortedWithPredicate(nums, lo, twoIndex[0], predicate);
  randomizedQuickSortedWithPredicate(nums, twoIndex[1], hi, predicate);
}

template <class Type>
size_t RandomizeQuickSorted<Type>::twoWayPartitioningPickingPivot(vector<int> &nums, const int lo, const int hi, size_t numberOfComparision, const size_t wayToPickPivot)
{
  if (lo >= hi)
    return 0;
  if (wayToPickPivot == 1)
    swapElement(nums[lo], nums[hi]);
  else if (wayToPickPivot == 2)
  {
    int midIndex = lo + (hi - lo) / 2;
    midIndex = medianOfTheThree(nums, lo, midIndex, hi);
    if (midIndex != lo)
      swapElement(nums[lo], nums[midIndex]);
  }

  size_t pivotIndex = twoWayPartioningPickFirstElement(nums, lo, hi);
  size_t countingLeftComparison = twoWayPartitioningPickingPivot(nums, lo, pivotIndex - 1, numberOfComparision, wayToPickPivot);
  size_t countingRightComparison = twoWayPartitioningPickingPivot(nums, pivotIndex + 1, hi, numberOfComparision, wayToPickPivot);
  numberOfComparision += (hi - lo) + countingLeftComparison + countingRightComparison;
  return numberOfComparision;
}

template <class Type>
int RandomizeQuickSorted<Type>::medianOfTheThree(vector<int> &nums, int lo, int mid, int hi)
{
  if ((nums[hi] < nums[lo] && nums[lo] < nums[mid]) || (nums[mid] < nums[lo] && nums[lo] < nums[hi]))
    return lo;
  else if ((nums[hi] < nums[mid] && nums[mid] < nums[lo]) || (nums[lo] < nums[mid] && nums[mid] < nums[hi]))
    return mid;
  else
    return hi;
}

template <class Type>
int RandomizeQuickSorted<Type>::twoWayPartioningPickFirstElement(vector<int> &nums, const int lo, const int hi)
{
  int pivotValue = nums[lo];
  int lessThanPivot = lo + 1;
  for (int greaterThanPivot = lessThanPivot; greaterThanPivot <= hi; greaterThanPivot++)
  {
    if (nums[greaterThanPivot] < pivotValue)
    {
      swapElement(nums[lessThanPivot], nums[greaterThanPivot]);
      lessThanPivot++;
    }
  }
  nums[lo] = nums[lessThanPivot - 1];
  nums[lessThanPivot - 1] = pivotValue;
  return lessThanPivot - 1;
}

template <class Type>
vector<size_t> RandomizeQuickSorted<Type>::threeWayPartioning(vector<Type> &nums, size_t lo, size_t hi)
{
  Type pivotValue = nums[lo];
  size_t lessThan = lo;
  size_t greaterThan = hi;
  size_t i = lo + 1;
  while (lessThan <= i && i <= greaterThan)
  {
    if (nums[i] < pivotValue)
    {
      swapElement(nums[lessThan], nums[i]);
      lessThan++;
      i++;
    }
    else if (nums[i] > pivotValue)
    {
      swapElement(nums[greaterThan], nums[i]);
      greaterThan--;
    }
    else
      i++;
  }
  vector<size_t> twoIndex = {lessThan, i};
  return twoIndex;
}

template <class Type>
template <typename Predicate>
vector<size_t> RandomizeQuickSorted<Type>::threeWayPartioningWithPredicate(vector<Type> &nums, size_t lo, size_t hi, Predicate &predicate)
{
  Type pivotValue = nums[lo];
  size_t lessThan = lo;
  size_t greaterThan = hi;
  size_t i = lo + 1;
  while (lessThan <= i && i <= greaterThan)
  {
    if (predicate(nums[i], pivotValue))
    // if (nums[i] < pivotValue)
    {
      swapElement(nums[lessThan], nums[i]);
      lessThan++;
      i++;
    }
    else if (!predicate(nums[i], pivotValue))
    // else if (nums[i] > pivotValue)
    {
      swapElement(nums[greaterThan], nums[i]);
      greaterThan--;
    }
    else
      i++;
  }
  vector<size_t> twoIndex = {lessThan, i};
  return twoIndex;
}
template <class Type>
void RandomizeQuickSorted<Type>::swapElement(Type &a, Type &b)
{
  Type temp = a;
  a = b;    // change value of a to b
  b = temp; //  change value b to a
}

#endif