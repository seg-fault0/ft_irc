#pragma once

/******************************************/
/***********     LIBRARIES    *************/
/******************************************/

//std
# include <iostream>
# include <sstream>
# include <map>
# include <vector>

# include <sys/socket.h>
# include <netinet/in.h>
# include <unistd.h>
# include <poll.h>

//non std
# include "exception.hpp"
# include "server.hpp"
# include "client.hpp"
# include "manager.hpp"

/******************************************/
/***********     PROTOYPES    *************/
/******************************************/

int		ft_atoi(const std::string& str);
pollfd	createPFD(int fd);