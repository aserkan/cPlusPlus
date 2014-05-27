#pragma once
#include <sstream>

template <typename T>
void verifyEquality(const T& expected, const T& actual, const std::string& name)
{
	if (expected != actual)
	{
		std::stringstream errorMessage;
		errorMessage << "ERROR with " << name << ": expected = " << expected << ", actual = " << actual << std::endl;
		throw std::runtime_error(errorMessage.str());
	}
}