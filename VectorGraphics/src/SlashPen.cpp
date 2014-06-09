
#include "SlashPen.h"
//#include "Point.h"


// TODO: move this to a collection of common utility functions
namespace
{
	bool inRect(const VectorGraphics::Point& p,
		int left,
		int upper,
		int right,
		int lower)
	{
		if (p.getX() < left || p.getX() >= right)
		{
			return false;
		}

		if (p.getY() < upper || p.getY() >= lower)
		{
			return false;
		}

		return true;
	}
}


namespace BitmapGraphics
{

	SlashPen::SlashPen(int size, const Color& color) :
		mSize(size),
		mColor(color)
	{
	}

	void SlashPen::drawPoint(const HCanvas& canvas, const VectorGraphics::Point& point)
	{
		VectorGraphics::Point upperLeft(point.getX() - (mSize / 2), point.getY() - (mSize / 2));

		for (int i = 0; i < mSize; ++i)
		{
			VectorGraphics::Point p = upperLeft + VectorGraphics::Point(0, i);

			for (int j = 0; j < mSize; ++j)
			{
				p += VectorGraphics::Point(1, 0);

				if ((i + j) % 2)
				{
					if (inRect(p, 0, 0, canvas->getWidth(), canvas->getHeight()))
					{
						canvas->setPixelColor(p, mColor);
					}
				}
			}
		}
	}

}