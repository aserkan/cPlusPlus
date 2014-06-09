#include "WindowsBitmapFileProjector.h"


namespace BitmapGraphics
{
	WindowsBitmapFileProjector::WindowsBitmapFileProjector(const std::string& fileName, BitmapGraphics::CodecLibrary& codecLibrary)
		: mFileName(fileName), mCodecLibrary(codecLibrary)
	{

	}

	void WindowsBitmapFileProjector::projectCanvas(HCanvas const& canvas)
	{
		HBitmapIterator bitmapIterator = canvas->createBitmapIterator();
		HBitmapEncoder bitmapEncoder = mCodecLibrary.createEncoder(BitmapGraphics::WindowsBitmapMimeType, bitmapIterator);
		std::ofstream outputStream(mFileName, std::ios::binary);
		if (outputStream.is_open())	bitmapEncoder->encodeToStream(outputStream);
		outputStream.close();
	}

}