#include "irc.hpp"

std::string	Channel::getTopic(void) const { return (_topic); }

std::string	Channel::getPassWord(void) const { return (_passWord); }

std::string	Channel::getName(void) const { return (_name); }

std::vector<std::string>	Channel::getClients(void) const { return (_clients); }

std::string					Channel::getClientsStr(void) const
{
	std::string str;

	for (size_t i = 0; i < _clients.size(); i++)
	{
		str += _clients[i];
		if (i + 1 < _clients.size())
			str += " ";
	}
	return (str);
}