
#include "WindowsBitmapDecoder.h"
#include "WindowsBitmapCommon.h"
#include "WindowsBitmapHeader.h"
#include <sstream>

namespace
{
	std::istringstream nullStream;
}


namespace BitmapGraphics
{

	WindowsBitmapDecoder::WindowsBitmapDecoder() :
		mySourceStream(nullStream)
	{
		mySourceStream.setstate(std::ios::badbit);
	}

	WindowsBitmapDecoder::WindowsBitmapDecoder(std::istream& sourceStream) :
		mySourceStream(sourceStream)
	{

	}

	HBitmapDecoder WindowsBitmapDecoder::clone(std::istream& sourceStream)
	{
		return HBitmapDecoder(new WindowsBitmapDecoder(sourceStream));
	}

	HBitmapIterator WindowsBitmapDecoder::createIterator()
	{
		if (mySourceStream.bad())
		{
			throw std::runtime_error("Invalid use of prototype decoder");
		}

		WindowsBitmapHeader header(mySourceStream);

		myBitmap = HBitmap(new Bitmap(header.getBitmapWidth(), header.getBitmapHeight()));
		//myBitmap = std::make_shared<Bitmap>(header.getBitmapWidth(), header.getBitmapHeight());

		for (int row = 0; row < myBitmap->getHeight(); ++row)
		{
			Bitmap::ScanLine scanLine;

			// Read row of pixels
			for (int column = 0; column < myBitmap->getWidth(); ++column)
			{
				scanLine.push_back(Color::read(mySourceStream));
			}

			// Read and ignore pad bytes (if any)
			for (int pad = 0; pad < getNumberOfPadBytes(myBitmap->getWidth()); ++pad)
			{
				Binary::Byte::read(mySourceStream);
			}

			myBitmap->addScanline(scanLine);
		}

		return myBitmap->createIterator();
	}

	std::string WindowsBitmapDecoder::getMimeType() const
	{
		return WindowsBitmapMimeType;
	}

	bool WindowsBitmapDecoder::isSupported(const std::string& firstChunk) const
	{
		if (firstChunk.size() < 2)
		{
			return false;
		}

		return (firstChunk[0] == 'B') && (firstChunk[1] == 'M');
	}

}