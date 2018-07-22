#include "RootCalculation.h"
#include <exception>
#include <iostream>
using namespace std;


double RootCalculation::calculateSquareRoot(double n)
{
	double epsilon = 0.0001;
	if (n >= 1) return BinsectionSearch(n, 1.0, n, epsilon);
	else        return BinsectionSearch(n, 0.0, 1.0 - epsilon, epsilon);
	cout << "Square Root of Negative Number is undefine";
	return -1.0;
}





double RootCalculation::BinsectionSearch(double n, double lo, double hi, double epsilon)
{
	double mid = (lo + hi) / 2;
	if (abs(mid*mid - n) <= epsilon) return mid;
	else if (mid*mid > n)		     return BinsectionSearch(n, lo, mid, epsilon);
	else							 return BinsectionSearch(n, mid, hi, epsilon);
}

RootCalculation::~RootCalculation()
{

}





