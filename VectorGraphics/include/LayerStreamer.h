#pragma once

#include "Layer.h"
#include "PlacedGraphicStreamer.h"
#include "Streamer.h"


namespace VectorGraphics
{
	class LayerStreamer :public Streamer
	{
	public:
		LayerStreamer();

		static Layer fromXml(std::stringstream& xml);

		static Layer fromNode(const Node& node);
		
		static Node toNode(const Layer& layer);

		static void toXml(const Layer& layer, std::stringstream& xml);

	private:
	};
}