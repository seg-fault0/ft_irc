#pragma once

# include "irc.hpp"

class Client;

# define RESPOND 1
# define REQUEST 2

class Server
{
	private:
		int						_port;
		std::string				_passWord;
		int						_fd;
		std::vector<Client>		_clients; 
		std::vector<pollfd>		_pfds;
		
		private:
		void	banner(void) const;
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
		void	log(int type, Client& client, const std::string& msg);

	//geters
		int			getPort(void) const ;
		int			getFd(void) const ;
		std::string	getPassWord(void) const ;
};