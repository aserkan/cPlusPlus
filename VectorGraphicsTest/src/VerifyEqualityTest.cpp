#include "stdafx.h"

#include "TestHarness.h"
#include "Byte.h"
#include "Word.h"
#include "DoubleWord.h"
#include "VerifyEquality.h"
#include <sstream>
#include <string>
#include <iostream>

TEST(verifyEquality, Byte)
{
	const unsigned char input[] = { 0xAB};
	std::stringstream ss(reinterpret_cast<const char*>(input));

	Binary::Byte actual = Binary::Byte::read(ss);
	Binary::Byte expected(0xAB);

	try
	{
		verifyEquality(expected, actual, "expected");
		CHECK(true);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		CHECK(false);
	}
}


TEST(verifyEquality, Word)
{
	const unsigned char input[] = { 0xAB, 0xCD, 0 };
	std::stringstream ss(reinterpret_cast<const char*>(input));

	Binary::Word actual = Binary::Word::readLittleEndian(ss);
	

	Binary::Word expected(0xCDAB);
	try
	{
		verifyEquality(expected, actual, "expected");
		CHECK(true);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		CHECK(false);
	}


	Binary::Word notReallyExpected(0xABCD);
	try
	{
		verifyEquality(notReallyExpected, actual, "notReallyExpected");
		CHECK(false);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		CHECK(true);
	}
}

TEST(verifyEquality, DoubleWord)
{
	unsigned char headerData[] = { 0xAA, 0xBB, 0xCC, 0xDD, 0 };
	std::stringstream headerStream(reinterpret_cast<char*>(headerData));

	Binary::DoubleWord someHeaderValue = Binary::Word::readLittleEndian(headerStream);
	
	Binary::DoubleWord expected(0xBBAA);
	try
	{
		verifyEquality(expected, someHeaderValue, "expected");
		CHECK(true);
	}
	catch (const std::exception& exc)
	{
		std::cout << exc.what() << std::endl;
		CHECK(false);
	}

	Binary::DoubleWord notReallyExpected(0xAABB);
	try
	{
		verifyEquality(notReallyExpected, someHeaderValue, "notReallyExpected");
		CHECK(false);
	}
	catch (const std::exception& exc)
	{
		std::cout << exc.what() << std::endl;
		CHECK(true);
	}
}
