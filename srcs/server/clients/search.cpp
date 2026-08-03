#include "irc.hpp"

bool Server::searchNickName(const std::string& nickName)
{
	for(size_t i = 1; i < _clients.size(); i++)
	{
		if (_clients[i].getNickName() == nickName)
			return (true);
	}
	return (false);
}