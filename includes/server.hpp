#pragma once

# include "irc.hpp"

class Irc;

class Server
{
	private:
		int						_port;
		std::string				_passWord;
		int						_fd;
	private:
		void	printServerInfo(void) const;

	public:
	//orthodox
		Server();
		~Server();
	
	//methods
		void	init(Irc& irc, int ac, char** av);
		void	run(Irc& irc);

	//geters
		int			getPort(void) const ;
		int			getFd(void) const ;
		std::string	getPassWord(void) const ;
};