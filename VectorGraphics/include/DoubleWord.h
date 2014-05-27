#pragma once

#include <iostream>
#include <cstdint>

namespace Binary
{
	union DoubleWordValue
	{
		uint32_t doubleWord;
		unsigned char bytes[4];
	};

	class DoubleWord
	{
	public:
		DoubleWord(unsigned long value = 0) : mValue(value){}
		operator unsigned long() const { return mValue; }
		DoubleWord& operator=(const DoubleWord& original)
		{
			mValue = original.mValue;
			return *this;
		}
		DoubleWord& operator=(unsigned long value)
		{
			mValue = value;
			return *this;
		}
		static DoubleWord readLittleEndian(std::istream& sourceStream);
		void writeLittleEndian(std::ostream& destinationStream) const;
		static DoubleWord readBigEndian(std::istream& sourceStream);
		void writeBigEndian(std::ostream& destinationStream) const;

	private:
		uint32_t mValue;

		void writeNativeOrder(std::ostream& destinationStream) const;
		void writeSwappedOrder(std::ostream& destinationStream) const;

		static DoubleWord readNativeOrder(std::istream& sourceStream);
		static DoubleWord readSwappedOrder(std::istream& sourceStream);

	};
}