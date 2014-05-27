#include "Bitmap.h"
#include "BitmapIterator.h"

using namespace BitmapGraphics;

Bitmap::Bitmap(std::istream& sourceStream)
	: mWidth(0), mHeight(0)
{
	
}
Bitmap::Bitmap(int width, int height) 
	: mWidth(width), mHeight(height)
{

}
Bitmap::Bitmap(int width, int height, std::istream& sourceStream)
	: mWidth(width), mHeight(height)
{
	readRawData(sourceStream);
}

void Bitmap::readRawData(std::istream& sourceStream)
{
	int numberOfScanLines = 0;
	while (numberOfScanLines < mHeight)
	{
		ScanLine curScanLine;
		int lineByteCount = 0;
		while (lineByteCount < mWidth)
		{
			curScanLine.push_back(Color::read(sourceStream));
			lineByteCount++; //do checking instead of this for the padding cases
		}
		//check for padding
		for (int i = 0; i < getNumberOfPadBytes(); i++) sourceStream.get();
		mScanLineCollection.push_back(curScanLine);
		numberOfScanLines++;
	}
}

void Bitmap::write(std::ostream & destinationStream) const
{
	for each(auto scanLine in mScanLineCollection)
	{
		for each(auto color in scanLine)
		{
			color.write(destinationStream);
		}
		//add padding if necessary
		for (int i = 0; i < getNumberOfPadBytes(); i++) destinationStream.put(0x00);
	}
}

void Bitmap::addScanline(const ScanLine& scanLine)
{
	mScanLineCollection.push_back(scanLine);
}

HBitmapIterator Bitmap::createIterator()
{
	return HBitmapIterator(new BitmapIterator(*this));
}

int Bitmap::getNumberOfPadBytes()const
{
	int scanLineDiv = (mWidth * 3) % 4;
	return  (scanLineDiv == 0) ? 0 : (4 - scanLineDiv);
}