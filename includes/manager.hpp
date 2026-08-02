#pragma once

# include "irc.hpp"

class Manager
{
	private:
		std::map<int, Client>	_clients;
	
	public:
		pollfd	clientCreate(int serverFd);
		bool	manage(int id);
};