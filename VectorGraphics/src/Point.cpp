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

	std::ostream& operator<<(std::ostream& os, const Point & point)
	{
		os << "Point " << "x=\"" << point.mX << "\" y=\"" << point.mY << "\"";
		return os;
	}
}