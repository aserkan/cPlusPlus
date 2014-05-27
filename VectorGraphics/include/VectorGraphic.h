#pragma once

#include <string>
#include <vector>
#include <list>
#include <deque>

#include "Point.h"
#include "Node.h"

namespace VectorGraphics
{
	class VectorGraphic
	{
	public:
		VectorGraphic()
			:mOpen(false), minXIndex(-1), maxXIndex(-1), minYIndex(-1), maxYIndex(-1){};
		
		VectorGraphic(const Node& root);

		void addPoint(Point point);
		void addPoint(Point point, int index);	
		void erasePoint(int index);
		bool removePoint(Point point);
		void closeShape();
		void openShape();

		int getPointCount() const;
		Point getPoint(int index) const;		
		bool isClosed() const;		
		bool isOpen() const;
		int getWidth() const;
		int getHeight() const;

		bool operator==(const VectorGraphic& rhs) const;
		bool operator!=(const VectorGraphic& rhs) const;

		friend std::ostream& operator<<(std::ostream& os, const VectorGraphic& vg);
	private:
		std::deque<Point> mPoints;
		bool mOpen;
		int minXIndex;
		int maxXIndex;
		int minYIndex;
		int maxYIndex;
		void updateMinMax(const Point& point, int index, bool insert);
		void update(int pointIndex, int& index, bool max, bool insert, bool coorX);
		void findMinMax(bool max, bool coorX);
	};

	std::ostream& operator<<(std::ostream& os, const VectorGraphic& vg);

}