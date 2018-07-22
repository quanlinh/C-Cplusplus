#pragma once
// TODO: find out how to use destructor correctly
class RootCalculation
{
public:
	double calculateSquareRoot(double n);
	~RootCalculation();
private:
	double BinsectionSearch(double n, double lo, double hi, double epsilon);
};

