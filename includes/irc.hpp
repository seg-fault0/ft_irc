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

/******************************************/
/***********       CLASS      *************/
/******************************************/

class Irc
{
	public:
		Server					server;
		std::map<int, Client>	clients; 
		std::vector<pollfd>		pfds;
	
	public:
		void createNewClient(void);
		void manageClients(int);
};

/******************************************/
/***********     PROTOYPES    *************/
/******************************************/

int		ft_atoi(const std::string& str);
pollfd	createPFD(int fd);