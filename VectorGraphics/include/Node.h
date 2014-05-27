#pragma once

#include <string>
#include <map>
#include <unordered_map>
#include <sstream>

#include "XMLTag.h"

class Node
{
public:
	Node(std::string name, bool closing=false)
		: mName(name), mClosing(closing){};

	Node(const XMLTag& tag)
		: mName(tag.getName()), mAttributes(tag.getAttributes()),
		mClosing(tag.isClosing()), mOpening(tag.isOpening()), mIsEmpty(tag.empty()){};

	std::string getName() const{ return mName; };
	std::unordered_map<std::string, std::string> getAttributes() const { return mAttributes;};
	std::vector<Node> getChildren() const { return mChildren; };
	bool isClosing() const {return mClosing;};
	bool isOpening() const { return mOpening; };
	bool isEmpty() const { return mIsEmpty; };

	void setClosing(bool val) { mClosing = val; };
	void setOpening(bool val) { mOpening = val; };

	void setName(std::string name){ mName = name; };
	void addAtribute(std::string element, std::string value)
	{ 
		mAttributes.insert(std::pair<std::string, std::string>(element, value)); 
	};
	void addChild(Node node)
	{ 
		mChildren.push_back(node);
	};

	bool operator==(const Node& rhs) const
	{
		return (mName == rhs.mName && mAttributes == rhs.mAttributes && mChildren == rhs.mChildren);
	};
	bool operator!=(const Node& rhs) const
	{
		return !operator==(rhs);
	};

//	friend std::ostream& operator<<(std::ostream& os, const Node & point);

private:
	std::string mName;
	std::unordered_map<std::string, std::string>  mAttributes;
	std::vector<Node> mChildren;
	bool mClosing;
	bool mOpening;
	bool mIsEmpty;

};

//std::ostream& operator<<(std::ostream& os, const Node & point);



