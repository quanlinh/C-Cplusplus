#include "TestRootCalculation.h"
#include "RootCalculation.h"
#include <math.h>
#include <assert.h>
#include <iostream>
#include <exception>
using namespace std;





void TestRootCalculation::testRoot()
{
	try {
		RootCalculation rootCal;
		double epsilon = 0.0001;
		double one = 1.0;
		double squareRootOne = 1.0;
		double five = 5.0;
		double squareRootFive = sqrt(5.0);
		double nine = 9.0;
		double squareRootNine = 3.0;
		double half = 0.5;
		double squaretRootHalf = sqrt(half);
		assert(rootCal.calculateSquareRoot(one) <= (squareRootOne + epsilon));
		assert(rootCal.calculateSquareRoot(one) >= (squareRootOne - epsilon));
		assert(rootCal.calculateSquareRoot(five) <= (squareRootFive + epsilon));
		assert(rootCal.calculateSquareRoot(five) >= (squareRootFive - epsilon));
		assert(rootCal.calculateSquareRoot(nine) <= (squareRootNine + epsilon));
		assert(rootCal.calculateSquareRoot(nine) >= (squareRootNine - epsilon));
		assert(rootCal.calculateSquareRoot(half) <= (squaretRootHalf + epsilon));
		assert(rootCal.calculateSquareRoot(half) >= (squaretRootHalf - epsilon));
		cout << "\n Test Root Passed \n";
	}
	catch (exception assert)
	{
		cout << "\n Test Root Failed \n";
	}

	
	
	
}
