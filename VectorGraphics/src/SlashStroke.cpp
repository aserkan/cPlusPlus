#include "SlashStroke.h"
#include "SlashPen.h"

namespace BitmapGraphics
{

	SlashStroke::SlashStroke(const int& size, const Color& color)
		: mSize(size), mColor(color)
	{
	}

	void SlashStroke::setSize(int size)
	{
		mSize = size;
	}

	int SlashStroke::getSize() const
	{
		return mSize;
	}

	void SlashStroke::setColor(const Color& color)
	{
		mColor = color;
	}

	Color SlashStroke::getColor() const
	{
		return mColor;
	}

	HPen SlashStroke::createPen() const
	{
		return HPen(new SlashPen(getSize(), getColor()));
	}

}