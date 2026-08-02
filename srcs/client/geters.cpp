# include "irc.hpp"

int	Client::getFd(void) const { return (_fd); }

std::string	Client::getNickName(void) const { return(_nickName); }

std::string	Client::getUserName(void) const { return(_userName); }

std::string	Client::getHostName(void) const { return(_hostName); }

std::string	Client::getRealName(void) const { return(_realName); }

bool		Client::isPassAccepted(void) const { return(_isPassAccepted); }

bool		Client::isRegistered(void) const { return(_isRegistered); }

std::string	Client::getBuffer(void) { return (_buffer); }
