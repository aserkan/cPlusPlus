#pragma once

#include <list>
#include "Color.h"
#include "IBitmapIterator.h"

namespace BitmapGraphics
{
	class Bitmap
	{
	public:
		typedef std::list<BitmapGraphics::Color> ScanLine;
		typedef ScanLine::iterator ColorIterator;

	private:
		typedef std::list<ScanLine> ScanLineCollection;

	public:
		typedef ScanLineCollection::iterator ScanLineIterator;
		typedef ScanLineCollection::const_iterator const_ScanLineIterator;
		Bitmap(std::istream& sourceStream);
		Bitmap(int width, int height);
		Bitmap(int width, int height, std::istream& sourceStream);

		ScanLineIterator begin() { return mScanLineCollection.begin(); };
		ScanLineIterator end() { return mScanLineCollection.end(); };

		const_ScanLineIterator begin() const { return mScanLineCollection.begin(); };
		const_ScanLineIterator end() const { return mScanLineCollection.end(); };

		int getWidth() const { return mWidth; };
		int getHeight() const { return mHeight; };
		int getNumberOfPadBytes()const;

		//static Bitmap read(int width, int height, std::istream& sourceStream);
		void write(std::ostream & destinationStream) const;

		void addScanline(const ScanLine& scanLine);

		HBitmapIterator createIterator();
		// ...

	private:
		int mWidth;
		int mHeight;
		ScanLineCollection mScanLineCollection;

		void readRawData(std::istream& sourceStream);

	};
	
	typedef std::shared_ptr<Bitmap> HBitmap;

}
