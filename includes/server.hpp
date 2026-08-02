#pragma once

# include "irc.hpp"

class Manager;

class Server
{
	private:
		int						_port;
		std::string				_passWord;
		int						_fd;
		std::vector<pollfd>		_pfds;
	
	private:
		void	printServerInfo(void) const;
		void	loop(Manager& manager);

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