#pragma once

#include "Node.h"
#include "XMLTag.h"

#include<stack>
#include<memory>
#include <sstream>

class Streamer
{
public:	
	Streamer();

	static Node fromXml(std::stringstream& xml);

	static void toXml(const Node& node, std::stringstream& xml);

	static XMLTag getNextTag(std::stringstream& ss, char cOpen = '<', char cClose = '>');
	
	static Node getNext(std::stringstream& xml);

	static Node nodeFromTag(const XMLTag& tag);

	//virtual Node fromXml(const std::stringstream& xml);

	//virtual void toXml(const Node& node, std::stringstream& xml);

private:
};