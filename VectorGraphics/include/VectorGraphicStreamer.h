#pragma once

#include <sstream>
#include "VectorGraphic.h"
#include "PointStreamer.h"
#include "Streamer.h"


namespace VectorGraphics
{
	class VectorGraphicStreamer:public Streamer
	{
	public:
		VectorGraphicStreamer();

		static VectorGraphic fromXml(std::stringstream& xml);

		static VectorGraphic fromNode(const Node& node);

		static Node toNode(const VectorGraphic& vectorGraphic);

		static void toXml(const VectorGraphic& vectorGraphic, std::stringstream& xml);

	private:
	};
}