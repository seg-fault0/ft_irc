#include "irc.hpp"

std::string	Channel::getTopic(void) const { return (_topic); }

std::string	Channel::getPassWord(void) const { return (_passWord); }

std::string	Channel::getName(void) const { return (_name); }

std::vector<file>	Channel::getClients(void) const { return (_clients); }