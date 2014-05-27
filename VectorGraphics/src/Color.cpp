#include "Color.h"

namespace BitmapGraphics
{
	Color::Color(const Binary::Byte& red,
		const Binary::Byte& green,
		const Binary::Byte& blue) :
		myRed(red),
		myGreen(green),
		myBlue(blue)
	{
	}

	Binary::Byte Color::getRed() const { return myRed; }
	Binary::Byte Color::getGreen() const { return myGreen; }
	Binary::Byte Color::getBlue() const { return myBlue; }

	Color Color::read(std::istream& sourceStream)
	{
		Binary::Byte blue = Binary::Byte::read(sourceStream);
		Binary::Byte green = Binary::Byte::read(sourceStream);
		Binary::Byte red = Binary::Byte::read(sourceStream);

		return Color(red, green, blue);
	}

	void Color::write(std::ostream& destinationStream) const
	{
		myBlue.write(destinationStream);
		myGreen.write(destinationStream);
		myRed.write(destinationStream);
	}

	bool Color::operator==(const Color& rhs) const
	{
		return (getRed() == rhs.getRed()) && (getGreen() == rhs.getGreen()) && (getBlue() == rhs.getBlue());
	}
	
	std::ostream& operator<<(std::ostream& os, const BitmapGraphics::Color& color)
	{
		color.write(os);
		return os;
	}

}