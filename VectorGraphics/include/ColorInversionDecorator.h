#pragma once

#include "IBitmapIterator.h"
#include "Color.h"

namespace BitmapGraphics
{
	class ColorInversionDecorator : public IBitmapIterator
	{
	public:
		ColorInversionDecorator(const HBitmapIterator& originalIterator) :
			myOriginalIterator(originalIterator)
		{

		}

		virtual void nextScanLine() { myOriginalIterator->nextScanLine(); }
		virtual bool isEndOfImage() const { return myOriginalIterator->isEndOfImage(); }
		virtual void nextPixel() { myOriginalIterator->nextPixel(); }
		virtual bool isEndOfScanLine() const { return myOriginalIterator->isEndOfScanLine(); }

		virtual int getBitmapWidth() const { return myOriginalIterator->getBitmapWidth(); }
		virtual int getBitmapHeight() const { return myOriginalIterator->getBitmapHeight(); }

		virtual Color getColor() const
		{
			Color adjustedColor = myOriginalIterator->getColor();
			adjustedColor.setRed(inverseColorComponent(adjustedColor.getRedInt()));
			adjustedColor.setGreen(inverseColorComponent(adjustedColor.getGreenInt()));
			adjustedColor.setBlue(inverseColorComponent(adjustedColor.getBlueInt()));

			return adjustedColor;
		}

	private:
		HBitmapIterator myOriginalIterator;
		static int inverseColorComponent(int colorComponent)
		{
			int adjustedColorComponent = (255 - colorComponent) % 255;
			return adjustedColorComponent;
		}
	};
}