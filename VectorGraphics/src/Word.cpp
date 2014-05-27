#include "Word.h"
#include <iostream>

namespace Binary
{
	union WordValue
	{
		uint16_t word;
		unsigned char bytes[2];
	};

	Word::Word(uint16_t value)
	{
		myValue = value;
	}

	Word::operator uint16_t() const
	{
		return myValue;
	}

	void Word::writeLittleEndian(std::ostream& destinationStream) const
	{
#ifdef Little_Endian_
		writeNativeOrder(destinationStream);
#else
		writeSwappedOrder(destinationStream);
#endif
	}

	void Word::writeBigEndian(std::ostream& destinationStream) const
	{
#ifdef Little_Endian_
		writeSwappedOrder(destinationStream);
#else
		writeNativeOrder(destinationStream);
#endif
	}

	Word Word::readBigEndian(std::istream& sourceStream)
	{
#ifdef Little_Endian_
		return readSwappedOrder(sourceStream);
#else
		return readNativeOrder(sourceStream);
#endif	
	}

	Word Word::readLittleEndian(std::istream& sourceStream)
	{
#ifdef Little_Endian_
		return readNativeOrder(sourceStream);
#else
		return readSwappedOrder(sourceStream);
#endif
	}


	Word Word::readNativeOrder(std::istream& sourceStream)
	{
		WordValue value;

		value.bytes[0] = sourceStream.get();
		value.bytes[1] = sourceStream.get();

		return value.word;
	}

	Word Word::readSwappedOrder(std::istream& sourceStream)
	{
		WordValue value;

		value.bytes[1] = sourceStream.get();
		value.bytes[0] = sourceStream.get();

		return value.word;
	}

	void Word::writeNativeOrder(std::ostream& destinationStream) const
	{
		WordValue value;
		value.word = myValue;

		destinationStream.put(value.bytes[0]);
		destinationStream.put(value.bytes[1]);
	}

	void Word::writeSwappedOrder(std::ostream& destinationStream) const
	{
		WordValue value;
		value.word = myValue;

		destinationStream.put(value.bytes[1]);
		destinationStream.put(value.bytes[0]);
	}
}