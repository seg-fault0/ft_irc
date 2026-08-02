#include "irc.hpp"

bool Irc::searchNickName(const std::string& nickName)
{
	for(size_t i = 1; i < pfds.size(); i++)
	{
		if (clients[pfds[i].fd].getNickName() == nickName)
			return (true);
	}
	return (false);
}