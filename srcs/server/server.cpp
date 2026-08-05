#include "irc.hpp"

/******************************************/
/***********      ORTHODOX    *************/
/******************************************/

Server::Server()
{
	_port = 0;
	_fd = -1;
}

Server::~Server()
{
	if (_fd >= 0)
		close(_fd);
}

/******************************************/
/***********       GETERS     *************/
/******************************************/

int			Server::getPort(void) const { return(_port);}

std::string	Server::getPassWord(void) const { return(_passWord);}

int			Server::getFd(void) const { return (_fd); }

std::string	Server::getDate(void) const { return (_date); }