#include "irc.hpp"

std::vector<std::string> ft_split(const std::string &str, char delimiter)
{
	std::vector<std::string>	result;
	std::string				word;

	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == delimiter)
		{
			if (!word.empty())
			{
				result.push_back(word);
				word.clear();
			}
		}
		else
			word += str[i];
	}
	if (!word.empty())
		result.push_back(word);

	return result;
}
