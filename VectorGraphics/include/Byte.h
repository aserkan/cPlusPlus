#pragma once

#include <iostream>
#include <cstdint>
#include <string>

namespace Binary
{
	//union ByteValue
	//{
	//	uint16_t intValue;
	//	unsigned char byte;
	//};

	class Byte
	{
	public:
		Byte(unsigned char value = 0) : mValue(value){}
		operator unsigned char() const
		{
			return mValue;
		}
		Byte& operator=(const Byte& original)
		{
			mValue = original.mValue;
			return *this;
		}
		Byte& operator=(unsigned char value)
		{
			mValue = value;
			return *this;
		}

		static Byte read(std::istream& sourceStream)
		{
			return sourceStream.get();
		}
		void write(std::ostream& destinationStream) const
		{
			destinationStream.put(mValue);
		}

		int toInt() const
		{
			return (int)mValue;
		}
		static Byte intToByte(int value)
		{
			if (value < 0) value = 0;
			else if (value> 255) value = 255;
			Byte returnByte;
			returnByte.mValue = (char)value;
			return returnByte;
		}
	private:
		unsigned char mValue;
	};
}