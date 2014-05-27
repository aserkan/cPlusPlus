#pragma once

#include <sstream>
#include "Scene.h"
#include "Streamer.h"
#include "LayerStreamer.h"


namespace VectorGraphics
{
	class SceneStreamer :public Streamer
	{
	public:
		SceneStreamer();

		static Scene fromXml(std::stringstream& xml);

		static Scene fromNode(const Node& node);
		
		static Node toNode(const Scene& scene);

		static void toXml(const Scene& scene, std::stringstream& xml);

	private:
	};
}