#include "Parser.h"
#include<limits>

void Parser::trim(std::string& sourceString, std::string const& trimmables)
{
	size_t posStart = sourceString.find_first_not_of(trimmables);
	
	size_t posEnd = sourceString.find_last_not_of(trimmables);

	if (posEnd == std::string::npos && posEnd==std::string::npos) sourceString = ""; // all of the string matches trimmables
	else sourceString = sourceString.substr(posStart, posEnd - posStart + 1);

}
void Parser::eat(std::istream& sourceStream, std::string const& edibles)
{
	while (edibles.find(sourceStream.peek()) != std::string::npos) sourceStream.ignore();
}

void Parser::eat(std::istream& sourceStream, char edible)
{
	while (sourceStream.peek() != edible) sourceStream.ignore();
}

std::string Parser::stringUntil(std::istream& sourceStream, char cEnd)
{
	std::stringstream ss;
	while ((char)(sourceStream.peek()) != cEnd) ss << (char)(sourceStream.get());
	return ss.str();

}

std::string Parser::stringUntil(std::istream& sourceStream, const std::string& strEnd)
{	
	std::stringstream ss;
	while (strEnd.find(sourceStream.peek()) == std::string::npos) ss << (char)(sourceStream.get());
	return ss.str();
}