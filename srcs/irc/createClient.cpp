#include "irc.hpp"

void Irc::createNewClient(void)
{
	int	fd = accept(server.getFd(), NULL, NULL);
	if (fd < 0)
		throw (Exception(WARNING, "client : failed to accecpt client"));

	std::cout << "new client connected\n";

	clients[fd].setFd(fd);
	pfds.push_back(createPFD(fd));
}