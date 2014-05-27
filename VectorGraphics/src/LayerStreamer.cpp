#include "LayerStreamer.h"

namespace VectorGraphics
{
	Layer LayerStreamer::fromXml(std::stringstream& xml)
	{
		Node node = Streamer::fromXml(xml);
		return LayerStreamer::fromNode(node);
	}

	Layer LayerStreamer::fromNode(const Node& node)
	{
		if (node.getName().compare("Layer") != 0) throw std::invalid_argument("Node is not a Layer node");
		std::string alias = node.getAttributes()["alias"];
		Layer layer(alias);

		for (auto child : node.getChildren())
		{
			layer.pushBack(PlacedGraphicStreamer::fromNode(child));
		}
		return layer;
	}

	Node LayerStreamer::toNode(const Layer& layer)
	{
		Node node("Layer");
		node.setOpening(true);
		node.addAtribute("alias", layer.getAlias());
		for (auto pos = layer.begin(); pos != layer.end(); pos++)
		{
			node.addChild(PlacedGraphicStreamer::toNode(*pos));
		}
		node.setClosing(true);
		return node;
	}

	void LayerStreamer::toXml(const Layer& layer, std::stringstream& xml)
	{
		xml << "<Layer alias=\"" << layer.getAlias()<<"\"" << ">\n";
		for (auto pos = layer.begin(); pos != layer.end(); ++pos)
		{
			PlacedGraphicStreamer::toXml(*pos, xml);
		}
		xml << "</Layer>";
	}
}