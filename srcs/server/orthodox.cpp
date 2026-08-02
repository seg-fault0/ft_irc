# include "irc.hpp"

Server::Server() 
{
	_port = 0;
}

Server::~Server()
{
	if (_fd >= 0)
		close(_fd);
}
