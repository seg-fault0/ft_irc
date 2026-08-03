#include "irc.hpp"

void	Server::loop()
{
	if (poll(_pfds.data(), _pfds.size(), -1) < 0)
		throw (Exception(WARNING, "server : poll failed"));
	
	for (size_t i = 0; i < _pfds.size(); i++)
	{
		if (_pfds[i].revents & POLLIN)
		{
			if (i == 0)
				createNewClient();
			else
				_clients[i].manager(*this);
		}
	}
}

void	Server::run()
{
	printServerInfo();

	while (true)
	{
		try
		{
			loop();
		}
		catch(const Exception& e)
		{
			if (e.getType() == ERROR)
				throw ;
			std::cerr << e << std::endl;
		}
	}
}