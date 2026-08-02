#include "irc.hpp"

pollfd	Manager::clientCreate(int serverFd)
{
	int	fd = accept(serverFd, NULL, NULL);
	if (fd < 0)
		throw (Exception(WARNING, "client : failed to accecpt client"));

	std::cout << "new client connected\n";

	_clients[fd].setFd(fd);

	return (createPFD(fd));
}