#include "BitmapIterator.h"
#include "Color.h"
#include <stdexcept>

namespace BitmapGraphics
{
	BitmapIterator::BitmapIterator(Bitmap& bitmap) :
		myBitmap(bitmap),
		myScanLine(bitmap.begin())
	{
		if (myScanLine == bitmap.end())
		{
		}
		else
		{
			myColor = myScanLine->begin();
		}
	}

	void BitmapIterator::nextScanLine()
	{
		++myScanLine;
		if (!isEndOfImage())
		{
			myColor = myScanLine->begin();
		}
	}

	bool BitmapIterator::isEndOfImage() const
	{
		return myScanLine == myBitmap.end();
	}

	void BitmapIterator::nextPixel()
	{
		++myColor;
	}

	bool BitmapIterator::isEndOfScanLine() const
	{
		return myColor == myScanLine->end();
	}

	Color BitmapIterator::getColor() const
	{
		return *myColor;
	}

	int BitmapIterator::getBitmapWidth() const
	{
		return myBitmap.getWidth();
	}

	int BitmapIterator::getBitmapHeight() const
	{
		return myBitmap.getHeight();
	}
}
