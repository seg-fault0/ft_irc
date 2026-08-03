#include "irc.hpp"

/******************************************/
/***********      ORTHODOX    *************/
/******************************************/

Client::Client() : _fd(-1) {}

Client::~Client() 
{
	if (_fd >= 0)
		close(_fd);
}

/******************************************/
/***********       GETERS     *************/
/******************************************/

int	Client::getFd(void) const { return (_fd); }

std::string	Client::getNickName(void) const { return(_nickName); }

std::string	Client::getUserName(void) const { return(_userName); }

std::string	Client::getHostName(void) const { return(_hostName); }

std::string	Client::getRealName(void) const { return(_realName); }

bool		Client::isPassAccepted(void) const { return(_isPassAccepted); }

bool		Client::isRegistered(void) const { return(_isRegistered); }

std::string	Client::getBuffer(int i) { return (_buffer[i]); }

/******************************************/
/***********       SETERS     *************/
/******************************************/

void Client::setFd(int fd) { _fd = fd; }

void Client::setPass(bool state) { _isPassAccepted = state; }

void	Client::setNickName(const std::string& nickName) { _nickName = nickName; }