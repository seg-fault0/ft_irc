#include "irc.hpp"

int ft_send(int fd, const std::string& msg)
{
	return (send(fd, msg.c_str(), msg.length(), 0));
}