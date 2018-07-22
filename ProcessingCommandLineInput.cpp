#include <string>
#include "TestRangeSearch.h"
#include "TestRootCalculation.h"
#include "ProcessingCommandLineInput.h"
//#include "InversionsCalculation.h"
//#include "ProcessingIntegerInputFromTextFile.h"
//#include "InversionCalculationUsedArray.h"
#include "karatsubaMultiplicationTesting.h"

using namespace std;

ProcessingCommandLineInput::ProcessingCommandLineInput()
{
	runninngTest();	
}


ProcessingCommandLineInput::~ProcessingCommandLineInput()
{
}

void ProcessingCommandLineInput::runninngTest()
{
	// if the the command line is test, just do testing
	// if the command line is some thing else, do it
	string command;
	while (1)
	{
		cout << "Please input command or type help for available command:";
		cin >> command;
		cout << "\n";
		if (command.compare("TestRangeSearch") == 0)
		{
			TestRangeSearch tf;
			tf.testRangeSearch();
		}

		if (command.compare("TestRootCalculation") == 0)
		{
			TestRootCalculation tRoot;
			tRoot.testRoot();

		}
		if (command.compare("calculateInversionStanford") == 0)
		{
			// InversionsCalculation inv;
			// ProcessingIntegerInputFromTextFile vectorArray;
			// vector<int>  array1{ 2, 3, 9, 2, 9 };
			// vector<int> array2{ 1, 3, 5, 2, 4, 6 };
			// vector<int> array3{ 1, 2, 3, 4, 5, 6 };

			// string fileName = "E:\\PersonalProjectGitHub\\AlgorithmsCodingJava\\_bcb5c6658381416d19b01bfc1d3993b5_IntegerArray.txt";
			// vector<int> nums = vectorArray.readIntegerFileToArray(fileName);
			
			// //long value = inv.countInversion(nums);	
			// cout << "inversion " << inv.countInversion(array1);
			// cout << "\n";
			// cout << "inversion " << inv.countInversion(array2);
			// cout << "\n";
			// cout << "inversion " << inv.countInversion(array3);
			// cout << "\n";
			// cout << "inversion " << inv.countInversion(nums);
			// cout << "\n";
			// cout << "done\n";	
		}
		if (command.compare("aInv") == 0) {
			cout << " \n not implement \n";
			//InversionCalculationUsedArray invA;
			//cout << "\n" << invA.countInversions << "\n";

		}

		if (command.compare("bigAddSub") == 0) 
		{
			karatsubaMultiplicationTesting test;
			cout << "\n" << endl;
			test.testAddBigInteger();
			test.testSubBigInteger();
			
		}

		if (command.compare("karatsuba") == 0) 
		{
			karatsubaMultiplicationTesting test;
			cout << "\n" << endl;
			test.testKaratSubaEvenNumbers();
			test.testKaratSubaOddNumbers();
			test.testKarasuba();
			cout << "passed" << "\n";
		}

		if (command.compare("help") == 0)
		{
			cout << "The list of command available: \n\n";
			cout << "TestRangeSearch --> To TEST the range search binary Search\n";
			cout << "TestRootCalculation --> To TEST the positive root > 0.0 \n ";
			cout << "calculateInversionStanford \n";
			cout << "bigAddSub --> To TEST the subtract and add big Integers";
			cout << "karatsuba --> to TEST the coursera karatsuba multiplication";
			cout << "exit --> To exit (closed) the program.\n";
		}


		if (command.compare("exit") == 0) break;
		cout << "\n";
	}
	cin.get();
}
