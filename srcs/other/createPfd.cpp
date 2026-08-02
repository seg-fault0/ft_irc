#include "irc.hpp"

pollfd createPFD(int fd)
{
	pollfd pfd;

	pfd.fd = fd;
	pfd.events = POLLIN;
	pfd.revents = 0;
	return (pfd);
}