#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <stdlib.h>
#include <vector>
#include <math.h>
using namespace std;



class Point
{
public:
  // constructor with one arguments
  // Point(double u) : x(u), y(0.0) {}
  // Point(double v) : x(0.0), y(v) {}
  // Point(double u, double v) : x(u), y(v) {}
  Point(int u, int v) : x(u), y(v) {}

  double x, y;

  bool operator==(Point other) const
  {
    return (x == other.x && y == other.y);
  }
  // This overload operator favor sorted base on X-coordinatate,
  // If there is a type we break it by y
};




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
template <class Number>
class ClosestPairOfPointsOnPlane
{
public:
  double closestPairDistance(vector<Number> &xCoordinate, vector<Number> &yCoordinate);
  vector<Point> closestPair(vector<Point> &pointsSortedByX, vector<Point> &pointSortedByY);
  double bruteForceClosestPairDistance(vector<Number> &xCoordiate, vector<Number> &yCoordinate);

private:
  double eucledianDistance(const Point &point1, const Point &point2);
  vector<Point> constructPointFromCoordinateXY(vector<Number> &xCoordinate, vector<Number> &yCoordinate);
  vector<Point> getSmallerPairOfPoint(vector<Point> &point1, vector<Point> &point2);
  vector<Point> closestSplitPair(vector<Point> &pointsSortedByX, vector<Point> &pointsSortedByY,
                                 vector<Point> &closestPairSofar);
};

struct xLessThanY
{
  bool operator()(const Point &point1, const Point &point2)
  {
    if (point1.x < point2.x)
      return true;
    else if (point1.x > point2.x)
      return false;
    else
      return point1.y < point2.y;
  }
};
struct yLessThanX
{
  bool operator()(const Point &point1, const Point &point2)
  {
    if (point1.y < point2.y)
      return true;
    else if (point1.x > point2.x)
      return false;
    else
      return point1.y < point2.y;
  }
};
template <class Number>
double ClosestPairOfPointsOnPlane<Number>::bruteForceClosestPairDistance(vector<Number> &xCoordiate, vector<Number> &yCoordinate)
{
  if (xCoordiate.size() != yCoordinate.size())
    throw exception();
  vector<Point> vectorOfPoints = constructPointFromCoordinateXY(xCoordiate, yCoordinate);
  double closestPairDistance = __DBL_MAX__;
  for (size_t i = 0; i < vectorOfPoints.size(); i++)
  {
    for (size_t j = i + 1; j < vectorOfPoints.size(); j++)
    {
      auto candidateDistance = eucledianDistance(vectorOfPoints[i], vectorOfPoints[j]);
      if (candidateDistance < closestPairDistance)
        closestPairDistance = candidateDistance;
    }
  }
  return closestPairDistance;
}

template <class Number>
double ClosestPairOfPointsOnPlane<Number>::closestPairDistance(vector<Number> &xCoordinate, vector<Number> &yCoordinate)
{
  vector<Point> arraysOfPoints = constructPointFromCoordinateXY(xCoordinate, yCoordinate);
  vector<Point> pointSortedByX(arraysOfPoints);
  vector<Point> pointSortedByY(arraysOfPoints);
  RandomizeQuickSorted<Point> rq;
  xLessThanY sortedByX;
  yLessThanX sortedByY;
  rq.quickSortedWithPredicate(pointSortedByX, sortedByX);
  // If we have duplicate elements, 0.0 return immidiately
  for (size_t i = 0; i < pointSortedByX.size() - 1; i++)
  {
    if (pointSortedByX[i] == pointSortedByX[i + 1])
      return 0.0;
  }
  rq.quickSortedWithPredicate(pointSortedByY, sortedByY);
  vector<Point> twoClosestPoint = closestPair(pointSortedByX, pointSortedByY);
  return eucledianDistance(twoClosestPoint[0], twoClosestPoint[1]);
}
/**
 * Precondition : Only two pointed is acceptep
 * throw exeception if less than two points
 * 
 * */
template <class Number>
vector<Point> ClosestPairOfPointsOnPlane<Number>::closestPair(vector<Point> &pointsSortedByX, vector<Point> &pointsSortedByY)
{
  size_t size = pointsSortedByX.size();
  if (size < 4)
  {
    if (size < 2)
      throw exception();
    if (size == 2)
      return pointsSortedByX;
    else
    {
      double distancePoint0ToPoint1 = eucledianDistance(pointsSortedByX[0], pointsSortedByX[1]);
      double distancePoint1ToPoint2 = eucledianDistance(pointsSortedByX[1], pointsSortedByX[2]);
      double distancePoint0ToPoint2 = eucledianDistance(pointsSortedByX[0], pointsSortedByX[2]);
      if (distancePoint0ToPoint1 < distancePoint0ToPoint2 && distancePoint0ToPoint1 < distancePoint1ToPoint2)
      {
        vector<Point> closestPair = {pointsSortedByX[0], pointsSortedByX[1]};
        return closestPair;
      }
      else if (distancePoint1ToPoint2 < distancePoint0ToPoint2)
      {
        vector<Point> closestPair = {pointsSortedByX[1], pointsSortedByX[2]};
        return closestPair;
      }
      else
      {
        vector<Point> closestPair = {pointsSortedByX[0], pointsSortedByX[2]};
        return closestPair;
      }
    }
  }

  size_t mid = size / 2;
  vector<Point> leftHalftSortedByX;
  for (size_t i = 0; i < mid; i++)
  {
    leftHalftSortedByX.push_back(pointsSortedByX[i]);
  }
  vector<Point> rightHalfSortedByX;
  for (size_t i = 0, j = mid; i < size - mid; i++, j++)
  {
    rightHalfSortedByX.push_back(pointsSortedByX[j]);
  }

  Point midPointOfXSorted = pointsSortedByX[mid];
  vector<Point> leftHalftSortedByY;
  vector<Point> rightHalftSortedByY;
  // This copy only correct if we assume that there is not tie on both x an y
  for (size_t i = 0; i < size; i++)
  {
    if (pointsSortedByY[i].x < midPointOfXSorted.x ||
        (pointsSortedByY[i].x == midPointOfXSorted.x && pointsSortedByY[i].y < midPointOfXSorted.y))
      leftHalftSortedByY.push_back(pointsSortedByY[i]);
    else
      rightHalftSortedByY.push_back(pointsSortedByY[i]);
  }
  vector<Point> closestPairOnLeft = closestPair(leftHalftSortedByX, leftHalftSortedByY);
  vector<Point> closestPairOnRight = closestPair(rightHalfSortedByX, rightHalftSortedByY);
  vector<Point> smallerPairSofar = getSmallerPairOfPoint(closestPairOnLeft, closestPairOnRight);
  vector<Point> splitPair = closestSplitPair(pointsSortedByX, pointsSortedByY, smallerPairSofar);
  if (splitPair.empty())
    return smallerPairSofar;
  else
  {
    return getSmallerPairOfPoint(smallerPairSofar, splitPair);
  }
}
template <class Number>
vector<Point> ClosestPairOfPointsOnPlane<Number>::closestSplitPair(vector<Point> &pointsSortedByX, vector<Point> &pointsSortedByY,
                                                                   vector<Point> &closestPairSofar)
{
  Point biggestPointOnTheLeft = pointsSortedByX[pointsSortedByX.size() / 2];
  auto theMidBarCenterX = biggestPointOnTheLeft.x;
  double smallesDistanceSofar = eucledianDistance(closestPairSofar[0], closestPairSofar[1]);
  double lowerRange = theMidBarCenterX - smallesDistanceSofar;
  double higherRange = theMidBarCenterX + smallesDistanceSofar;
  vector<Point> theSortedYPointLessThanXMidbar;

  for (Point point : pointsSortedByY)
  {
    if (lowerRange < point.x && point.x < higherRange)
    {
      theSortedYPointLessThanXMidbar.push_back(point);
    }
  }
  vector<Point> closestPairSplit;
  for (size_t i = 0; i < theSortedYPointLessThanXMidbar.size(); i++)
  {
    for (size_t j = 0; j < 7 && i + j < theSortedYPointLessThanXMidbar.size(); j++)
    {
      Point pointI = theSortedYPointLessThanXMidbar[i];
      Point pointJAroundI = theSortedYPointLessThanXMidbar[i + j];
      if (pointI == pointJAroundI)
        continue;
      if (eucledianDistance(pointI, pointJAroundI) < smallesDistanceSofar)
      {
        if (closestPairSplit.empty())
        {
          closestPairSplit.push_back(pointI);
          closestPairSplit.push_back(pointJAroundI);
        }
        else
        {
          closestPairSplit[0] = pointI;
          closestPairSplit[1] = pointJAroundI;
        }
      }
    }
  }
  return closestPairSplit;
}
template <class Number>
vector<Point> ClosestPairOfPointsOnPlane<Number>::getSmallerPairOfPoint(vector<Point> &pairPoint1, vector<Point> &pairPoint2)
{
  if (eucledianDistance(pairPoint1[0], pairPoint1[1]) < eucledianDistance(pairPoint2[0], pairPoint2[1]))
    return pairPoint1;
  else
    return pairPoint2;
}
template <class Number>
double ClosestPairOfPointsOnPlane<Number>::eucledianDistance(const Point &point1, const Point &point2)
{
  return sqrt(pow(abs(point1.x - point2.x), 2) + pow(abs(point1.y - point2.y), 2));
}

template <class Number>
vector<Point> ClosestPairOfPointsOnPlane<Number>::constructPointFromCoordinateXY(
    vector<Number> &xCoordinate, vector<Number> &yCoordinate)
{
  vector<Point> arraysOfPoints;
  for (size_t pointIndex = 0; pointIndex < xCoordinate.size(); pointIndex++)
  {
    Point point(xCoordinate[pointIndex], yCoordinate[pointIndex]);
    arraysOfPoints.push_back(point);
  }
  return arraysOfPoints;
}
int main()
{
  size_t n;
  std::cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::fixed;
  ClosestPairOfPointsOnPlane<int> cP;
  std::cout << std::setprecision(9) << cP.closestPairDistance(x, y) << "\n";
}
