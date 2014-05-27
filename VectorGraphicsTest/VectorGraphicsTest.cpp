// VectorGraphicsTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "TestHarness.h"
#include <ctime>
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	//random number generator used in some tests
	//srand(::time_t()); // this keeps generating same number
	srand(std::time(NULL));

	TestResult tr;
	TestRegistry::runAllTests(tr);

	//force console screen to hold
	char ch;
	std::cin >> ch;

	return 0;
}

