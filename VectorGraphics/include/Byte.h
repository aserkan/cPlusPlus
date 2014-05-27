#pragma once

#include <iostream>

namespace Binary
{
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
	private:
		unsigned char mValue;
	};
}