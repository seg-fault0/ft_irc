#include "irc.hpp"

void	manageConnections(std::vector<pollfd>& pfds, size_t i)
{
	char buffer[1024];

	int bytes = recv(pfds[i].fd, buffer, sizeof(buffer) - 1, 0);

	if (bytes <= 0)
	{
		std::cout << "client disconnected\n";
		return;
	}
	buffer[bytes] = '\0';
	std::cout << "client" << i  << " : "<< buffer;
}

void	Server::loop(Manager& manager)
{
	if (poll(_pfds.data(), _pfds.size(), -1) < 0)
		throw (Exception(WARNING, "server : poll failed"));
	
	for (size_t i = 0; i < _pfds.size(); i++)
	{
		if (_pfds[i].revents & POLLIN)
		{
			if (i == 0)
				_pfds.push_back(manager.createClient(_fd));
			else
				manageConnections(_pfds, i);
		}
	}
}

void	Server::run()
{
	Manager	manager;
	
	printServerInfo();

	while (true)
	{
		try
		{
			loop(manager);
		}
		catch(const Exception& e)
		{
			if (e.getType() == ERROR)
				throw ;
			std::cerr << e << std::endl;
		}
	}
}