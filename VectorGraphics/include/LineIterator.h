#pragma once

#include "Point.h"

namespace VectorGraphics
{
	class LineIterator
	{
	public:
		LineIterator(Point const& beginPoint, Point const& endPoint)
			: mBeginPoint(beginPoint), mEndPoint(endPoint), mCurrentPoint(beginPoint)
		{}
		bool isEnd() const
		{
			return mCurrentPoint == mEndPoint;
		}
		Point getBeginPoint() const
		{
			return mBeginPoint;
		}
		Point getEndPoint() const
		{
			return mEndPoint;
		}
		Point getCurrentPoint() const
		{
			return mCurrentPoint;
		}
		void nextPoint()
		{

		}
	private:
		Point mBeginPoint;
		Point mEndPoint;
		Point mCurrentPoint;
	};
}