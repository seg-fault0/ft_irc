#pragma once

# include "irc.hpp"

class Client;

class Server
{
	private:
		int						_port;
		std::string				_passWord;
		int						_fd;
		std::vector<Client>		_clients; 
		std::vector<pollfd>		_pfds;

	private:
		void	printServerInfo(void) const;
		void	loop();

	public:
	//orthodox
		Server();
		~Server();
	
	//methods
		void	init(int ac, char** av);
		void	lunch();
		void	createNewClient(void);
		bool	searchNickName(const std::string& nickName);
		void	deleteClient(Client& client);

	//geters
		int			getPort(void) const ;
		int			getFd(void) const ;
		std::string	getPassWord(void) const ;
};