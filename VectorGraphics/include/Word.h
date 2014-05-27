#pragma once

#include <iosfwd>
#include <cstdint>

namespace Binary
{
	class Word
	{
	public:
		Word(uint16_t value = 0);
		operator uint16_t() const;
		//bool operator==(const Word& rhs){ return myValue == rhs.myValue; };
		//bool operator!=(const Word& rhs){ return !(operator==(rhs)); };

		void writeLittleEndian(std::ostream& destinationStream) const;
		void writeBigEndian(std::ostream& destinationStream) const;

		static Word readBigEndian(std::istream& sourceStream);
		static Word readLittleEndian(std::istream& sourceStream);

	private:
		uint16_t myValue;

		void writeNativeOrder(std::ostream& destinationStream) const;
		void writeSwappedOrder(std::ostream& destinationStream) const;

		static Word readNativeOrder(std::istream& sourceStream);
		static Word readSwappedOrder(std::istream& sourceStream);
	};
}