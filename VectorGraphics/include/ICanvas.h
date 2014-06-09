#pragma once
#include <memory>
#include "Color.h"
#include "Point.h"
#include "IBitmapIterator.h"

namespace BitmapGraphics
{
	class ICanvas;
	typedef std::shared_ptr<ICanvas> HCanvas;

	class ICanvas
	{
	public:
		virtual ~ICanvas(){}
		virtual void setPixelColor(const VectorGraphics::Point& location, const Color& color) = 0;
		virtual Color getPixelColor(const VectorGraphics::Point& location) const = 0;
		virtual int getWidth() const = 0;
		virtual int getHeight() const = 0;
		virtual HBitmapIterator createBitmapIterator() = 0;
		//virtual const_HBitmapIterator createBitmapIterator() const = 0;
	private:
	};
}