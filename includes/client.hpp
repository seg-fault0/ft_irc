#pragma once

# include "irc.hpp"

class Client
{
	private:
		int			_fd;
		std::string	_buffer;
		std::string	_nickName;
		std::string	_userName;
		std::string	_hostName;
		std::string	_realName;
		bool		_isPassAccepted; 
		bool		_isRegistered;

	public:
	//orthodox
		Client();
		~Client();
	
	//methods
		void	readBuffer(void);
		void	signIn(Irc& irc);
	
	//geters
		int			getFd(void) const;
		std::string	getBuffer(void);
		std::string	getNickName(void) const;
		std::string	getUserName(void) const;
		std::string	getHostName(void) const;
		std::string	getRealName(void) const;
		bool		isPassAccepted(void) const;
		bool		isRegistered(void) const;

	//seters
		void	setFd(int fd);
		void	setPass(bool state);
};