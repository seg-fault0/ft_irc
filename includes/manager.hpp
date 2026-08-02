#pragma once

# include "irc.hpp"

class Manager
{
	private:
		std::map<int, Client>	_clients;
	
	public:
		void	createClient(int serverFd);
};