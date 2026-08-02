#include "irc.hpp"

void	Server::loop(Manager& manager) const
{
	manager.createClient(_fd);
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