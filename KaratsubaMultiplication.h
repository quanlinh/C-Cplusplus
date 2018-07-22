#pragma once
#include <string>
#include <vector>
using namespace std;
// I should Used call by reference instead of value
class KaratsubaMultiplication
{
public:
	KaratsubaMultiplication();
	~KaratsubaMultiplication();
	string karatsubaBigMultiplication( const string &firstNumber, const  string  &secondNumber);
	string plusTwoBigIntegers(const string &firstNumbers, const string &secondNumber);
	string subtractTwoBigIntegers(const string &firstNumbers, const string &secondNumber);
private:
	vector<string> makeTwoNumberEven(const string &firstNumber, const string &secondNumber,const int &lenFirst,const int &lenSecond);

};

