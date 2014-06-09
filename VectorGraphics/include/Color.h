#pragma once

#include "Byte.h"
#include <iosfwd>
#include <string>

namespace BitmapGraphics
{
	class Color
	{
	public:
		explicit Color(const Binary::Byte& red = 0,
			const Binary::Byte& green = 0,
			const Binary::Byte& blue = 0);

		Binary::Byte getRed() const;
		Binary::Byte getGreen() const;
		Binary::Byte getBlue() const;

		int getRedInt() const;
		int getGreenInt() const;
		int getBlueInt() const;

		void setRed(const Binary::Byte& red);
		void setGreen(const Binary::Byte& green);
		void setBlue(const Binary::Byte& blue);

		void setRed(int red);
		void setGreen(int green);
		void setBlue(int blue);

		static Color read(std::istream& sourceStream);
		void write(std::ostream& destinationStream) const;

		bool operator==(const Color& rhs) const;

		static Color fromHexString(const std::string& hexString);
		std::string toHexString() const;

	private:
		Binary::Byte myRed;
		Binary::Byte myGreen;
		Binary::Byte myBlue;
	};

	std::ostream& operator<<(std::ostream& os, const BitmapGraphics::Color& color);
}