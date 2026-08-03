#pragma once

# include "irc.hpp"

class Client
{
	private:
		int							_fd;
		std::vector<std::string>	_buffer;
		std::string					_nickName;
		std::string					_userName;
		std::string					_realName;
		bool						_isPassAccepted; 
		bool						_isRegistered;

	public:
	//orthodox
		Client();
		~Client();
	
	//methods
		void	readBuffer(void);
		void	signIn(Server& server);
		void	manager(Server& server);
	
	//geters
		int							getFd(void) const;
		std::vector<std::string>	getBuffer(void) const;
		std::string					getBuffer(int) const;
		std::string					getNickName(void) const;
		std::string					getUserName(void) const;
		std::string					getRealName(void) const;
		bool						isPassAccepted(void) const;
		bool						isRegistered(void) const;

	//seters
		void	setFd(int fd);
		void	setPass(bool state);
		void	setNickName(const std::string& nickName);
		void	setRealName(const std::string&);
		void	setUserName(const std::string&);
};