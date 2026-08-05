#pragma once

# include "irc.hpp"


/**************************************/
/************     MACROS    ***********/
/**************************************/

# define RESPOND 1
# define REQUEST 2

/**************************************/
/************     CLASS     ***********/
/**************************************/

class Client;
class Channel;

class Server
{
	private:
		std::string				_date;
		int						_port;
		std::string				_passWord;
		int						_fd;
		std::vector<Channel>	_channels;
		std::vector<Client>		_clients;
		std::vector<pollfd>		_pfds;
		
		private:
		void	banner(void) const;
		void	loop();
		void	log(int type, const Client& client, const std::string& msg);

	public:
	//orthodox
		Server();
		~Server();
	
	//server methods
		void	init(int ac, char** av);
		void	lunch();
		bool	searchNickName(const std::string& nickName);
		void	sendMsgToClient(const Client& client, const std::string& msg);
		
	//client methods
		void		createNewClient(void);
		void		deleteClient(Client& client);
		void		manageClient(Client& client);
		std::string	getClientNickNameFromFd(file fd);
		Client*		getClientByNickName(const std::string&);

	//channel methods
		bool		hasChannel(const std::string& channel_name);
		Channel*	getChannel(const std::string& channel_name);
		void		sendMsgToChannel(const std::string& channel_name, const std::string& msg);

	//cmd methods
		void 	signIn(Client& client);
		void	cmdManager(Client& client);
		void	handleNickCmd(Client& client);
		void	handlePassCmd(Client& client);
		void	handleUserCmd(Client& client);
		void	handleQuitCmd(Client& client);
		void	handleJoinCmd(Client& client);

	//geters
		int			getPort(void) const ;
		int			getFd(void) const ;
		std::string	getPassWord(void) const ;
		std::string	getDate(void) const ;
};