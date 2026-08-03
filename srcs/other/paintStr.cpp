#include "irc.hpp"

std::string paintStr(const std::string& clr, const std::string& str)
{
	return (clr + str + color::reset);
}