#include "CodecLibrary.h"

//#include "WindowsBitmapDecoder.h"

namespace BitmapGraphics
{
	void CodecLibrary::registerEncoder(HBitmapEncoder const& encoder)
	{
		mEncoderMap.insert(std::pair<std::string, HBitmapEncoder>(encoder->getMimeType(), encoder));
	}
	void CodecLibrary::registerDecoder(HBitmapDecoder const& decoder)
	{
		//won't insert if key is already in map
		mDecoderMap.insert(std::pair<std::string, HBitmapDecoder>(decoder->getMimeType(), decoder));
	}

	// provide a mime type version and an
	// auto determination version of createDecoder
	HBitmapDecoder CodecLibrary::createDecoder(std::istream& sourceStream)
	{
		char str[100];
		sourceStream.get(str, 100);
		std::string firstChunk(str);
		for each(auto pair in mDecoderMap)
		{
			if (pair.second->isSupported(firstChunk))
			{
				sourceStream.seekg(0);
				return createDecoder(pair.first, sourceStream);
			}
		}

	}
	HBitmapDecoder CodecLibrary::createDecoder(std::string const& mimeType,
		std::istream& sourceStream)
	{
		auto iter = mDecoderMap.find(mimeType);
		if (iter == mDecoderMap.end())
		{
			throw std::runtime_error("Decoder type has not been registered");
		}
		return iter->second->clone(sourceStream);
	}

	HBitmapEncoder CodecLibrary::createEncoder(std::string const& mimeType,
		HBitmapIterator& bitmapIterator)
	{
		auto iter = mEncoderMap.find(mimeType);
		if (iter == mEncoderMap.end())
		{
			throw std::runtime_error("Encoder type has not been registered");
		}
		return iter->second->clone(bitmapIterator);
	}
}