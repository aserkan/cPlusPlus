#pragma once

#include <sstream>
#include "IStroke.h"
#include "Streamer.h"


namespace VectorGraphics
{
	class StrokeStreamer :public Streamer
	{
	public:
		StrokeStreamer();

		static BitmapGraphics::HStroke fromXml(std::stringstream& xml);

		static BitmapGraphics::HStroke fromNode(const Node& node);

		static Node toNode(const BitmapGraphics::HStroke stroke);

		static void toXml(const BitmapGraphics::HStroke stroke, std::stringstream& xml);

	private:
		static std::string getTip(const BitmapGraphics::HStroke stroke);
		//static BitmapGraphics::HStroke getStroke(std::string tip);
	};
}