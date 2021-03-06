#pragma once

#include <sstream>

namespace VectorGraphics
{
	class Point
	{
	public:
		Point(int x, int y)
			:mX(x), mY(y){};
		
		int getX() const;
		int getY() const;

		void setX(int x);
		void setY(int y);

		bool operator==(const Point& rhs) const;
		bool operator!=(const Point& rhs) const;
		bool operator<(const Point& rhs) const;
		bool operator>(const Point& rhs) const;
		bool operator<=(const Point& rhs) const;
		bool operator>=(const Point& rhs) const;
		Point operator+(const Point& rhs) const;
		Point& operator+=(const Point& rhs);
		Point operator-(const Point& rhs) const;
		Point& operator-=(const Point& rhs);

		friend std::ostream& operator<<(std::ostream& os, const Point & point);

	private:
		int mX;
		int mY;
	};
	
	std::ostream& operator<<(std::ostream& os, const Point & point);

}
