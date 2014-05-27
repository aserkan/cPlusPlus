#pragma once

#include <iostream>
#include "Byte.h"
#include "Word.h"
#include "DoubleWord.h"

namespace BitmapGraphics
{
	class WindowsBitmapHeader
	{
	public:
		// appropriate accessors, constructors, etc. . .
		// . . .
		WindowsBitmapHeader();
		WindowsBitmapHeader(int fileSize, int width, int height);
		WindowsBitmapHeader(std::istream& sourceStream);
		void readFileHeader(std::istream& sourceStream);
		void readInfoHeader(std::istream& sourceStream);
		void writeFileHeader(std::ostream& destinationStream) const;
		void writeFileInfo(std::ostream& destinationStream) const;
		void write(std::ostream & destinationStream) const;
		
		Binary::DoubleWord getBitmapHeight() const;
		Binary::DoubleWord getBitmapWidth() const;
		Binary::DoubleWord getFileSize() const;


	private:
		// file header
		static Binary::Byte firstIdentifier;
		static Binary::Byte secondIdentifier;
		Binary::DoubleWord fileSize;
		static Binary::DoubleWord reserved;
		static Binary::DoubleWord rawImageByteOffset;

		// info header
		static Binary::DoubleWord infoHeaderBytes;
		Binary::DoubleWord bitmapWidth;
		Binary::DoubleWord bitmapHeight;
		static Binary::Word numberOfPlanes;
		static Binary::Word bitsPerPixel;
		static Binary::DoubleWord compressionType;
		static Binary::DoubleWord compressedImageSize;
		static Binary::DoubleWord horizontalPixelsPerMeter;
		static Binary::DoubleWord verticalPixelsPerMeter;
		static Binary::DoubleWord numberOfColors;
		static Binary::DoubleWord numberOfImportantColors;
	};
}
