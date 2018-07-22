#include "KaratsubaMultiplication.h"
#include <algorithm>		// using max, ceil, abs
#include <assert.h>	          
#include <iostream>
#include <exception>
#include <cmath>
using namespace std;
KaratsubaMultiplication::KaratsubaMultiplication()
{
}

KaratsubaMultiplication::~KaratsubaMultiplication()
{
}
// Karatsuba Multiplcation Algorithms works as follow
// divide firstNumber to a/b and divide secondNumber to c/d
// Recursively calculate a*c
// Recursively calculate b*d
// Recursively calculate (a+b)*(c+d)
// Take the differece of {(a+b)*(c+d) - a*c - b*d}
// Results would be a*c*10^n + (ad + bc)^10^(n/2) + bd
// Assume n is even numbers and both size must be equal lenghs
// Otherwise: :(
// In the case two numbers is not equals in length
// Take n =  maxlen(firstNumber,secondNumber)
// Take integer divison by two, mid = Math.ceil(n/2.0) aka. make it even when it is odd
// Take the the length of the right hand size two numbers is equals to each others. 
// And leave the rest for the left hansize: in the case of c or d is zero. Don't need to 
// call the first recursive call for calculate ac as well as padding ac*10^n
// Edge cases: 
// If two numbers is equal but the left size is less than the right size after divide 
// Example: 678 912 => a = 6 ; b = 78; c= 9; d = 12
// in this case, check n%2 !=0 for the max length, add extra 0 to it aka. lenUpperBound ++

// There is 16 numbers give wrong answer, while 17 give right answer
string KaratsubaMultiplication::karatsubaBigMultiplication(const string &firstNumber, const string &secondNumber)
{
	size_t lenFirstNumber = firstNumber.size();
	size_t lenSecondNumber = secondNumber.size();
	// long int a = 12345678901234567890;
	int lowerBound = min(lenFirstNumber,lenSecondNumber);

	if (lowerBound == 1 )
	{
		long first = stol(firstNumber);
		long second = stol(secondNumber);
		return to_string(first * second);
	}
	size_t lenUpperBound = max(lenFirstNumber, lenSecondNumber);
	// not sure how to handle the casting correct. :(
	size_t mid = ceil((static_cast<double>(lenUpperBound) / 2.0));
	size_t mid1 = lenFirstNumber - mid;
	size_t mid2 = lenSecondNumber - mid;
	// bugs may can become from here
	string a = firstNumber.substr(0, mid1);
	string b = firstNumber.substr(mid1, lenFirstNumber - mid1);
	string c = secondNumber.substr(0, mid2);
	string d = secondNumber.substr(mid2, lenSecondNumber - mid2);
	assert(a.length() <= b.length());
	assert(c.length() <= d.length());
	
	if (a.size() == 0 || c.size() == 0) 
	{
		// no need calculate for a*c
		if (a.size() == 0) a = "0";
		if (c.size() == 0) c = "0";
		
		string bd = karatsubaBigMultiplication(b, d);
		// calculate (a+b)(c+d)
		// use a for loop in reverse order to add them, if one number is carry, continue to add them up until the last one
		// will be number if carry not zero
		string aPlusB = plusTwoBigIntegers(a, b);
		string cPlusD = plusTwoBigIntegers(c, d);
		string aPlusB_cPlusD = karatsubaBigMultiplication(aPlusB, cPlusD);
		// take diff gauss 3 - 2
		string gaussTrick = subtractTwoBigIntegers(aPlusB_cPlusD, bd);

		// padding 0 to 10/2 == mid
		int i = mid;
		while (i > 0)
		{
			gaussTrick += "0";
			i--;
		}
		string res = plusTwoBigIntegers(gaussTrick, bd);

		return res;

	}
	else
	{
		string ac = karatsubaBigMultiplication(a, c);
		string bd = karatsubaBigMultiplication(b, d);

		// calculate (a+b)(c+d)
		// use a for loop in reverse order to add them, if one number is carry, continue to add them up until the last one
		// will be number if carry not zero
		string aPlusB = plusTwoBigIntegers(a, b);
		string cPlusD = plusTwoBigIntegers(c, d);
		string aPlusB_cPlusD = karatsubaBigMultiplication(aPlusB, cPlusD);
		// take diff gauss 3 - 2 - 1
		string gaussTrick = subtractTwoBigIntegers(aPlusB_cPlusD, bd);exception
		try {
			gaussTrick = subtractTwoBigIntegers(gaussTrick, ac);
		} catch(exception e)
		{
			cout << "empty string, has been provide" endl;
		}

		if (lenUpperBound % 2 != 0) lenUpperBound += 1;
		int i = lenUpperBound;
		while (i > 0) 		
		{
			ac = ac + "0";
			i--;
		}

		int j = mid;
		while (j > 0)
		{
			gaussTrick += "0";
			j--;
		}
		// padding 0 to 10/2 == mid
		string res = plusTwoBigIntegers(ac, gaussTrick);
		res = plusTwoBigIntegers(res, bd);

		return res;
	}
}
// Interesting: size() and length are the same :) for string
string KaratsubaMultiplication::plusTwoBigIntegers(const string &firstNumbers, const string  &secondNumber)
{
	int lenFirst  = firstNumbers.size();
	int lenSecond = secondNumber.size();
	string firstNumberLocal = firstNumbers;
	string secondNumberLocal = secondNumber;
	if (lenFirst == 0 || lenSecond == 0) throw string("the string empty is not supported in add two integers");

	// the cutoff is 9 digits

	// add normally if their length is less than 19
	// since long  can hold up to 10 digits and 
	// max values of 99....99 + 99...99 <= 10 digits
	if (lenFirst < 10 && lenSecond < 10) 
	{
		return to_string(stol(firstNumberLocal) + stol(secondNumberLocal));
	} 
	else 
	{
		// equalize two strings if they are not equals by padding 0 at the begin
		if (lenFirst != lenSecond)
		{
			vector<string> pairsNumber = makeTwoNumberEven(firstNumberLocal, secondNumberLocal, lenFirst, lenSecond);
			firstNumberLocal = pairsNumber[0];
			secondNumberLocal = pairsNumber[1];
		}
		
		int remainingLen = firstNumberLocal.length();
		// cut off length until it reachs to a point the remaining 
		// len in the left hand size is less than or equals 9
		long carry = 0;
		string sum = "";
		// try to think a way to make sure everything is cover since there 
		// is a cases it only cover the first half
		// The edgecases with carry :( when use it already, it should be reset.
		while (remainingLen > 8)
		{
			remainingLen -= 9;
			string firstPartition  = firstNumberLocal.substr(remainingLen, 9);
			string secondPartition = secondNumberLocal.substr(remainingLen, 9);
			long numericRes = stol(firstPartition) + stol(secondPartition) + carry;
			carry = 0;
			string resPartition = to_string(numericRes);
			if (resPartition.length() > 9)
			{
				// The carry position is not number 1 as I expected, but it is 49
				//carry = resPartition[0];  // get the number carry at position 0
				carry = stol(resPartition.substr(0, 1));
				sum = resPartition.substr(1,9) + sum;
			} 
			// cases were found when leading is zeros, and had been remove after plus
			else if (resPartition.length() < 9)
			{
				int i = 9 - resPartition.length();
				while (i > 0)
				{
					resPartition = "0" + resPartition;
					i--;
				}

				sum = resPartition + sum;
			}
			else { sum = resPartition + sum; }

			// process the last part and break if the next subtract 9 len is less than 9
			if (remainingLen - 9 < 1)			
			{
				// the left parts in them 
				string firstPartition  = firstNumberLocal.substr(0, remainingLen);
				string secondPartition = secondNumberLocal.substr(0, remainingLen);

				long numericRes = stol(firstPartition) + stol(secondPartition) + carry;
				// reset carry to zero, since it already being used
				carry = 0;
				string resPartition = to_string(numericRes);

				sum = resPartition + sum;
				break;
			}
		}
		return sum;
	}
	
}
// This function takes to input string the first number is the subtraction number,
// the second is the the number need to be to subtract

string KaratsubaMultiplication::subtractTwoBigIntegers(const string &firstNumbers, const string &secondNumber)
{
	// 1) The first thing we need to do is to compare the first left most digit
	//  a. If we have a small number in the subtracion number we flip the order
	//  b. The results order will be negative with string "-"
	// 2) Else we procee normally
	// 3) Inorder to subtract two numbers, we need to calculate first, it the partition is 
	// turn out to be less than 0
	// a. If so, we need to borrow from the left hand size fo the numbers
	//  => In case it is >= 1, we minus 1 from that number at that position
	//  => in case it 0, we set it to 9, and we move to next left position until we find  >=1
	//		-> We minus 1 from that, and took add it to begegging of the right hand sides strings
	//		-> (continue) and procees normally.( left numbers as 9, since they may need borrow
	// 4) Repeated ly remove every things if the results is leading with 0
	
	int lenFirst = firstNumbers.length();
	int lenSecond = secondNumber.length();
	string firstNumberLocal = firstNumbers;
	string secondNumberLocal = secondNumber;
	if (lenFirst == 0 || lenSecond == 0) throw string("the string empty is not supported in add two integers");
	if (lenFirst < 10 && lenSecond < 10) return to_string(stol(firstNumberLocal) - stol(secondNumberLocal));	
	else
	{
		if (lenFirst != lenSecond)
		{
			vector<string> pairsNumbers = makeTwoNumberEven(firstNumberLocal, secondNumberLocal, lenFirst, lenSecond);
			firstNumberLocal = pairsNumbers[0];
			secondNumberLocal = pairsNumbers[1];
		}
		// hanlde negative sign, but something wrongs with karatsuba algorihtms, it 
		// should not be negative here
		long firstLeftMostDigit  = stol(firstNumberLocal.substr(0, 1));
		long secondLeftMostDigit = stol(secondNumberLocal.substr(0, 1));
		string sign = "";
		// The most significant digits is less than, we need to flip the numbers
		// to able to proceed the subtractions 
		if (firstLeftMostDigit - secondLeftMostDigit < 0)
		{
			string temp = firstNumberLocal;
			firstNumberLocal = secondNumberLocal;
			secondNumberLocal = temp;
			sign = "-";
		}

		int remainLen = firstNumberLocal.length();
		string diff = "";
		while (remainLen > 8)
		{
			remainLen -= 9;
			string firstPartition  = firstNumberLocal.substr(remainLen, 9);
			string secondPartition = secondNumberLocal.substr(remainLen, 9);

			long checkSubtract = stol(firstPartition) - stol(secondPartition);
			// need borrowed since it not enough numbers to subtract
			if (checkSubtract < 0)
			{
				int pointerToTheLeftSubstring = remainLen - 1;
				while (firstNumberLocal.substr(pointerToTheLeftSubstring, 1).compare("0") == 0)
				{
					// replace it with 9 at that position
					firstNumberLocal.replace(pointerToTheLeftSubstring, 1, "9");
					pointerToTheLeftSubstring--;
					// this never should happens
					if (pointerToTheLeftSubstring < 0) break;
				}
				// reach a number that > 0
				string minusOneFromBorrowing = to_string(stol(firstNumberLocal.substr(pointerToTheLeftSubstring, 1)) - 1);
				firstNumberLocal.replace(pointerToTheLeftSubstring, 1, minusOneFromBorrowing);
				checkSubtract = stol("1" + firstPartition) - stol(secondPartition);
			}
			// I think I still need to check whether the results have 0  sice it drop zeros after subtract, 
			// need to add them back
			string resPartition = to_string(checkSubtract);
			while (resPartition.length() < 9) resPartition = "0" + resPartition;

			diff = resPartition + diff;

			// since we already flip the bigger numbers, the last part of subtraction numbers
			// must be greater or equals the second parts, but still have to check for zero !
			// Do not confused between leading zeros with the righ hand sizes 0, since it does not need 
			// to be replaces; however, the next part such as "0" + "0" or need to be replaces
			if (remainLen - 9 < 1)
			{
				string firstPartition = firstNumberLocal.substr(0, remainLen);
				string secondPartition = secondNumberLocal.substr(0, remainLen);
				long checkSubtract = stol(firstPartition) - stol(secondPartition);
				if (checkSubtract != 0)
				{
					string resPartition = to_string(checkSubtract);
					diff = sign + resPartition + diff;
					break;
				}
				else
				{
					diff = to_string(checkSubtract) + diff;
					// The keys here to recognize after being replace 
					// with empty strings, the string is automatically
					// shift to the left
					while (diff.substr(0, 1).compare("0") == 0) diff.replace(0, 1, "");					
					if (diff.empty()) diff = "0";
					else diff = sign + diff;
				}
			}
		}

		return diff;

	}
}

vector<string> KaratsubaMultiplication::makeTwoNumberEven(const string &firstNumber, const string &secondNumber,const int &lenFirst,const int &lenSecond)
{
	string padding = "";
	int differenceLen = abs(lenFirst - lenSecond);
	while (padding.length() != differenceLen) padding = padding + "0";
	string firstNumberLocal = firstNumber;
	string secondNumberLocal = secondNumber;
	if (lenFirst > lenSecond) secondNumberLocal = padding + secondNumberLocal;
	else					  firstNumberLocal = padding + firstNumberLocal;
	vector<string> pairNumbers(2);
	pairNumbers[0]= firstNumberLocal;
	pairNumbers[1]= secondNumberLocal;
	return pairNumbers;
}
