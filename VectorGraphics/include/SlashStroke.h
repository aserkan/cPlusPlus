#pragma once

#include "IStroke.h"

namespace BitmapGraphics
{
	class SlashStroke : public IStroke
	{
	public:
		SlashStroke(const int& size, const Color& color);

		virtual void setSize(int size);
		virtual int getSize() const;
		virtual void setColor(const Color& color);
		virtual Color getColor() const;
		virtual HPen createPen() const;

	protected:
		int mSize;
		Color mColor;
	};

}
