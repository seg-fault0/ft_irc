#pragma once

# include "irc.hpp"

class Server
{
	private:
		int			_port;
		std::string	_passWord;
		int			_fd;
	
	public:
	//orthodox
		Server();
		~Server();
	
	//methods
		void	init(int ac, char** av);
		void	run(void);
	
	//geters
		int			getPort(void) const ;
		std::string	getPassWord(void) const ; 
};