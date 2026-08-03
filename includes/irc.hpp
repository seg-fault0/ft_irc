#pragma once

/******************************************/
/***********     LIBRARIES    *************/
/******************************************/

//std
# include <iostream>
# include <sstream>
# include <map>
# include <vector>
# include <sstream>

# include <sys/socket.h>
# include <netinet/in.h>
# include <unistd.h>
# include <poll.h>

//non std
# include "exception.hpp"
# include "server.hpp"
# include "client.hpp"

/******************************************/
/***********     NAME SPACES    ***********/
/******************************************/

namespace color
{
    const std::string reset  = "\033[0m";
    const std::string red    = "\033[31m";
    const std::string green  = "\033[32m";
    const std::string yellow = "\033[33m";
    const std::string blue   = "\033[34m";
    const std::string cyan   = "\033[36m";
}

/******************************************/
/***********     PROTOYPES    *************/
/******************************************/

int							ft_atoi(const std::string& str);
int							ft_send(int fd, const std::string& msg);
pollfd						createPFD(int fd);
std::vector<std::string>	ft_split(const std::string &str, char delimiter);
std::string					paintStr(const std::string& clr, const std::string& str);