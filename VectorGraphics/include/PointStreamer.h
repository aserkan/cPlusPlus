#pragma once

#include <sstream>
#include "Point.h"
#include "Streamer.h"


namespace VectorGraphics
{
	class PointStreamer :public Streamer
	{
	public:
		PointStreamer();

		static Point fromXml(std::stringstream& xml);

		static Point fromNode(const Node& node);

		static Node toNode(const Point& point);

		static void toXml(const Point& point, std::stringstream& xml);

	private:
	};
}