#include "irc.hpp"

void	Server::loop(Manager& manager)
{
	if (poll(_pfds.data(), _pfds.size(), -1) < 0)
		throw (Exception(WARNING, "server : poll failed"));
	
	int		isConnecting;
	pollfd	new_client;
	
	for (size_t i = 0; i < _pfds.size(); i++)
	{
		if (_pfds[i].revents & POLLIN)
		{
			if (i == 0)
			{
				new_client = manager.clientCreate(_fd);
				_pfds.push_back(new_client);
			}
			else
			{
				isConnecting = manager.manage(_pfds[i].fd);
				if (isConnecting == false)
					_pfds.erase(_pfds.begin() + i);
			}
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