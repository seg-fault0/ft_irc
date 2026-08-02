#include "irc.hpp"

void	Server::init(int ac, char** av)
{
	if (ac != 3)
		throw (Exception(ERROR, "usage : ./ircserver <port> <passWord>"));
	
	_port = ft_atoi(av[1]);
	_passWord = av[2];
}