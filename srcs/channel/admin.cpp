#include "irc.hpp"

bool	Channel::isAdmin(const Client& client) const
{
	if (!isClient(client))
		return (false);
	
	file client_fd = client.getFd();

	for (size_t i = 0; i < _admins.size(); i++)
	{
		if (_admins[i] == client_fd)
			return (true);
	}
	return (false);
}

void	Channel::adminAdd(const Client& client)
{
	if (isAdmin(client))
		return ;
	
	file client_fd = client.getFd();
	_admins.push_back(client_fd);
}
