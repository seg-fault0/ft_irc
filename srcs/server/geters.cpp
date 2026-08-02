#include "irc.hpp"

int			Server::getPort(void) const { return(_port);}

std::string	Server::getPassWord(void) const { return(_passWord);}

int			Server::getFd(void) const { return (_fd); }