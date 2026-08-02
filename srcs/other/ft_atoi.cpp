#include "irc.hpp"

int	ft_atoi(const std::string& str)
{
	std::stringstream	ss(str);
	int ret = 0;

	ss >> ret;
	return (ret);
}
