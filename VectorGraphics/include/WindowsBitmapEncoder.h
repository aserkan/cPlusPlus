#pragma once

#include "IBitmapEncoder.h"
#include "Bitmap.h"

namespace BitmapGraphics
{
	class WindowsBitmapEncoder : public IBitmapEncoder
	{
	public:
		WindowsBitmapEncoder();
		//WindowsBitmapEncoder(std::ostream & destinationStream);
		WindowsBitmapEncoder(HBitmapIterator& bitmapIterator);

		virtual void encodeToStream(std::ostream & destinationStream);

		virtual HBitmapEncoder clone(HBitmapIterator& bitmapIterator);

		//virtual HBitmapIterator createIterator();

		virtual std::string getMimeType() const;

		//virtual bool isSupported(const std::string& firstChunk) const;

	private:
		//std::istream& mySourceStream;
		//HBitmap myBitmap;
		HBitmapIterator mBitmapIterator;
	};

}