#include "DoubleWord.h"

namespace Binary
{
	union WordValue
	{
		uint32_t word;
		unsigned char bytes[4];
	};

	DoubleWord DoubleWord::readLittleEndian(std::istream& sourceStream)
	{
#ifdef Little_Endian_
		return readNativeOrder(sourceStream);
#else
		return readSwappedOrder(sourceStream);
#endif
	}

	DoubleWord DoubleWord::readBigEndian(std::istream& sourceStream)
	{
#ifdef Little_Endian_
		return readSwappedOrder(sourceStream);
#else
		return readNativeOrder(sourceStream);
#endif	
	}

	void DoubleWord::writeLittleEndian(std::ostream& destinationStream) const
	{
	#ifdef Little_Endian_
		writeNativeOrder(destinationStream);
	#else
		writeSwappedOrder(destinationStream);
	#endif
	}

	void DoubleWord::writeBigEndian(std::ostream& destinationStream) const
	{
	#ifdef Little_Endian_
		writeSwappedOrder(destinationStream);
	#else
		writeNativeOrder(destinationStream);
	#endif

	}

	void DoubleWord::writeNativeOrder(std::ostream& destinationStream) const
	{
		DoubleWordValue value;
		value.doubleWord = mValue;

		destinationStream.put(value.bytes[0]);
		destinationStream.put(value.bytes[1]);
		destinationStream.put(value.bytes[2]);
		destinationStream.put(value.bytes[3]);
	}
	void DoubleWord::writeSwappedOrder(std::ostream& destinationStream) const
	{
		DoubleWordValue value;
		value.doubleWord = mValue;

		destinationStream.put(value.bytes[3]);
		destinationStream.put(value.bytes[2]);
		destinationStream.put(value.bytes[1]);
		destinationStream.put(value.bytes[0]);
	}

	DoubleWord DoubleWord::readNativeOrder(std::istream& sourceStream)
	{
		WordValue value;

		value.bytes[0] = sourceStream.get();
		value.bytes[1] = sourceStream.get();
		value.bytes[2] = sourceStream.get();
		value.bytes[3] = sourceStream.get();

		return value.word;
	}

	DoubleWord DoubleWord::readSwappedOrder(std::istream& sourceStream)
	{
		WordValue value;

		value.bytes[3] = sourceStream.get();
		value.bytes[2] = sourceStream.get();
		value.bytes[1] = sourceStream.get();
		value.bytes[0] = sourceStream.get();

		return value.word;
	}

}
