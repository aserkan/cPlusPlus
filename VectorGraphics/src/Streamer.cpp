#include "Streamer.h"
#include "Parser.h"

typedef std::shared_ptr<Node> nodePtr;
Node Streamer::fromXml(std::stringstream& xml)
{
	//return getNext(xml, "");
	return getNext(xml);
}

XMLTag Streamer::getNextTag(std::stringstream& ss, char cOpen, char cClose)
{
	Parser::eat(ss, WHITESPACE);
	if (ss.get() != cOpen) throw std::invalid_argument("invalid tag; expected "+ cOpen); //does not append cOpen
	std::string strTag = Parser::stringUntil(ss, cClose);
	Parser::trim(strTag, WHITESPACE);
	if (ss.get() != cClose) throw std::invalid_argument("invalid tag; expected " + cClose); //does not append cClose
	return XMLTag(strTag);
}

Node Streamer::getNext(std::stringstream& xml)
{
	XMLTag tag = Streamer::getNextTag(xml);
	if (tag.empty()) throw std::invalid_argument("invalid xml; empty tag");

	Node newNode = Node(tag);
	if (newNode.isClosing()) return newNode;
	else if (newNode.isOpening())
	{
		while (xml.peek() != EOF)
		{
			//Node temp = getNext(xml, newNode.getName());
			Node temp = getNext(xml);
			if (newNode.getName().compare(temp.getName()) == 0)
			{
				newNode.setClosing(true);//found the closing tag node for the node, set it to closing and return 
				return newNode;
			}
			else newNode.addChild(temp);
		}
	}
}


void Streamer::toXml(const Node& node, std::stringstream& xml)
{
	xml << "<" << node.getName();
	std::unordered_map<std::string, std::string> attributes = node.getAttributes();
	for each (auto var in attributes)
	{
		xml << " " << var.first << " = \"" << var.second << "\"";
	}
	std::vector<Node> children = node.getChildren();
	if (children.empty()) //no children, can close tag
	{
		xml << " />\n";
	}
	else //call toXml for all children and close tag after
	{
		xml << ">\n";
		for each (auto var in children)
		{
			toXml(var, xml);
		}
		xml << "</ " << node.getName() << ">\n";
	}
}
