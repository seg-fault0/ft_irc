#pragma once

# include "irc.hpp"

class Client
{
	private:
		int	_fd;
	
	public:
	//orthodox
		Client();
		~Client();
		
	//geters
		int	getFd(void) const;
		
	//seters
		void	setFd(int fd);
};