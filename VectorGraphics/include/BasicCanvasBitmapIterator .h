#pragma once

//#include "IBitmapIterator.h"
#include "BasicCanvas.h"

namespace BitmapGraphics
{
	class BasicCanvasBitmapIterator : public IBitmapIterator
	{
	public:
		BasicCanvasBitmapIterator(BasicCanvas& basicCanvas);

		virtual void nextScanLine();
		virtual bool isEndOfImage() const;
		virtual void nextPixel();
		virtual bool isEndOfScanLine() const;
		virtual Color getColor() const;

		virtual int getBitmapWidth() const;
		virtual int getBitmapHeight() const;

	private:
		BasicCanvas& mBasicCanvas;
		BasicCanvas::PointColorMapIterator mMapIterator;
		int mCurrentX;
		int mCurrentY;
	};
}