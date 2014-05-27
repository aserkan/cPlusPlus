#include "SceneStreamer.h"


namespace VectorGraphics
{
	Scene SceneStreamer::fromXml(std::stringstream& xml)
	{
		Node node = Streamer::fromXml(xml);
		return SceneStreamer::fromNode(node);
	}

	Scene SceneStreamer::fromNode(const Node& node)
	{
		Scene scene;
		if (node.getName().compare("Scene") != 0) throw std::invalid_argument("Node is not a Scene node");
		int width = std::stoi(node.getAttributes()["width"]);
		int height = std::stoi(node.getAttributes()["height"]);
		scene.setWidth(width);
		scene.setHeight(height);
		for (auto child : node.getChildren())
		{
			scene.pushBack(LayerStreamer::fromNode(child));
		}
		return scene;
	}

	Node SceneStreamer::toNode(const Scene& scene)
	{
		Node node("Scene");
		node.setOpening(true);
		node.addAtribute("width", std::to_string(scene.getWidth()));
		node.addAtribute("height", std::to_string(scene.getHeight()));
		for (auto pos = scene.begin(); pos != scene.end(); ++pos)
		{
			node.addChild(LayerStreamer::toNode(*pos));
		}
		node.setClosing(true);
		return node;
	}


	void SceneStreamer::toXml(const Scene& scene, std::stringstream& xml)
	{
		xml << "<Scene ";
		xml << "width = \"" << scene.getWidth()<< "\" ";
		xml << "height = \"" << scene.getHeight()<< "\" ";
		xml << ">\n";
		for (auto pos = scene.begin(); pos != scene.end(); ++pos)
		{
			LayerStreamer::toXml(*pos, xml);
		}
		xml << "</Scene>";
	}
}