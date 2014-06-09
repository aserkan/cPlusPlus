#pragma once

#include "ICanvas.h"

namespace BitmapGraphics
{
	class IProjector
	{
	public:
		virtual void projectCanvas(HCanvas const& canvas) = 0;
	};

	typedef std::shared_ptr<IProjector> HProjector;
}