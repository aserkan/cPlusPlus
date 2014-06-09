#include "SquareStroke.h"
#include "SquarePen.h"

namespace BitmapGraphics
{

	SquareStroke::SquareStroke(const int& size, const Color& color)
		: mSize(size), mColor(color)
	{
	}

	void SquareStroke::setSize(int size)
	{
		mSize = size;
	}

	int SquareStroke::getSize() const
	{
		return mSize;
	}

	void SquareStroke::setColor(const Color& color)
	{
		mColor = color;
	}

	Color SquareStroke::getColor() const
	{
		return mColor;
	}

	HPen SquareStroke::createPen() const
	{
		return HPen(new SquarePen(getSize(), getColor()));
	}

}