#include "irc.hpp"

void	Server::run(Irc& irc)
{
	(void) irc;

	std::cout << "Port = " << _port << " | password = " << _passWord << "\n";
}