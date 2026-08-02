#pragma once

/******************************************/
/***********     LIBRARIES    *************/
/******************************************/

//std
# include <iostream>
# include <sstream>

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