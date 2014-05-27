#include "XMLTag.h"


XMLTag::XMLTag(const std::string text)
:mText(text), mIsClosing(false), mIsOpening(false), mIsEmpty(true)
{
	parseFieldsFromText(mText);
}

void XMLTag::parseFieldsFromText(std::string textStr)
{
	if (textStr[0] == '/') //we are assuming this is a closing only tag
	{
		mIsClosing = true;
		textStr = textStr.substr(1, mText.size() - 1);
		Parser::trim(textStr, WHITESPACE);
		mName = textStr;
		mIsEmpty = (mName.compare("") == 0) ? true : false;
		return;
	}
	if (textStr[textStr.size() - 1] == '/') //we are assuming this is a self closing tag
	{
		mIsClosing = true;
		mText = textStr.substr(0, mText.size() - 1);
	}
	//it must be an opening tag	
	mIsOpening = true;
	Parser::trim(textStr, WHITESPACE);
	std::stringstream ss;
	ss << mText;
	mName = Parser::stringUntil(ss, WHITESPACE);
	mIsEmpty = (mName.compare("") == 0) ? true : false;
	parseAttributes(ss);
}

void XMLTag::parseAttributes(std::stringstream& ss)
{
	Parser::eat(ss, WHITESPACE);
	while (ss.peek() != EOF)
	{
		std::string attributeNameStr = Parser::stringUntil(ss, '=');
		Parser::eat(ss, WHITESPACE+'='+'"');
		Parser::trim(attributeNameStr, WHITESPACE);

		std::string attributeValueStr = Parser::stringUntil(ss, '\"');
		Parser::eat(ss, WHITESPACE+'"');
		Parser::trim(attributeValueStr, WHITESPACE);
		mAttributes.insert(std::pair<std::string, std::string>(attributeNameStr, attributeValueStr));
	}
}
