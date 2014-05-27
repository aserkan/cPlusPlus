#include "PlacedGraphicStreamer.h"

namespace VectorGraphics
{
	PlacedGraphic PlacedGraphicStreamer::fromXml(std::stringstream& xml)
	{
		Node node = Streamer::fromXml(xml);
		return PlacedGraphicStreamer::fromNode(node);
	}

	PlacedGraphic PlacedGraphicStreamer::fromNode(const Node& node)
	{
		PlacedGraphic placedVecGraphic;
		if (node.getName().compare("PlacedGraphic") != 0) throw std::invalid_argument("Node is not a PlacedGraphic node");
		
		int x = std::stoi(node.getAttributes()["x"]);
		int y = std::stoi(node.getAttributes()["y"]);
		placedVecGraphic.setPlacementPoint(Point(x, y));

		Node child = node.getChildren()[0];
		placedVecGraphic.setGraphic(std::make_shared<VectorGraphic>(VectorGraphicStreamer::fromNode(child)));
	
	return placedVecGraphic;
	}

	Node PlacedGraphicStreamer::toNode(const PlacedGraphic& placedGraphic)
	{
		Node node("PlacedGraphic");
		node.setOpening(true);
		node.addAtribute("x", std::to_string(placedGraphic.getPlacementPoint().getX()));
		node.addAtribute("y", std::to_string(placedGraphic.getPlacementPoint().getY()));
		node.addChild(VectorGraphicStreamer::toNode(placedGraphic.getGraphic()));
		node.setClosing(true);
		return node;
	}


	void PlacedGraphicStreamer::toXml(const PlacedGraphic& placedGraphic, std::stringstream& xml)
	{
		xml << "<PlacedGraphic ";
		xml << "x = \"" << placedGraphic.getPlacementPoint().getX() << "\" ";
		xml << "y = \"" << placedGraphic.getPlacementPoint().getY() << "\" ";
		xml << ">\n";
		VectorGraphicStreamer::toXml(placedGraphic.getGraphic(), xml);
		xml << "</PlacedGraphic>";
	}
}