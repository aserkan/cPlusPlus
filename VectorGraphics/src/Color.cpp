#include "Color.h"
#include <sstream>

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

	int Color::getRedInt() const{ return myRed.toInt(); }
	int Color::getGreenInt() const{ return myGreen.toInt(); }
	int Color::getBlueInt() const{ return myBlue.toInt(); }

	void Color::setRed(const Binary::Byte& red){ myRed = red; }
	void Color::setGreen(const Binary::Byte& green){ myGreen = green; }
	void Color::setBlue(const Binary::Byte& blue){ myBlue = blue; }

	void Color::setRed(int red){ myRed = Binary::Byte::intToByte(red); }
	void Color::setGreen(int green){ myGreen = Binary::Byte::intToByte(green); }
	void Color::setBlue(int blue){ myBlue = Binary::Byte::intToByte(blue); }

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

	Color Color::fromHexString(const std::string& hexString)
	{
		if (hexString.length() != 6) throw std::runtime_error("invalid hexString");
		std::stringstream ssRed, ssGreen, ssBlue;
		int red, green, blue;
		ssRed << hexString.substr(0, 2);
		ssRed >> std::hex >> red;
		ssGreen << hexString.substr(2, 2);
		ssGreen >> std::hex >> green;
		ssBlue << hexString.substr(4, 2);
		ssBlue >> std::hex >> blue;
		return Color(Binary::Byte::intToByte(red), Binary::Byte::intToByte(green), Binary::Byte::intToByte(blue));
	}
	std::string Color::toHexString() const
	{
		std::stringstream ss, ssRed, ssGreen, ssBlue;
		ssRed << std::hex << myRed.toInt();
		ssGreen << std::hex << myRed.toInt();
		ssBlue << std::hex << myRed.toInt();
		ss << ssRed.str() << ssGreen.str() << ssBlue.str();
		return ss.str();
	}

}