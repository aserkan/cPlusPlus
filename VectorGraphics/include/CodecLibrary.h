#pragma once

#include "IBitmapDecoder.h"
#include "IBitmapEncoder.h"

#include <unordered_map>

namespace BitmapGraphics
{
	class CodecLibrary {
	public:
		void registerEncoder(HBitmapEncoder const& encoder);
		void registerDecoder(HBitmapDecoder const& decoder);

		// provide a mime type version and an
		// auto determination version of createDecoder
		HBitmapDecoder createDecoder(std::istream& sourceStream);
		HBitmapDecoder createDecoder(std::string const& mimeType,
			std::istream& sourceStream);

		HBitmapEncoder createEncoder(std::string const& mimeType,
			HBitmapIterator& bitmapIterator);
	private:
		std::unordered_map<std::string, HBitmapEncoder> mEncoderMap;
		std::unordered_map<std::string, HBitmapDecoder> mDecoderMap;
	};
}
