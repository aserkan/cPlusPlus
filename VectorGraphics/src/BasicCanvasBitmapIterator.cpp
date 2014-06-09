#include "BasicCanvasBitmapIterator .h"

namespace BitmapGraphics
{

	BasicCanvasBitmapIterator::BasicCanvasBitmapIterator(BasicCanvas& basicCanvas)
		:mBasicCanvas(basicCanvas), mCurrentX(0), mCurrentY(0), mMapIterator(basicCanvas.begin())
	{

	}

	void BasicCanvasBitmapIterator::nextScanLine()
	{
		if (isEndOfImage()) return;
		if (isEndOfScanLine())
		{
			mCurrentX = 0;
			mCurrentY++;
			mMapIterator++;
		}
		else
		{
			int advance = mBasicCanvas.getWidth() - mCurrentX;
			mCurrentX = 0;
			mCurrentY++;
			if (mCurrentY != mBasicCanvas.getHeight()) std::advance(mMapIterator, advance);
			else mMapIterator = mBasicCanvas.end();
		}


	}
	bool BasicCanvasBitmapIterator::isEndOfImage() const
	{
		return mMapIterator == mBasicCanvas.end();
	}
	void BasicCanvasBitmapIterator::nextPixel()
	{
		if (isEndOfImage()) return;
		mCurrentX++;
		if (!isEndOfScanLine())	mMapIterator++;
		else if (mCurrentY == mBasicCanvas.getHeight() - 1) mMapIterator = mBasicCanvas.end();
		//if (mCurrentX == mBasicCanvas.getWidth())
		//{
		//	mCurrentY++;
		//	if (mCurrentY != mBasicCanvas.getHeight()) mCurrentX = 0;
		//	else mMapIterator = mBasicCanvas.end();
		//}
	}
	bool BasicCanvasBitmapIterator::isEndOfScanLine() const
	{
		//return (mCurrentX == (mBasicCanvas.getWidth() - 1));
		return (mCurrentX == (mBasicCanvas.getWidth()));
	}
	
	Color BasicCanvasBitmapIterator::getColor() const
	{
		return mMapIterator->second;
	}
	int BasicCanvasBitmapIterator::getBitmapWidth() const
	{
		return mBasicCanvas.getWidth();
	}
	int BasicCanvasBitmapIterator::getBitmapHeight() const
	{
		return mBasicCanvas.getHeight();
	}
}