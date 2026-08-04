#include "irc.hpp"

void Server::banner(void) const
{
	std::cout << "\n";
	std::cout << paintStr(color::blue,"╔══════════════════════════════════════════════╗\n");
	std::cout << paintStr(color::blue,"║               FT_IRC SERVER                  ║\n");
	std::cout << paintStr(color::blue,"╠══════════════════════════════════════════════╣\n");
	std::cout << paintStr(color::blue,"║ Port     : ") << _port << "\n";
	std::cout << paintStr(color::blue,"║ Password : ") << _passWord << "\n";
	std::cout << paintStr(color::blue,"╚══════════════════════════════════════════════╝\n");
	std::cout << std::endl;
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
				manageClient(_clients[i]);
		}
	}
}

void	Server::lunch()
{
	banner();

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