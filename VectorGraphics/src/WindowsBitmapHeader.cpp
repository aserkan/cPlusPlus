#include "WindowsBitmapHeader.h"
#include "VerifyEquality.h"

namespace BitmapGraphics
{
	Binary::Byte WindowsBitmapHeader::firstIdentifier = 0x42; //"B"
	Binary::Byte WindowsBitmapHeader::secondIdentifier = 0x4D; //"M"
	Binary::DoubleWord WindowsBitmapHeader::reserved = 0x00000000;
	Binary::DoubleWord WindowsBitmapHeader::rawImageByteOffset = 0x0000036; //"54"
	Binary::DoubleWord WindowsBitmapHeader::infoHeaderBytes = 0x00000028; //"40"
	Binary::Word WindowsBitmapHeader::numberOfPlanes = 0x0001; // "1"
	Binary::Word WindowsBitmapHeader::bitsPerPixel = 0x0018; // "24"
	Binary::DoubleWord WindowsBitmapHeader::compressionType = 0x00000000;
	Binary::DoubleWord WindowsBitmapHeader::compressedImageSize = 0x00000000;
	Binary::DoubleWord WindowsBitmapHeader::horizontalPixelsPerMeter = 0x00000000;
	Binary::DoubleWord WindowsBitmapHeader::verticalPixelsPerMeter = 0x00000000;
	Binary::DoubleWord WindowsBitmapHeader::numberOfColors = 0x00000000;
	Binary::DoubleWord WindowsBitmapHeader::numberOfImportantColors = 0x00000000;


	WindowsBitmapHeader::WindowsBitmapHeader()
		: fileSize(0), bitmapWidth(0), bitmapHeight(0)
	{
	}
	WindowsBitmapHeader::WindowsBitmapHeader(int size, int width, int height)
		: fileSize(size), bitmapWidth(width), bitmapHeight(height)
	{

	}
	WindowsBitmapHeader::WindowsBitmapHeader(std::istream& sourceStream)
		: fileSize(0), bitmapWidth(0), bitmapHeight(0)
	{
		readFileHeader(sourceStream);
		readInfoHeader(sourceStream);
	}
	
	void WindowsBitmapHeader::readFileHeader(std::istream& sourceStream)
	{
		verifyEquality(firstIdentifier, Binary::Byte::read(sourceStream), "firstIdentifier");
		verifyEquality(secondIdentifier, Binary::Byte::read(sourceStream), "secondIdentifier");
		fileSize = Binary::DoubleWord::readLittleEndian(sourceStream);
		verifyEquality(reserved, Binary::DoubleWord::readLittleEndian(sourceStream), "reserved");
		rawImageByteOffset = Binary::DoubleWord::readLittleEndian(sourceStream);
		//verifyEquality(rawImageByteOffset, Binary::DoubleWord::readLittleEndian(sourceStream), "rawImageByteOffset");
	}

	void WindowsBitmapHeader::writeFileHeader(std::ostream& destinationStream) const
	{
		firstIdentifier.write(destinationStream);
		secondIdentifier.write(destinationStream);
		fileSize.writeLittleEndian(destinationStream);
		reserved.writeLittleEndian(destinationStream);
		rawImageByteOffset.writeLittleEndian(destinationStream);
	}

	void WindowsBitmapHeader::readInfoHeader(std::istream& sourceStream)
	{
		verifyEquality(infoHeaderBytes, Binary::DoubleWord::readLittleEndian(sourceStream), "infoHeaderBytes");
		bitmapWidth = Binary::DoubleWord::readLittleEndian(sourceStream);
		bitmapHeight = Binary::DoubleWord::readLittleEndian(sourceStream);
		verifyEquality(numberOfPlanes, Binary::Word::readLittleEndian(sourceStream), "numberOfPlanes");
		//verifyEquality(bitsPerPixel, Binary::Word::readLittleEndian(sourceStream), "bitsPerPixel");
		bitsPerPixel = Binary::Word::readLittleEndian(sourceStream);
		//verifyEquality(compressionType, Binary::DoubleWord::readLittleEndian(sourceStream), "compressionType");
		compressionType = Binary::DoubleWord::readLittleEndian(sourceStream);
		//verifyEquality(compressedImageSize, Binary::DoubleWord::readLittleEndian(sourceStream), "compressedImageSize");
		compressedImageSize = Binary::DoubleWord::readLittleEndian(sourceStream);
		horizontalPixelsPerMeter = Binary::DoubleWord::readLittleEndian(sourceStream);
		verticalPixelsPerMeter = Binary::DoubleWord::readLittleEndian(sourceStream);
		//verifyEquality(horizontalPixelsPerMeter, Binary::DoubleWord::readLittleEndian(sourceStream), "horizontalPixelsPerMeter");
		//verifyEquality(verticalPixelsPerMeter, Binary::DoubleWord::readLittleEndian(sourceStream), "verticalPixelsPerMeter");
		numberOfColors = Binary::DoubleWord::readLittleEndian(sourceStream);
		//verifyEquality(numberOfColors, Binary::DoubleWord::readLittleEndian(sourceStream), "numberOfColors");
		numberOfImportantColors = Binary::DoubleWord::readLittleEndian(sourceStream);
		//verifyEquality(numberOfImportantColors, Binary::DoubleWord::readLittleEndian(sourceStream), "numberOfImportantColors");
	}

	void WindowsBitmapHeader::writeFileInfo(std::ostream& destinationStream) const
	{
		infoHeaderBytes.writeLittleEndian(destinationStream);
		bitmapWidth.writeLittleEndian(destinationStream);
		bitmapHeight.writeLittleEndian(destinationStream);
		numberOfPlanes.writeLittleEndian(destinationStream);
		bitsPerPixel.writeLittleEndian(destinationStream);
		compressionType.writeLittleEndian(destinationStream);
		compressedImageSize.writeLittleEndian(destinationStream);
		horizontalPixelsPerMeter.writeLittleEndian(destinationStream);
		verticalPixelsPerMeter.writeLittleEndian(destinationStream);
		numberOfColors.writeLittleEndian(destinationStream);
		numberOfImportantColors.writeLittleEndian(destinationStream);
	}

	void WindowsBitmapHeader::write(std::ostream & destinationStream) const
	{
		writeFileHeader(destinationStream);
		writeFileInfo(destinationStream);
	}


	Binary::DoubleWord WindowsBitmapHeader::getBitmapHeight() const
	{
		return bitmapHeight;
	}
	Binary::DoubleWord WindowsBitmapHeader::getBitmapWidth() const
	{
		return bitmapWidth;
	}
	Binary::DoubleWord WindowsBitmapHeader::getFileSize() const
	{
		return fileSize;
	}

	
}
