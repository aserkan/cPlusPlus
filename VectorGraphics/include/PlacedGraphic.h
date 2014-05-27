#pragma once

#include <memory>

#include "VectorGraphic.h"

namespace VectorGraphics
{
	typedef std::shared_ptr<VectorGraphic> HVectorGraphic;

	class PlacedGraphic 
	{
	public:
		PlacedGraphic(const Point& point, HVectorGraphic hVectorGraphic)
			:mPlacementPoint(point), mGraphic(hVectorGraphic){}

		PlacedGraphic()
			: mPlacementPoint(Point(0, 0)), mGraphic(std::make_shared<VectorGraphic>()){}

		void setPlacementPoint(Point const& placement)
		{
			mPlacementPoint = placement;
		}
		Point const& getPlacementPoint() const
		{
			return mPlacementPoint;
		}
		void setGraphic(HVectorGraphic const& graphic)
		{
			mGraphic = graphic;
		}
		VectorGraphic const& getGraphic() const
		{
			return *(mGraphic.get());
		}
		bool operator==(const PlacedGraphic& rhs) const
		{
			return (mPlacementPoint == rhs.mPlacementPoint) && (*mGraphic.get() == *rhs.mGraphic.get());
		}
		bool operator!=(const PlacedGraphic& rhs) const
		{
			return !operator==(rhs); 
		}

	private:
		Point mPlacementPoint;
		HVectorGraphic mGraphic;
	};

}
