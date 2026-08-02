#pragma once

/******************************************/
/***********     LIBRARIES    *************/
/******************************************/

//std
# include <iostream>
# include <sstream>
# include <sys/socket.h>
# include <netinet/in.h>
# include <unistd.h>

//non std
# include "exception.hpp"
# include "server.hpp"

/******************************************/
/***********       CLASS      *************/
/******************************************/

class Irc
{
	public:
		Server	server;
};

int	ft_atoi(const std::string& str);