#pragma once

#include "IBitmapIterator.h"
#include <iostream>
#include <memory>
#include <string>

namespace BitmapGraphics
{
	class IBitmapDecoder;
	typedef std::shared_ptr<IBitmapDecoder> HBitmapDecoder;

	class IBitmapDecoder
	{
	public:
		virtual ~IBitmapDecoder() { }

		virtual HBitmapDecoder clone(std::istream& sourceStream) = 0;

		virtual HBitmapIterator createIterator() = 0;

		virtual std::string getMimeType() const = 0;

		virtual bool isSupported(const std::string& firstChunk) const = 0;
	};

}