#include "PointStreamer.h"


namespace VectorGraphics
{
	Point PointStreamer::fromXml(std::stringstream& xml)
	{
		Node node = Streamer::fromXml(xml);
		return fromNode(node);
	}

	Point PointStreamer::fromNode(const Node& node)
	{
		if (node.getName().compare("Point") != 0) throw std::invalid_argument("Node is not a Point node");
		int x = std::stoi(node.getAttributes()["x"]);
		int y = std::stoi(node.getAttributes()["y"]);
		return Point(x, y);
	}

	Node PointStreamer::toNode(const Point& point)
	{
		Node node("Point");
		node.setOpening(true);
		node.addAtribute("x", std::to_string(point.getX()));
		node.addAtribute("y", std::to_string(point.getY()));
		node.setClosing(true);
		return node;
	}

	
	void PointStreamer::toXml(const Point& point, std::stringstream& xml)
	{
		xml << "<Point " << "x=\"" << point.getX() << "\" y=\"" << point.getY() << "\>";
	}
}