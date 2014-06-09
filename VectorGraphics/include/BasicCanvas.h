#pragma once

#include <memory>
#include <map>
#include "ICanvas.h"

namespace BitmapGraphics
{
	class BasicCanvas : public ICanvas
	{
	public:
		typedef std::map<VectorGraphics::Point, Color>::iterator PointColorMapIterator;
		typedef std::map<VectorGraphics::Point, Color>::const_iterator const_PointColorMapIterator;

		BasicCanvas(int width, int height, Color color);
		virtual void setPixelColor(const VectorGraphics::Point& location, const Color& color);
		virtual Color getPixelColor(const VectorGraphics::Point& location) const;
		virtual int getWidth() const;
		virtual int getHeight() const;

		virtual PointColorMapIterator begin();
		virtual PointColorMapIterator end();

		virtual const_PointColorMapIterator begin() const;
		virtual const_PointColorMapIterator end() const;

		virtual HBitmapIterator createBitmapIterator();
		//virtual const_HBitmapIterator createBitmapIterator() const;
	private:
		int mWidth;
		int mHeight;
		Color mBackgroundColor;
		std::map<VectorGraphics::Point, Color> mPixels;
	};

}


