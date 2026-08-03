#include "irc.hpp"

void	Server::printServerInfo(void) const
{
	std::cout << "*******  WELCOM TO IRC SERVER ***********\n";
	std::cout << "Port = " << _port << std::endl;
	std::cout << "Pass Word = " << _passWord << std::endl;
}

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

void	Server::lunch()
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