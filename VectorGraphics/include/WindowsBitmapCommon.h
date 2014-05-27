#pragma once

#include <string>

namespace BitmapGraphics
{
	const std::string WindowsBitmapMimeType = "image/x-ms-bmp";
	
	const int WindowsBitmapHeaderSize = 54;

	inline int getNumberOfPadBytes(int width)
	{
		int remainder = (width * 3) % 4;
		return (remainder == 0) ? 0 : (4 - remainder);
	}

	inline int getFileSize(int width, int height)
	{
		int paddedWidth = width + getNumberOfPadBytes(width);
		int bitmapSize = paddedWidth * height;
		return bitmapSize + WindowsBitmapHeaderSize;
	}

}