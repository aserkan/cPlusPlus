#include "Point.h"

namespace VectorGraphics
{
	int Point::getX() const
	{
		return mX;
	}
	int Point::getY() const
	{
		return mY;
	}

	bool Point::operator==(const Point& rhs) const
	{
		return (mX == rhs.mX && mY == rhs.mY);
	}
	bool Point::operator!=(const Point& rhs) const
	{
		return !operator==(rhs);
	}

	bool Point::operator<(const Point& rhs) const
	{
		if (mY<rhs.mY) return true;
		else if (mY>rhs.mY) return false;
		else return mX<rhs.mX;
	}
	bool Point::operator>(const Point& rhs) const
	{
		if (mY>rhs.mY) return true;
		else if (mY<rhs.mY) return false;
		else return mX>rhs.mX;
	}
	bool Point::operator<=(const Point& rhs) const
	{
		if (mY<rhs.mY) return true;
		else if (mY>rhs.mY) return false;
		else return mX<=rhs.mX;
	}
	bool Point::operator>=(const Point& rhs) const
	{
		if (mY>rhs.mY) return true;
		else if (mY<rhs.mY) return false;
		else return mX>=rhs.mX;
	}
	Point Point::operator+(const Point& rhs) const
	{
		return Point(mX + rhs.mX, mY + rhs.mY);
	}
	Point& Point::operator+=(const Point& rhs)
	{
		mX += rhs.mX;
		mY += rhs.mY;
		return *this;
	}
	Point Point::operator-(const Point& rhs) const
	{
		return Point(mX - rhs.mX, mY - rhs.mY);
	}
	Point& Point::operator-=(const Point& rhs)
	{
		mX -= rhs.mX;
		mY -= rhs.mY;
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const Point & point)
	{
		os << "Point " << "x=\"" << point.mX << "\" y=\"" << point.mY << "\"";
		return os;
	}
}