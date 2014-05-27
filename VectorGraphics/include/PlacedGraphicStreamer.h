#pragma once

#include "PlacedGraphic.h"
#include "VectorGraphicStreamer.h"
#include "Streamer.h"


namespace VectorGraphics
{
	class PlacedGraphicStreamer :public Streamer
	{
	public:
		PlacedGraphicStreamer();

		static PlacedGraphic fromXml(std::stringstream& xml);
		
		static PlacedGraphic fromNode(const Node& node);

		static Node toNode(const PlacedGraphic& placedGraphic);

		static void toXml(const PlacedGraphic& placedGraphic, std::stringstream& xml);

	private:
	};
}