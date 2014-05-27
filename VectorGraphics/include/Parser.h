#pragma once

#include <string>
#include <sstream>

const std::string WHITESPACE = " \t\r\n";
class Parser
{
public:
	Parser();

	static void trim(std::string& sourceString, const std::string& trimmables = "");

	static void eat(std::istream& sourceStream, const std::string& edibles="");

	static void Parser::eat(std::istream& sourceStream, char edible);

	static std::string Parser::stringUntil(std::istream& sourceStream, char cEnd);
	static std::string Parser::stringUntil(std::istream& sourceStream, const std::string& strEnd);

private:

};