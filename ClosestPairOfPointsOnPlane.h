#ifndef CLOSESTPAIROFPOINTSONPLANE_H
#define CLOSESTPAIROFPOINTSONPLANE_H
#include <stdlib.h>
#include <vector>
#include "RandomizedQuickSorted.h"
#include "Point.h"
#include <math.h>
#include <iostream>
using namespace std;
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

#endif