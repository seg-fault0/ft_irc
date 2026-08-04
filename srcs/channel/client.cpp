#include "irc.hpp"

bool	Channel::isClient(const Client& client) const
{
	file client_fd = client.getFd();

	for (size_t i = 0; i < _clients.size(); i++)
	{
		if (_clients[i] == client_fd)
			return (true);
	}
	return (false);
}

bool	Channel::isClientInvited(const Client& client) const
{
	file client_fd = client.getFd();

	for (size_t i = 0; i < _clients.size(); i++)
	{
		if (_invitedClients[i] == client_fd)
			return (true);
	}
	return (false);
}

bool	Channel::clientAdd(const Client& client)
{
	file client_fd = client.getFd();

	if (_userLimit >= _clients.size())
		return (false);

	_clients.push_back(client_fd);
	return (true);
}

void	Channel::clientDel(const Client& client)
{
	if (!isClient(client))
		return ;
	
	file client_fd = client.getFd();

	for(size_t i = 0; i < _clients.size(); i++)
	{
		if (_clients[i] == client_fd)
			_clients.erase(_clients.begin() + i);
	}

	for(size_t i = 0; i < _admins.size(); i++)
	{
		if (_admins[i] == client_fd)
			_admins.erase(_admins.begin() + i);
	}
}
