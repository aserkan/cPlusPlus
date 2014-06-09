#pragma once

#include <memory>
#include "ICanvas.h"

namespace BitmapGraphics
{
	class IPen;
	typedef std::shared_ptr<IPen> HPen;

	class IPen
	{
	public:
		virtual ~IPen(){}
		virtual void drawPoint(const HCanvas& canvas, const VectorGraphics::Point& point) = 0;

	private:
	};

}