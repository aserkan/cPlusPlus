#pragma once

#include <iostream>

//forward declarations 
template <class Number, Number lowerLimit, Number upperLimit>
class ranged_number;

template <class Number, Number lowerLimit, Number upperLimit>
std::ostream& operator<<(std::ostream& os, const ranged_number<Number, lowerLimit, upperLimit> & rngdNumber);


//ranged_number class definition
template <class Number, Number lowerLimit, Number upperLimit>
class ranged_number
{
public:
	ranged_number()
	{

	}
	ranged_number(Number value)
		: mNumber(value)
	{
		checkLimits();
	}
	ranged_number& operator=(const ranged_number& rhs)
	{
		mNumber = rhs.mNumber;
		checkLimits();
		return *this;

	}
	template<class T>
	ranged_number& operator=(const T& rhs)
	{
		mNumber = rhs;
		checkLimits();
		return *this;
	}
	ranged_number operator+(const ranged_number& rhs)
	{
		ranged_number<Number, lowerLimit, upperLimit> tmp(mNumber+rhs.mNumber);
		return tmp;
	}
	ranged_number<Number, lowerLimit, upperLimit>& operator+=(const ranged_number& rhs)
	{
		mNumber += rhs.mNumber;
		checkLimits();
		return *this;
	}
	ranged_number<Number, lowerLimit, upperLimit> operator-(const ranged_number& rhs) 
	{
		ranged_number<Number, lowerLimit, upperLimit> tmp(mNumber - rhs.mNumber);
		return tmp;
	}
	ranged_number<Number, lowerLimit, upperLimit>& operator-=(const ranged_number& rhs)
	{
		mNumber -= rhs.mNumber;
		checkLimits();
		return *this;
	}
	//prefix
	ranged_number<Number, lowerLimit, upperLimit>& operator++()
	{
		mNumber++;
		checkLimits();
		return *this;
	}
	//postfix
	ranged_number<Number, lowerLimit, upperLimit>& operator++(int)
	{
		ranged_number<Number, lowerLimit, upperLimit> tmp(mNumber);
		operator++();
		return tmp;
	}
	//prefix
	ranged_number<Number, lowerLimit, upperLimit>& operator--()
	{
		mNumber--;
		checkLimits();
		return *this;
	}
	//postfix
	ranged_number<Number, lowerLimit, upperLimit>& operator--(int)
	{
		ranged_number<Number, lowerLimit, upperLimit> tmp(mNumber);
		operator--();
		return tmp;
	}
	bool operator==(const ranged_number& rhs) const 
	{
		return mNumber == rhs.mNumber;
	}
	bool operator!=(const ranged_number& rhs) const
	{
		return !operator==(rhs);
	}
	friend std::ostream& operator<< <>(std::ostream& os, const ranged_number & rngdNumber);
	// operators and methods to make the class behave
	// just like an actual number, with the addition of
	// restricting the range.

private:
	Number mNumber;
	void checkLimits()
	{
		if (upperLimit<lowerLimit) throw std::runtime_error("upperLimit is smaller than lowerLimit");
		if (mNumber > upperLimit) mNumber = upperLimit;
		else if (mNumber < lowerLimit) mNumber = lowerLimit;
	}
};

template <class Number, Number lowerLimit, Number upperLimit>
std::ostream& operator<<(std::ostream& os, const ranged_number<Number, lowerLimit, upperLimit> & rngdNumber)
{
	os << "Value is: " << rngdNumber.mNumber << " ,lower limit is: " << lowerLimit << " ,upper limit is: " << upperLimit;
	return os;
}


template <class Number, Number lowerLimit, Number upperLimit>
bool operator==(Number num, const ranged_number<Number, lowerLimit, upperLimit> & rangedNumber)
{
	return rangedNumber.operator==(num);
}