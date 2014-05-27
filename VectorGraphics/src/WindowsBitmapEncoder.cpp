
#include "WindowsBitmapEncoder.h"
#include "WindowsBitmapCommon.h"
#include "WindowsBitmapHeader.h"
#include <sstream>

namespace
{
	std::istringstream nullStream;
}


namespace BitmapGraphics
{
	WindowsBitmapEncoder::WindowsBitmapEncoder()
	{

	}
	WindowsBitmapEncoder::WindowsBitmapEncoder(HBitmapIterator& bitmapIterator)
		: mBitmapIterator(bitmapIterator)
	{

	}
	HBitmapEncoder WindowsBitmapEncoder::clone(HBitmapIterator& bitmapIterator)
	{
		return HBitmapEncoder(new WindowsBitmapEncoder(bitmapIterator));
	}

	std::string WindowsBitmapEncoder::getMimeType() const
	{
		return WindowsBitmapMimeType;
	}

	void WindowsBitmapEncoder::encodeToStream(std::ostream & destinationStream)
	{
		if (mBitmapIterator == NULL)
		{
			throw std::runtime_error("Invalid use of prototype encoder");
		}

		//stream header info to destinationStream
		int width = mBitmapIterator->getBitmapWidth();
		int height = mBitmapIterator->getBitmapHeight();
		WindowsBitmapHeader header(getFileSize(width, height), width, height);
		header.write(destinationStream);

		while (!mBitmapIterator->isEndOfImage())
		{
			while (!mBitmapIterator->isEndOfScanLine())
			{
				Color color = mBitmapIterator->getColor();
				color.write(destinationStream);
				mBitmapIterator->nextPixel();
			}
			//add padding if necessary
			for (int pad = 0; pad < getNumberOfPadBytes(width); ++pad)
			{
				destinationStream.put(0x00);
			}

			mBitmapIterator->nextScanLine();
		}
	}
}