#pragma once

#include <list>
#include "PlacedGraphic.h"

namespace VectorGraphics
{
	class Layer
	{

	private:
		typedef std::list<PlacedGraphic> PlacedGraphicCollection;

	public:
		typedef PlacedGraphicCollection::iterator PlacedGraphicIterator;
		typedef PlacedGraphicCollection::const_iterator const_PlacedGraphicIterator;

		Layer(const std::string& alias)
			:mAlias(alias){}

		// insert, remove, iteration support.
		void pushBack(const PlacedGraphic& placedGraphic)
		{
			mGraphics.push_back(placedGraphic);
		}
		void remove(const PlacedGraphic& placedGraphic)
		{
			mGraphics.remove(placedGraphic);
		}
		PlacedGraphicIterator begin()
		{
			return mGraphics.begin();
		}
		const_PlacedGraphicIterator begin() const
		{
			return mGraphics.begin();
		}
		PlacedGraphicIterator end()
		{
			return mGraphics.end();
		}
		const_PlacedGraphicIterator end() const
		{
			return mGraphics.end();
		}

		// accessors to alias.
		std::string getAlias() const
		{
			return mAlias;
		}
		void setAlias(const std::string& alias)
		{
			mAlias = alias;
		}
		bool operator==(const Layer& rhs) const
		{
			return mAlias == rhs.mAlias && mGraphics == rhs.mGraphics;
		}
		bool operator!=(const Layer& rhs) const
		{
			return !operator==(rhs);
		}
		void draw(BitmapGraphics::HCanvas hCanvas)
		{
			for (auto pos = begin(); pos != end(); ++pos)
			{
				pos->draw(hCanvas);
			}
		}
	private:
		PlacedGraphicCollection mGraphics;
		std::string mAlias;
	};

}