#pragma once

#include <list>

#include "Layer.h"
#include "ICanvas.h"

namespace VectorGraphics
{
	class Scene
	{
	private:
		typedef std::list<Layer> LayerCollection;

	public:
		typedef LayerCollection::iterator LayerIterator;
		typedef LayerCollection::const_iterator const_LayerIterator;

		// insert, remove, iteration support.
		void pushBack(const Layer& layer)
		{
			mLayers.push_back(layer);
		}
		void remove(const Layer& layer)
		{
			mLayers.remove(layer);
		}

		LayerIterator begin()
		{
			return mLayers.begin();
		}

		const_LayerIterator begin() const
		{
			return mLayers.begin();
		}

		LayerIterator end()
		{
			return mLayers.end();
		}

		const_LayerIterator end() const
		{
			return mLayers.end();
		}

		bool operator==(const Scene& rhs) const
		{
			return mHeight == rhs.mHeight && mWidth == rhs.mWidth && mLayers == rhs.mLayers;
		}

		bool operator!=(const Scene& rhs) const
		{
			return operator==(rhs);
		}
		// accessors to width and height.
		int getWidth() const
		{
			return mWidth;
		}
		int getHeight() const
		{
			return mHeight;
		}
		void setWidth(int width)
		{
			mWidth = width;
		}
		void setHeight(int height)
		{
			mHeight = height;
		}

		void draw(BitmapGraphics::HCanvas hCanvas)
		{
			if ((mHeight > hCanvas->getHeight()) || (mWidth > hCanvas->getWidth()))
				throw std::runtime_error("draw error: scene greater than canvas");

			for (auto pos = begin(); pos != end(); ++pos)
			{
				pos->draw(hCanvas);
			}
		}

	private:
		LayerCollection mLayers;
		int mWidth;
		int mHeight;
	};
}