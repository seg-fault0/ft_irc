#pragma once

# include "irc.hpp"


/**************************************/
/************     MACROS    ***********/
/**************************************/

# define RESPOND 1
# define REQUEST 2
# define LOG 3

/**************************************/
/************     CLASS     ***********/
/**************************************/

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
		void	banner(void) const;
		void	loop();
		void	log(int type, Client& client, const std::string& msg);

	public:
	//orthodox
		Server();
		~Server();
	
	//server methods
		void	init(int ac, char** av);
		void	lunch();
		bool	searchNickName(const std::string& nickName);
		void	respond(Client& client, const std::string& msg);
		
	//client methods
		void	createNewClient(void);
		void	deleteClient(Client& client);
		void	manageClient(Client& client);

	//cmd methods
		void 	signIn(Client& client);
		void	cmdManager(Client& client);
		void	handleNickCmd(Client& client);
		void	handlePassCmd(Client& client);
		void	handleUserCmd(Client& client);

	//geters
		int			getPort(void) const ;
		int			getFd(void) const ;
		std::string	getPassWord(void) const ;
};