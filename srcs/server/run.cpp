#include "irc.hpp"

static void	Welcom(int port, const std::string& passWord)
{
	std::cout << "*******  WELCOM TO IRC SERVER ***********\n";
	std::cout << "Port = " << port << std::endl;
	std::cout << "Pass Word = " << passWord << std::endl;
}

void	Server::loop(Manager& manager) const
{
	manager.createClient(_fd);
}

void	Server::run()
{
	Manager	manager;
	
	Welcom(_port, _passWord);

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