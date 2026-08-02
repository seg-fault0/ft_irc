#include "irc.hpp"


void Client::setFd(int fd) { _fd = fd; }

void	Client::setNickName(const std::string& name)
{
	_nickName = name;
}

void	Client::setUserName(const std::string& name)
{
	_userName = name;
}

void	Client::setHostName(const std::string& name)
{
	_hostName = name;
}

void	Client::setRealName(const std::string& name)
{
	_realName = name;
}

void	Client::setConnected(bool state)
{
	_isConnected = state;
}

void	Client::setRegistered(bool state)
{
	_isRegistered = state;
}
