#include "irc.hpp"

pollfd	Manager::createClient(int serverFd)
{
	int	_fd = accept(serverFd, NULL, NULL);
	if (_fd < 0)
		throw (Exception(WARNING, "client : failed to accecpt client"));

	std::cout << "new client connected\n";
	return (createPFD(_fd));
}