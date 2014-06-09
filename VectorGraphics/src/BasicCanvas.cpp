#include "BasicCanvas.h"
#include "BasicCanvasBitmapIterator .h"

namespace BitmapGraphics
{
	typedef std::pair<VectorGraphics::Point, Color> pointColorPair;

	BasicCanvas::BasicCanvas(int width, int height, Color color)
		: mWidth(width), mHeight(height), mBackgroundColor(color)
	{
		for (int row = 0; row < height; row++)
		{
			for (int column = 0; column < width; column++)
			{
				mPixels.insert(pointColorPair(VectorGraphics::Point(column, row), mBackgroundColor));
			}
		}

	}
	void BasicCanvas::setPixelColor(const VectorGraphics::Point& location, const Color& color)
	{
		auto point = mPixels.find(location);
		if (point != mPixels.end()) point->second = color;
		else throw std::runtime_error("point location not in canvas");
	}

	Color BasicCanvas::getPixelColor(const VectorGraphics::Point& location) const
	{
		auto point = mPixels.find(location);
		if (point != mPixels.end()) return point->second;
		else return mBackgroundColor;
	}

	int BasicCanvas::getWidth() const
	{
		return mWidth;
	}

	int BasicCanvas::getHeight() const
	{
		return mHeight;
	}

	BasicCanvas::PointColorMapIterator BasicCanvas::begin()
	{
		return mPixels.begin();
	}
	BasicCanvas::PointColorMapIterator BasicCanvas::end()
	{
		return mPixels.end();
	}

	BasicCanvas::const_PointColorMapIterator BasicCanvas::begin() const
	{
		return mPixels.begin();
	}
	BasicCanvas::const_PointColorMapIterator BasicCanvas::end() const
	{
		return mPixels.end();
	}

	HBitmapIterator BasicCanvas::createBitmapIterator()
	{
		return HBitmapIterator(new BasicCanvasBitmapIterator(*this));
	}
}