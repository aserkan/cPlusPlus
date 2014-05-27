#include "VectorGraphicStreamer.h"

namespace VectorGraphics
{
	VectorGraphic VectorGraphicStreamer::fromXml(std::stringstream& xml)
	{
		Node node = Streamer::fromXml(xml);
		return VectorGraphicStreamer::fromNode(node);
	}
	
	VectorGraphic VectorGraphicStreamer::fromNode(const Node& node)
	{
		VectorGraphic vecGraphic;
		if (node.getName().compare("VectorGraphic") != 0) throw std::invalid_argument("Node is not a VectorGraphic node");
		(node.getAttributes()["closed"] == "true") ? vecGraphic.closeShape() : vecGraphic.openShape();
		for (auto child : node.getChildren())
		{
			vecGraphic.addPoint(PointStreamer::fromNode(child));
		}
		return vecGraphic;
	}

	Node VectorGraphicStreamer::toNode(const VectorGraphic& vectorGraphic)
	{
		Node node("VectorGraphic");
		node.setOpening(true);
		node.addAtribute("closed", ((vectorGraphic.isClosed()) ? "true" : "false"));
		for (int i = 0; i < vectorGraphic.getPointCount(); i++)
		{
			node.addChild(PointStreamer::toNode(vectorGraphic.getPoint(i)));
		}
		node.setClosing(true);
		return node;
	}


	void VectorGraphicStreamer::toXml(const VectorGraphic& vecGraphic, std::stringstream& xml)
	{
		xml << "<VectorGraphic closed=\"" << ((vecGraphic.isClosed()) ? "true" : "false") << "\"" << ">\n";
		for (int i = 0; i < vecGraphic.getPointCount(); i++)
		{
			xml << "\t<" << vecGraphic.getPoint(i) << "/>\n";
		}
		xml << "</VectorGraphic>";
	}
}