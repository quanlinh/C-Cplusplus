#include "karatsubaMultiplicationTesting.h"
#include "KaratsubaMultiplication.h"
#include <assert.h>
#include <iostream>


// This is the constructor for :(
karatsubaMultiplicationTesting::karatsubaMultiplicationTesting()
{
	
}


karatsubaMultiplicationTesting::~karatsubaMultiplicationTesting()
{
	
}

void karatsubaMultiplicationTesting::testKarasuba()
{
	KaratsubaMultiplication kat;
	string first  = "3141592653589793238462643383279502884197169399375105820974944592";
	string second = "2718281828459045235360287471352662497757247093699959574966967627";
	string res =	  "8539734222673567065463550869546574495034888535765114961879601127067743044893204848617875072216249073013374895871952806582723184";
	string resPrint = "8539734222673567065463550869546574495034888535765114961879601127067743044893204848617875072216249073013374895871952806582723184";
	// string a = "3430012370529730";
	// string c = "8968057553168415";
	string b = "02884197169399375105820974944592";
	string d = "62497757247093699959574966967627";
	assert(kat.karatsubaBigMultiplication(first, second).compare(res) == 0);
	

}

void karatsubaMultiplicationTesting::testKaratSubaOddNumbers()
{
	KaratsubaMultiplication kat;
	string firstNumber = "567";
	string secondNumber = "912";
	string res1 = "517104";
	assert(kat.karatsubaBigMultiplication(firstNumber, secondNumber).compare(res1) == 0);
	string case1 = "12345";
	string case2 = "678";
	string resCase12 = to_string(stol(case1) * stol(case2));
	assert(kat.karatsubaBigMultiplication(case1, case2).compare(resCase12) == 0);
	string case3 = "1274";
	string case4 = "132";
	string resCase34 = to_string(stol(case3) * stol(case4));
	assert(kat.karatsubaBigMultiplication(case3, case4).compare(resCase34) == 0);
	string case5 = "85741";
	string case6 = "93424";

	string resCase56 = "8010267184";	
	assert(kat.karatsubaBigMultiplication(case5, case6).compare(resCase56) == 0);
}

void karatsubaMultiplicationTesting::testKaratSubaEvenNumbers()
{
	KaratsubaMultiplication kat;
	string firstNumber = "1234";
	string secondNumber = "5678";

	assert(kat.karatsubaBigMultiplication(firstNumber, secondNumber).compare("7006652")==0);

}


void karatsubaMultiplicationTesting::testSubBigInteger()
{
	KaratsubaMultiplication testSubtract;
	string first = "274";
	string second = "567";
	string expectFirstSecond = "-293";
	assert(testSubtract.subtractTwoBigIntegers(first, second).compare(expectFirstSecond) == 0);
	string greaterThan10 = "9999999999999999999999999";
	assert(testSubtract.subtractTwoBigIntegers(greaterThan10, greaterThan10).compare("0") == 0);

	string unequalBigNumbers =   "111111111111111111111111111111111111111111";
	string unequalSmallNumbers = "9999999999999999999999999999999999999999999999999";
	string resultsOfNegativeLarge = "-9999999888888888888888888888888888888888888888888";

	assert(testSubtract.subtractTwoBigIntegers(unequalBigNumbers, unequalSmallNumbers).compare(resultsOfNegativeLarge) == 0);

	string third = "87437139090070687609802597594884";
	string fourth = "50851806767876401952806582723184";
	string res34 = "36585332322194285656996014871700";
	string real = testSubtract.subtractTwoBigIntegers(third, fourth);
	// Edgecases, some how it delete the 0 in side the subtract strings :)
	assert(real.compare(res34)==0);

}

void karatsubaMultiplicationTesting::testAddBigInteger()
{
	KaratsubaMultiplication testAddBigInteger;
	string first = "1";
	string second = "1";
	string twoNumbers = "2";
	string lessThan10 = "999999999";
	string resLessThan10 = "1999999998";
	string greaterThan10 = "999999999999999999";
	string resultsGreaterThan10 = "1999999999999999998";
	string notEqualLength1 = "156491156484";
	string notEqualLength2 = "491156484";
	string resNotEqualLen = "156982312968";

	assert(testAddBigInteger.plusTwoBigIntegers(first,second).compare(twoNumbers) == 0);
	assert(testAddBigInteger.plusTwoBigIntegers(greaterThan10, greaterThan10).compare(resultsGreaterThan10) == 0);
	assert(testAddBigInteger.plusTwoBigIntegers(lessThan10, lessThan10).compare(resLessThan10) == 0);
	assert(testAddBigInteger.plusTwoBigIntegers(notEqualLength1, notEqualLength2).compare(resNotEqualLen) == 0);


	// This edcases is the cases where the numbers after adding is less than the original numbers :)
	string edgeCase1 = "8009953000";
	string edgeCase12 = "314184";
	string expectResults = "8010267184";
	assert(testAddBigInteger.plusTwoBigIntegers(edgeCase1, edgeCase12).compare(expectResults) == 0);

}

