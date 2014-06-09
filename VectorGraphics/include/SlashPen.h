#pragma once

#include "IPen.h"
#include "ICanvas.h"
#include "Color.h"

namespace BitmapGraphics
{

	class SlashPen : public IPen
	{
	public:
		SlashPen(int size, const Color& color);
		virtual void drawPoint(const HCanvas& canvas, const VectorGraphics::Point& point);

	private:
		int mSize;
		Color mColor;
	};

}