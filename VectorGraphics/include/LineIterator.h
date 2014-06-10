#pragma once

#include "Point.h"

// Bresenham's algorithm used for the next point calculation
// http://rosettacode.org/wiki/Bitmap/Bresenham's_line_algorithm
namespace VectorGraphics
{
	class LineIterator
	{
	public:
		LineIterator(Point const& beginPoint, Point const& endPoint)
			: mBeginPoint(beginPoint), mEndPoint(endPoint), mCurrentPoint(beginPoint)
		{
			xOrientation = ( mEndPoint.getX() > mBeginPoint.getX() ) ? 1 : -1;
			yOrientation = ( mEndPoint.getY() > mBeginPoint.getY() ) ? 1 : -1;
			xDistance = abs(mEndPoint.getX() - mBeginPoint.getX());
			yDistance = abs(mEndPoint.getY() - mBeginPoint.getY());
			//error = ((xDistance >yDistance) ? xDistance : yDistance) / 2;
			error = xDistance - yDistance;
		}
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
			int nextX, nextY;
			if (isEnd()) return;
			//int tempError = error;
			int tempError = error *2;
			if (tempError > (-1 * xDistance))
			{
				error -= yDistance;
				nextX = mCurrentPoint.getX() + xOrientation;
				mCurrentPoint.setX(nextX);
			}
			if (tempError < yDistance)
			{
				error += xDistance;
				nextY = mCurrentPoint.getY() + yOrientation;
				mCurrentPoint.setY(nextY);
			}
		}
	private:
		Point mBeginPoint;
		Point mEndPoint;
		Point mCurrentPoint;
		int xOrientation;
		int yOrientation;
		int xDistance;
		int yDistance;
		int error;
	};
}