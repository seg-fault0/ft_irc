#include "irc.hpp"

void	loop(Irc& irc)
{
	if (poll(irc.pfds.data(), irc.pfds.size(), -1) < 0)
		throw (Exception(WARNING, "server : poll failed"));
	
	int		isConnecting;
	pollfd	new_client;
	
	for (size_t i = 0; i < irc.pfds.size(); i++)
	{
		if (irc.pfds[i].revents & POLLIN)
		{
			if (i == 0)
				irc.createNewClient();
			else
				irc.manageClients(i);
		}
	}
}

void	Server::run(Irc& irc)
{
	printServerInfo();

	while (true)
	{
		try
		{
			loop(irc);
		}
		catch(const Exception& e)
		{
			if (e.getType() == ERROR)
				throw ;
			std::cerr << e << std::endl;
		}
	}
}