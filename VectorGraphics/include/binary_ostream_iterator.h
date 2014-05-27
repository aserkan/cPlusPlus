#pragma once

namespace BitmapGraphics
{

	template <typename T>
	class binary_ostream_iterator : public std::iterator<std::output_iterator_tag, T>
	{
	protected:
		// stream to which output will be written
		std::ostream& myOutputStream;

	public:
		explicit binary_ostream_iterator(std::ostream& outputStream) : myOutputStream(outputStream) { }

		binary_ostream_iterator <T>& operator=(const T& value)
		{
			// do something here
			value.write(myOutputStream);
			return *this;
		}

		// dereference is a no-op
		binary_ostream_iterator <T>& operator*()
		{
			return *this;
		}

		// increment is a no-op
		binary_ostream_iterator <T>& operator++()
		{
			return *this;
		}

		binary_ostream_iterator <T>& operator++(int)
		{
			return *this;
		}
	};
}