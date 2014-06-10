#include "VectorGraphic.h"
#include "LineIterator.h"

namespace VectorGraphics
{
	void VectorGraphic::addPoint(Point point)
	{
		mPoints.push_back(point);
		updateMinMax(point, mPoints.size() - 1, true);
	}

	void VectorGraphic::addPoint(Point point, int index)
	{
		if (index<0 || index>mPoints.size()) throw std::out_of_range("index out of range");
		auto iter = mPoints.begin();
		for (int i = 0; i < index; i++) iter++;
		mPoints.insert(iter, point);

		updateMinMax(point, index, true);
	}

	void VectorGraphic::erasePoint(int index)
	{
		if (index<0 || index>mPoints.size()) throw std::out_of_range("index out of range");
		Point point = mPoints[index];
		auto iter = mPoints.begin();
		for (int i = 0; i < index; i++) iter++;
		mPoints.erase(iter);

		updateMinMax(point, index, false);
	}

	bool VectorGraphic::removePoint(Point point)
	{
		bool found = false;
		auto iter = mPoints.begin();
		int index = 0;
		while (iter != mPoints.end() && !found)
		{
			if (*iter == point) found = true;
			else
			{
				iter++;
				index++;
			}
		}
		if (found)
		{
			mPoints.erase(iter);
			updateMinMax(point, index, false);
		}
		return found;
	}

	int VectorGraphic::getPointCount() const
	{
		return mPoints.size();
	}

	Point VectorGraphic::getPoint(int index) const
	{
		if (index < mPoints.size()) return mPoints[index];
		else throw std::out_of_range("index out of range");
	}

	bool VectorGraphic::isClosed() const
	{
		return !mOpen;
	}

	bool VectorGraphic::isOpen() const
	{
		return mOpen;
	}

	void VectorGraphic::closeShape()
	{
		mOpen = false;
	}

	void VectorGraphic::openShape()
	{
		mOpen = true;
	}

	int VectorGraphic::getWidth() const
	{
		return mPoints[maxXIndex].getX() - mPoints[minXIndex].getX();
	}

	int VectorGraphic::getHeight() const
	{
		return mPoints[maxYIndex].getY() - mPoints[minYIndex].getY();
	}


	void VectorGraphic::setStroke(BitmapGraphics::HStroke hStroke)
	{
		mStroke = hStroke;
	}
	BitmapGraphics::HStroke VectorGraphic::getStroke()
	{
		return mStroke;
	}

	void VectorGraphic::updateMinMax(const Point& point, int index, bool insert)
	{
		update(index, minXIndex, false, insert, true);
		update(index, maxXIndex, true, insert, true);
		update(index, minYIndex, false, insert, false);
		update(index, maxYIndex, true, insert, false);
	}

	void VectorGraphic::update(int pointIndex, int& index, bool max, bool insert, bool coorX)
	{
		if (index == -1)
		{
			if (!insert) throw std::out_of_range("deleting from empty list");
			else index = 0;
			return;
		}

		if (insert)
		{
			int pointVal = coorX ? mPoints[pointIndex].getX() : mPoints[pointIndex].getY();
			int indexVal = coorX ? mPoints[index].getX() : mPoints[index].getY();
			if (max && (pointVal > indexVal)) index = pointIndex;
			else if (!max && (pointVal < indexVal)) index = pointIndex;
			else if (pointIndex <= index) index++;
		}
		else
		{
			if (pointIndex == index) findMinMax(max, coorX);
			else if (pointIndex < index) index--;
		}
	}

	void VectorGraphic::findMinMax(bool max, bool coorX)
	{
		if (mPoints.empty())
		{
			if (coorX) max ? (maxXIndex = -1) : (minXIndex = -1);
			else max ? (maxYIndex = -1) : (minYIndex = -1);
			return;
		}

		int newIndex = 0;
		for (int indexCount = 0; indexCount< mPoints.size(); indexCount++)
		{
			int localVal = coorX ? mPoints[indexCount].getX() : mPoints[indexCount].getY();
			int compareVal = coorX ? (mPoints[newIndex].getX()) : (mPoints[newIndex].getY());
			bool needForChange = max ? (localVal > compareVal) : (localVal < compareVal);
			if (needForChange) newIndex = indexCount;
		}

		if (coorX) max ? (maxXIndex = newIndex) : (minXIndex = newIndex);
		else max ? (maxYIndex = newIndex) : (minYIndex = newIndex);
	}


	bool VectorGraphic::operator==(const VectorGraphic& rhs) const
	{
		return ((mOpen == rhs.mOpen) && mPoints==rhs.mPoints);
	}
	bool VectorGraphic::operator!=(const VectorGraphic& rhs) const
	{
		return !operator==(rhs);
	}

	void VectorGraphic::draw(BitmapGraphics::HCanvas hCanvas, const Point& offset)
	{
		auto iter = mPoints.begin();
		while (iter != mPoints.end())
		{
			Point start = *iter, end = *iter;
			if (++iter == mPoints.end())
			{
				if (isClosed()) end = *(mPoints.begin()); //connect end point to start point
				else return; //open shape, no need to draw line
			}
			else end = *iter;
			LineIterator lineIterator(start, end);
			while (!lineIterator.isEnd())
			{
				mStroke->createPen()->drawPoint(hCanvas, lineIterator.getCurrentPoint() + offset);
				lineIterator.nextPoint();
			}
			mStroke->createPen()->drawPoint(hCanvas, lineIterator.getEndPoint() + offset);

		}

		//for (auto iter = mPoints.begin(); iter != mPoints.end(); iter++)
		//{
		//	mStroke->createPen()->drawPoint(hCanvas, (*iter)+offset);

		//}
	}


	std::ostream& operator<<(std::ostream& os, const VectorGraphic& vg)
	{
		os << "VectorGraphic closed=\"" << ((vg.mOpen) ? "false" : "true") << "\"" << '\n';
		for (auto iter = vg.mPoints.begin(); iter != vg.mPoints.end(); iter++)
		{
			os <<  *iter << '\n';
		}
		return os;
	}

}