#pragma once

#include "IBitmapIterator.h"
#include "Color.h"

namespace BitmapGraphics
{
	class BrightnessDecorator : public IBitmapIterator
	{
	public:
		BrightnessDecorator(const HBitmapIterator& originalIterator, int brightnessAdjustment = 0) :
			myOriginalIterator(originalIterator), myBrightnessAdjustment(brightnessAdjustment)
		{

		}
		
		void setBrightnessAdjustment (int brightnessAdjustment) {
			myBrightnessAdjustment = brightnessAdjustment;
		}

		int getBrightnessAdjustment () const {
			myBrightnessAdjustment;
		}		
		
		virtual void nextScanLine() { myOriginalIterator->nextScanLine(); }
		virtual bool isEndOfImage() const { return myOriginalIterator->isEndOfImage(); }
		virtual void nextPixel() { myOriginalIterator->nextPixel(); }
		virtual bool isEndOfScanLine() const { return myOriginalIterator->isEndOfScanLine(); }

		virtual int getBitmapWidth() const { return myOriginalIterator->getBitmapWidth(); }
		virtual int getBitmapHeight() const { return myOriginalIterator->getBitmapHeight(); }

		//virtual Color getColor() const
		//{
		//	Color originalColor = myOriginalIterator->getColor();

		//	int averageIntensity = (originalColor.getRed() + originalColor.getGreen() + originalColor.getBlue()) / 3;

		//	return Color(averageIntensity, averageIntensity, averageIntensity);
		//}


		//virtual Color getColor() const {
		//	Color const oldColor = myOriginalIterator->getColor();
		//	int red = oldColor.getRed() + myBrightnessAdjustment;
		//	if (red > 255) {
		//		red = 255;
		//	}
		//	else if (red < 0) {
		//		red = 0;
		//	}

		//	int green = oldColor.getGreen() + myBrightnessAdjustment;
		//	if (green > 255) {
		//		green = 255;
		//	}
		//	else if (green < 0) {
		//		green = 0;
		//	}
		//	int blue = oldColor.getBlue() + myBrightnessAdjustment;
		//	if (blue > 255) {
		//		blue = 255;
		//	}
		//	else if (blue < 0) {
		//		blue = 0;
		//	}

		//	return Color(red, green, blue);
		//}

		virtual Color getColor() const 
		{
			Color adjustedColor = myOriginalIterator->getColor();
			adjustedColor.setRed(adjustColorComponent(adjustedColor.getRedInt()));
			adjustedColor.setGreen(adjustColorComponent(adjustedColor.getGreenInt()));
			adjustedColor.setBlue(adjustColorComponent(adjustedColor.getBlueInt()));

			return adjustedColor;
		}

	private:
		int myBrightnessAdjustment;
		HBitmapIterator myOriginalIterator;

		int adjustColorComponent(int colorComponent) const
		{
			int adjustedColorComponent = colorComponent + myBrightnessAdjustment;
			if (adjustedColorComponent > 255) 
			{
				adjustedColorComponent = 255;
			}
			else if (adjustedColorComponent < 0) 
			{
				adjustedColorComponent = 0;
			}
			return adjustedColorComponent;
		}
	};
}