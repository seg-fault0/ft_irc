#pragma once

# include "irc.hpp"

class Client
{
	private:
		int							_fd;
		std::string					_buffer;
		std::vector<std::string>	_cmds;
		std::string					_nickName;
		std::string					_userName;
		std::string					_realName;
		bool						_isPassAccepted; 
		bool						_isRegistered;
		std::vector<std::string>	_channels;

	public:
	//orthodox
		Client();
		Client(int fd);
		~Client();
	
	//methods
		void	readBuffer(Server& server);
		bool	isChannelMember(const std::string& channel_name);
		void	channelAdd(const std::string& channel_name);
		void	channelDel(const std::string& channel_name);
		void	closeFd(void);

	//geters
		int							getFd(void) const;
		std::string					getBuffer(void) const;
		std::vector<std::string>	getAllCmd(void) const;
		std::vector<std::string>	getChannels(void) const ;
		std::string					getCmd(int) const ;
		std::string					getNickName(void) const;
		std::string					getUserName(void) const;
		std::string					getRealName(void) const;
		bool						isPassAccepted(void) const;
		bool						isRegistered(void) const;

	//seters
		void	setFd(int fd);
		void	setPass(bool state);
		void	setRegistered(bool state);
		void	setNickName(const std::string& nickName);
		void	setRealName(const std::string&);
		void	setUserName(const std::string&);
};