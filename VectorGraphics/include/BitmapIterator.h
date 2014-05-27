#pragma once

#include "IBitmapIterator.h"
#include "Bitmap.h"

namespace BitmapGraphics
{
	class BitmapIterator : public IBitmapIterator
	{
	public:
		BitmapIterator(Bitmap& bitmap);

		virtual void nextScanLine();
		virtual bool isEndOfImage() const;
		virtual void nextPixel();
		virtual bool isEndOfScanLine() const;
		virtual Color getColor() const;

		virtual int getBitmapWidth() const;
		virtual int getBitmapHeight() const;

	private:
		Bitmap& myBitmap;
		Bitmap::ScanLineIterator myScanLine;
		Bitmap::ColorIterator myColor;
	};

}