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

		bool operator==(const Point& rhs) const;
		bool operator!=(const Point& rhs) const;

		friend std::ostream& operator<<(std::ostream& os, const Point & point);

	private:
		int mX;
		int mY;
	};
	
	std::ostream& operator<<(std::ostream& os, const Point & point);

}
