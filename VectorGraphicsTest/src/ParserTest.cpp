#include "stdafx.h"

#include "Parser.h"
#include "TestHarness.h"

TEST(trimBeginning, Parse)
{
	std::string actual("  \tHello");
	Parser::trim(actual, " \t\n");
	std::string expected("Hello");
	CHECK_EQUAL(expected, actual);
}

TEST(trimEnd, Parse)
{
	std::string actual("Hello  \n\n\n\t");
	Parser::trim(actual, " \t\n");
	std::string expected("Hello");
	CHECK_EQUAL(expected, actual);
}

TEST(trimBeginningAndEnd, Parse)
{
	std::string actual("  Hello\n\t");
	Parser::trim(actual, " \t\n");
	std::string expected("Hello");
	CHECK_EQUAL(expected, actual);
}

TEST(trimBeginningAndEndOne, Parse)
{
	std::string actual("  H\n\t");
	Parser::trim(actual, " \t\n");
	std::string expected("H");
	CHECK_EQUAL(expected, actual);
}

TEST(trimNone, Parse)
{
	std::string actual("Hello");
	Parser::trim(actual);
	std::string expected("Hello");
	CHECK_EQUAL(expected, actual);
}

TEST(trimEmpty, Parse)
{
	std::string actual;
	Parser::trim(actual);
	std::string expected;
	CHECK_EQUAL(expected, actual);
}

TEST(trimEverything, Parse)
{
	std::string actual("Hello 1234");
	std::string trimmables("Hello 0123456789");
	Parser::trim(actual, trimmables);
	std::string expected;
	CHECK_EQUAL(expected, actual);
}

TEST(eatNothing, Parse)
{
	std::stringstream stream("Hello");
	Parser::eat(stream, "123456789");
	std::string expected("Hello");
	std::string actual;
	stream >> actual;
	CHECK_EQUAL(expected, actual);
}

TEST(eatSomething, Parse)
{
	std::stringstream stream("4320Hello");
	Parser::eat(stream, "1234567890");
	std::string expected("Hello");
	std::string actual;
	stream >> actual;
	CHECK_EQUAL(expected, actual);
}
