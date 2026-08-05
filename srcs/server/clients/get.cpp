#include "irc.hpp"

std::string	Server::getClientNickNameFromFd(file fd)
{
	for (size_t i = 0; i < _clients.size(); i++)
	{
		if (fd = _clients[i].getFd())
			return (_clients[i].getNickName());
	}
	return (std::string());
}