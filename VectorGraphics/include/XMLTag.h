#pragma once

#include <string>
#include <sstream>
#include <unordered_map>

#include "Parser.h"

class XMLTag
{
public:
	XMLTag(const std::string text);

	bool empty() const { return mIsEmpty; };
	bool isOpening() const { return mIsOpening; };
	bool isClosing() const{ return mIsClosing; };
	std::string getName() const { return mName; };
	std::unordered_map<std::string, std::string> getAttributes() const { return mAttributes; };

private:
	std::string mText;
	std::string mName;
	std::unordered_map<std::string, std::string> mAttributes;
	bool mIsEmpty;
	bool mIsOpening;
	bool mIsClosing;

	void parseAttributes(std::stringstream& ss);
	void parseFieldsFromText(std::string textStr);

};