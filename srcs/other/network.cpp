#include "irc.hpp"

int ft_send(int fd, const std::string& msg)
{
	return (send(fd, msg.c_str(), msg.length(), 0));
}

pollfd createPFD(int fd)
{
	pollfd pfd;

	pfd.fd = fd;
	pfd.events = POLLIN;
	pfd.revents = 0;
	return (pfd);
}