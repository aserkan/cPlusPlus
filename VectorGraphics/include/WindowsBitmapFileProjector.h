#pragma once

#include <fstream>
#include "IProjector.h"
#include "CodecLibrary.h"
#include "WindowsBitmapCommon.h"

namespace BitmapGraphics
{
	class WindowsBitmapFileProjector : public IProjector
	{
	public:
		WindowsBitmapFileProjector(const std::string& filename, BitmapGraphics::CodecLibrary& codecLibrary);
		virtual void projectCanvas(HCanvas const& canvas);

	private:
		std::string mFileName;
		BitmapGraphics::CodecLibrary& mCodecLibrary;
	};
}