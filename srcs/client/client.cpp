#include "irc.hpp"

/******************************************/
/***********      ORTHODOX    *************/
/******************************************/

Client::Client() : _fd(-1), _nickName("*") {}

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

std::string	Client::getRealName(void) const { return(_realName); }

std::string					Client::getBuffer(void) const { return (_buffer); }

std::vector<std::string>	Client::getAllCmd(void) const{ return (_cmds); }

std::string					Client::getCmd(int i) const { return (_cmds[i]); }


bool		Client::isPassAccepted(void) const { return(_isPassAccepted); }

bool		Client::isRegistered(void) const { return(_isRegistered); }


/******************************************/
/***********       SETERS     *************/
/******************************************/

void	 Client::setFd(int fd) { _fd = fd; }

void 	Client::setPass(bool state) { _isPassAccepted = state; }

void	Client::setNickName(const std::string& nickName) { _nickName = nickName; }

void	Client::setUserName(const std::string& userName) { _userName = userName; }

void	Client::setRealName(const std::string& realName) {_realName = realName; }

void	Client::setRegistered(bool state) { _isRegistered = state; }