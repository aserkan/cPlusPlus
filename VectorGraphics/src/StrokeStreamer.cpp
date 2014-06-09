#include "StrokeStreamer.h"

#include "SquareStroke.h"
#include "SlashStroke.h"

namespace VectorGraphics
{
	BitmapGraphics::HStroke StrokeStreamer::fromXml(std::stringstream& xml)
	{
		Node node = Streamer::fromXml(xml);
		return fromNode(node);
	}

	BitmapGraphics::HStroke StrokeStreamer::fromNode(const Node& node)
	{
		if (node.getName().compare("Stroke") != 0) throw std::invalid_argument("Node is not a Stroke node");
		std::string sColor = node.getAttributes()["color"];
		BitmapGraphics::Color cColor = BitmapGraphics::Color::fromHexString(sColor);
		int size = std::stoi(node.getAttributes()["size"]);
		std::string sTip = node.getAttributes()["tip"];
		if (sTip.compare("square") == 0) return BitmapGraphics::HStroke(new BitmapGraphics::SquareStroke(size, cColor));
		else if (sTip.compare("slash") == 0) return BitmapGraphics::HStroke(new BitmapGraphics::SlashStroke(size, cColor));
		else throw std::runtime_error("unspecified stroke type");
	}

	Node StrokeStreamer::toNode(const BitmapGraphics::HStroke stroke)
	{
		Node node("Stroke");
		node.setOpening(true);
		BitmapGraphics::Color strokeColor = stroke->getColor();
		std::string sColor = strokeColor.toHexString();
		node.addAtribute("color", sColor);
		node.addAtribute("size", std::to_string(stroke->getSize()));
		node.addAtribute("tip", getTip(stroke));
		node.setClosing(true);
		return node;
	}
	void StrokeStreamer::toXml(const BitmapGraphics::HStroke stroke, std::stringstream& xml)
	{
		xml << "<Stroke " << "color=\"" << stroke->getColor() << "\" size=\"" << stroke->getSize() << "\" tip=\"" << getTip(stroke)<< "\>";
	}

	std::string StrokeStreamer::getTip(const BitmapGraphics::HStroke stroke)
	{
		if (dynamic_cast<BitmapGraphics::SquareStroke*>(stroke.get())) return "square";
		else if (dynamic_cast<BitmapGraphics::SlashStroke*>(stroke.get())) return "slash";
		else return "unspecified tip type";

	}

}