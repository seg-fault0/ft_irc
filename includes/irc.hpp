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

class Client;

class Irc
{
	public:
		Server					server;
		std::map<int, Client>	clients; 
		std::vector<pollfd>		pfds;
	
	public:
		void createNewClient(void);
		void deleteClient(int);
		void manageClients(int);
		bool searchNickName(const std::string& nickName);
};

/******************************************/
/***********     PROTOYPES    *************/
/******************************************/

int		ft_atoi(const std::string& str);
int		ft_send(int fd, const std::string& msg);
pollfd	createPFD(int fd);