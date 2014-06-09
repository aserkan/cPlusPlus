#pragma once

#include "IPen.h"
#include "ICanvas.h"
#include "Color.h"

namespace BitmapGraphics
{

	class SquarePen : public IPen
	{
	public:
		SquarePen(int size, const Color& color);
		virtual void drawPoint(const HCanvas& canvas, const VectorGraphics::Point& point);

	private:
		int mSize;
		Color mColor;
	};

}