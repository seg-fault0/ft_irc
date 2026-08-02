#pragma once

# include "irc.hpp"

class Manager
{
	private:
		std::map<int, Client>	_clients;
	
	public:
		pollfd	createClient(int serverFd);
		void	manage(int id);
};