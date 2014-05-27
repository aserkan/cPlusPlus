#pragma once

#include "IBitmapIterator.h"
#include <iostream>
#include <memory>
#include <string>

namespace BitmapGraphics
{
	class IBitmapEncoder;
	typedef std::shared_ptr<IBitmapEncoder> HBitmapEncoder;

	class IBitmapEncoder
	{
	public:
		virtual ~IBitmapEncoder() { }

		virtual HBitmapEncoder clone(HBitmapIterator& bitmapIterator) = 0;

		//virtual HBitmapIterator createIterator() = 0;

		virtual std::string getMimeType() const = 0;
		
		virtual void encodeToStream(std::ostream & destinationStream) = 0;

		//virtual bool isSupported(const std::string& firstChunk) const = 0;
	};

}